/* SONER GUNES 1901042623 */
#ifndef GTUVECTOR_CPP
#define GTUVECTOR_cPP
// implementation guards for templated classes and functions
#include "gtuvector.h" // including the header file of interest
#include <iostream> // cout cerr endl
#include <memory> // shared_ptr
using namespace std;
namespace IterableGTU { // adding templated member functions to namespace IterableGTU
    template <typename T> // templated function
    GTUVector<T>::GTUVector() : _capacity(1), _size(0) { // being initialized with capacity 1 and size 0 value
        decltype(_data) temp(new T[_capacity]); // creating a new memory location with the same type with _data
        _data = temp; // assigning data to temp
        // temp will be destroyed and _data keeps pointing to the memory location
    }
    template <typename T>
    GTUVector<T>::GTUVector(int capacity) : _size(0) { // getting a capacity value and initializing the size value
        if(capacity < 1) throw "Invalid capacity value"; // throws an exception for invalid values
        _capacity = capacity; // assigning capacity
        decltype(_data) temp(new T[_capacity]); // creating processes same with the no-parameter constructor
        _data = temp;  
    }
    template <typename T>
    GTUVector<T>::GTUVector(const GTUVector<T>& other) // copy constructor
        : _capacity(other._capacity), _size(other._size) { // initializing the capacity and size values
        decltype(_data) temp(new T[_capacity]); // constructing operations
        _data = temp;
        auto ptrData = _data.get(); // gets the value of addresses
        auto ptrOther = other._data.get();
        for(int i = 0; i < _size; ++i) // deep copy here
            ptrData[i] = ptrOther[i];
    }
    template <typename T>
    GTUVector<T>::GTUVector(GTUVector<T>&& other) noexcept // move constructor
        : _capacity(other._capacity), _size(other._size) { // initializing operations
        _data = other._data; // shallow copy is enough since we are stealing the data
        other._data = nullptr; // moving not copying
        cout << "move constructor is called" << endl; // for testing purposes
        // added flag -fno-elide-constructors to makefile for move operations
    }
    template <typename T>
    GTUVector<T>& GTUVector<T>::operator=(GTUVector<T>&& other) noexcept { // move assignment
        if (this == &other) return *this; // controls for same locations
        _capacity = other._capacity; // other stuff similar to move constructor
        _size = other.size();
        _data = other._data;
        other._data = nullptr;
        cout << "move assignment is called" << endl;
        return *this; // returns itself
    }
    template <typename T>
    GTUVector<T>& GTUVector<T>::operator=(const GTUVector<T>& other) { // assignment overloading
        if(this == &other) return *this;
        _capacity = other._capacity; // similar to copy constructor
        _size = other.size();
        decltype(_data) temp(new T[_capacity]);
        _data = temp;
        auto ptrData = _data.get();
        auto ptrOther = other._data.get();
        for(int i = 0; i < _size; ++i) // deep copy here
            ptrData[i] = ptrOther[i];
        return *this;
    }
    template <typename T>
    void GTUVector<T>::add(const T& element) { // adds an element dynamically
        if(_size >= _capacity) { // if capacity is full then allocate new memory locations
            auto buffer = _data; 
            _capacity *= 2; // capacity is multiplied by two
            decltype(_data) temp(new T[_capacity]);
            _data = temp; // new location
            auto ptrData = _data.get();
            auto ptrBuffer = buffer.get();
            for(int i = 0; i < _size; ++i) // deep copying
                ptrData[i] = ptrBuffer[i];  
        }
        auto ptrData = _data.get();
        ptrData[_size] = element; // adding the element
        ++_size; // incrementing size by one
    }
    template <typename T>
    T& GTUVector<T>::operator[](int index) { // indexing operations
        if(index >= _size || index < 0) throw "Invalid index value";
        auto ptrData = _data.get(); // getting address to reach the value by using index operator
        return ptrData[index];
    }
    template <typename T>
    const T& GTUVector<T>::operator[](int index) const { // constant one
        if(index >= _size || index < 0) throw "Invalid index value";
        auto ptrData = _data.get();
        return ptrData[index];
    }
    template <typename T> // erase the value pointed by the iterator
    void GTUVector<T>::erase(const typename Iterable<T>::GTUIterator& iterator) {
        decltype(_data) temp(new T[_capacity]); // getting new memory location
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