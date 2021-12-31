/* SONER GUNES 1901042623 */
#ifndef GTUARRAY_H
#define GTUARRAY_H
// header guards
#include "iterable.h" // including the base class
namespace IterableGTU { // adding classes to namespace IterableGTU
    template <typename T, size_t N> // templated class and fixed size array
    class GTUArray : public Iterable<T> { // inherits from Iterable<T> abstract base class
    public:
        GTUArray(); // no parameter constructor
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
        T& operator[](int index); // index operator
        const T& operator[](int index) const; // constant index operator
    private:
        shared_ptr<T[]> _data; // keeps data with shared_ptr stl smart pointers
        int _size; // size value
    };
} // IterableGTU
#endif // GTUARRAY_H