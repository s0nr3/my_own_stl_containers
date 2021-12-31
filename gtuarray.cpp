/* SONER GUNES 1901042623 */
#ifndef GTUARRAY_CPP
#define GTUARRAY_CPP
// implementation guards for templated classes and functions
#include "gtuarray.h" // including the header file of interest
namespace IterableGTU { // adding templated member functions to namespace IterableGTU
    template <typename T, size_t N> // templated function
    GTUArray<T, N>::GTUArray() : _size(N) { // initializing the size value
        decltype(_data) temp(new T[_size]); // creating a new memory location with the same type with _data
        _data = temp; // assigning data to temp
        // temp will be destroyed and _data keeps pointing to the memory location
    }
    template <typename T, size_t N>
    T& GTUArray<T, N>::operator[](int index) { // indexing operations
        if(index >= _size || index < 0) throw "Invalid index value";
        auto ptrData = _data.get(); // getting address to reach the value by using index operator
        return ptrData[index];
    }
    template <typename T, size_t N>
    const T& GTUArray<T, N>::operator[](int index) const { // constant one
        if(index >= _size || index < 0) throw "Invalid index value";
        auto ptrData = _data.get();
        return ptrData[index];
    }
    template <typename T, size_t N> // erase the value pointed by the iterator
    void GTUArray<T, N>::erase(const typename Iterable<T>::GTUIterator& iterator) {
        decltype(_data) temp(new T[_size]); // getting new memory location
        auto ptrTemp = temp.get();
        typename Iterable<T>::GTUIterator it = this->begin();
        int i = 0;
        for(; it != iterator; ++it, ++i) // copying the elements until the element that'll be erased
            ptrTemp[i] = *it;
        ++it; // passing the iterator next element
        for(; it != this->end(); ++it, ++i) // copying the elements remaining
            ptrTemp[i] = *it;
        _data = temp; // _data points new data         
        --_size; // decrementing the size value by one
    }
} // IterableGTU
#endif