/* SONER GUNES 1901042623 */
#ifndef GTUVECTOR_H
#define GTUVECTOR_H
// header guards
#include "iterable.h" // including the base class
namespace IterableGTU { // adding classes to namespace IterableGTU
    template <typename T> // templated class
    class GTUVector : public Iterable<T> { // inherits from Iterable<T> abstract base class
    public:
        GTUVector(); // no parameter constructor
        explicit GTUVector(int capacity); // explicitly declared constructor that takes a capacity value
        GTUVector(const GTUVector<T>&); // copy constructor
        GTUVector(GTUVector<T>&& other) noexcept; // move constructor
        GTUVector<T>& operator=(GTUVector<T>&& other) noexcept;  // move assignment
        GTUVector<T>& operator=(const GTUVector<T>&); // assignment operator for deep copy
        // destructor is not needed since shared_ptr is used
        bool empty() const {return _size == 0;} // returns if the container is empty
        int size() const {return _size;} // returns size
        void erase(const typename Iterable<T>::GTUIterator& iterator); // deletes element pointed by the given iterator
        void clear() {_size = 0;} // deletes all content
        typename Iterable<T>::GTUIterator begin() // returns an iterator to the beginning of the container
        {return typename Iterable<T>::GTUIterator(&_data[0]);}
        typename Iterable<T>::GTUIterator end() // returns an iterator to the ending of the container
        {return typename Iterable<T>::GTUIterator(&_data[size()]);}
        typename Iterable<T>::GTUIteratorConst cbegin() // returns an constant iterator to the beginning of the container
        {return typename Iterable<T>::GTUIteratorConst(&_data[0]);}
        typename Iterable<T>::GTUIteratorConst cend() // returns an constant iterator to the ending of the container
        {return typename Iterable<T>::GTUIteratorConst(&_data[size()]);}
        void add(const T&); // adds an element to the end
        T& operator[](int index); // index operator
        const T& operator[](int index) const; // constant index operator
    private:
        shared_ptr<T[]> _data; // keeps data with shared_ptr stl smart pointers
        int _capacity; // capacity value
        int _size; // size value
    };
} // IterableGTU
#endif // GTUVECTOR_H