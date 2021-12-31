/* SONER GUNES 1901042623 */
#ifndef ITERABLE_H
#define ITERABLE_H
// header guards
#include <memory> // shared_ptr
#include <iterator> // iterator tags
#include <cstddef> // ptrdiff_t
using namespace std;
namespace IterableGTU { // namespace that contains all iterables
    template <typename T> // templated class
    class Iterable { // abstract base class
    public:
        class GTUIterator { // inner class for random access iterator
        public:
            // defining some configurations 
            typedef random_access_iterator_tag iterator_category;
            typedef ptrdiff_t difference_type;
            typedef T value_type;
            typedef value_type* pointer;
            typedef value_type& reference;
            GTUIterator() {} // no-parameter constructor
            GTUIterator(pointer ptr) : _ptr(ptr) {} // takes a pointer
            reference operator*() const {return *_ptr;} // returns the value
            pointer operator->() const {return _ptr;} // returns the pointer
            GTUIterator& operator++(); // incrementing operators
            GTUIterator operator++(int);
            GTUIterator& operator--(); // decrementing operators
            GTUIterator operator--(int);
            difference_type operator-(const GTUIterator& it) const {return this->_ptr - it._ptr;} // difference
            GTUIterator operator+(const difference_type& df) const {return GTUIterator(_ptr + df);} // addition
            GTUIterator operator-(const difference_type& df) const {return GTUIterator(_ptr - df);} // substraction
            GTUIterator& operator+=(const difference_type& df) { // addition and assignment
                this->_ptr += df;
                return *this;
            }
            GTUIterator& operator-=(const difference_type& df) { // substraction and assignment
                this->_ptr -= df;
                return *this;
            }
            reference operator[](int index) { // index operator
                if(index < 0) throw "Invalid index value";
                return _ptr[index];
            }
            const reference operator[](int index) const { // constant index operator
                if(index < 0) throw "Invalid index value";
                return _ptr[index];
            }
            friend bool operator==(const GTUIterator& it1, const GTUIterator& it2) {
                return it1._ptr == it2._ptr;
            }
            friend bool operator!=(const GTUIterator& it1, const GTUIterator& it2) {
                return !(it1 == it2);
            }
            // comparison operators based on pointers
            bool operator<(const GTUIterator& it) const {return this->_ptr < it._ptr;}
            bool operator>(const GTUIterator& it) const {return this->_ptr > it._ptr;}
            bool operator>=(const GTUIterator& it) const {return !(this->_ptr < it._ptr);}
            bool operator<=(const GTUIterator& it) const {return !(this->_ptr > it._ptr);}
        protected:
            pointer _ptr;
        };
        // iterator hierarchy: GTUIteratorConst is a GTUIterator
        class GTUIteratorConst : public GTUIterator { // constant random access iterator 
        public: // inherits from non-constant one 
            GTUIteratorConst() {} // no-parameter constructor
            GTUIteratorConst(T* ptr) : GTUIterator(ptr) {} // takes a pointer
            const T& operator*() const {return *GTUIterator::_ptr;} // returns value
            const T* operator->() const {return GTUIterator::_ptr;} // returns pointer
        };
        // pure virtual functions
        virtual bool empty() const = 0; // tests if container is empty
        virtual int size() const = 0; // returns container size 
        virtual void erase(const typename Iterable<T>::GTUIterator& iterator) = 0; // deletes element pointed by the given iterator
        virtual void clear() = 0; // deletes all content
        virtual GTUIterator begin() = 0; // returns a iterator to beginning
        virtual GTUIterator end() = 0; // returns a iterator to end
        virtual GTUIteratorConst cbegin() = 0; // returns a constant iterator to beginning
        virtual GTUIteratorConst cend() = 0; // returns a constant iterator to end
    private:
        shared_ptr<T[]> _data; // keeping data using dynamic memory techniques with shared_ptr STL pointers
        int _capacity; // keeps capacity
        int _size; // keeps size
    }; // Iterable
} // IterableGTU
#endif // ITERABLE_H