/* SONER GUNES 1901042623 */
#ifndef GTUSET_CPP
#define GTUSET_CPP
 // implementation guards for templated classes and functions
#include "gtuset.h" // including the related header file
#include <iostream> // cout cerr endl
#include <memory> // shared_ptr
using namespace std;
namespace IterableGTU { // adding templated member functions to namespace IterableGTU
    template <typename T> // templated function
    GTUSet<T>::GTUSet() : _capacity(1), _size(0) { // being initialized with capacity 1 and size 0 value
        decltype(_data) temp(new T[_capacity]); // creating a new memory location with the same type with _data
        _data = temp; // assigning data to temp
        // temp will be destroyed and _data keeps pointing to the memory location
    }
    template <typename T>
    GTUSet<T>::GTUSet(int capacity) : _size(0) { // getting a capacity value and initializing the size value
        if(capacity < 1) throw "Invalid capacity value"; // throws an exception for invalid values
        _capacity = capacity; // assigning capacity
        decltype(_data) temp(new T[_capacity]); // creating processes same with the no-parameter constructor
        _data = temp;  
    }
    template <typename T>
    GTUSet<T>::GTUSet(const GTUSet<T>& other) // copy constructor
        : _capacity(other._capacity), _size(other._size) { // initializing the capacity and size values
        decltype(_data) temp(new T[_capacity]); // constructing operations
        _data = temp;
        auto ptrData = _data.get(); // gets the value of addresses
        auto ptrOther = other._data.get();
        for(int i = 0; i < _size; ++i) // deep copy here
            ptrData[i] = ptrOther[i];
    }
    template <typename T>
    GTUSet<T>::GTUSet(GTUSet<T>&& other) noexcept // move constructor
        : _capacity(other._capacity), _size(other._size) { // initializing operations
        _data = other._data; // shallow copy is enough since we are stealing the data
        other._data = nullptr; // moving not copying
        cout << "move constructor is called" << endl; // for testing purposes
        // added flag -fno-elide-constructors to makefile for move operations
    }
    template <typename T>
    GTUSet<T>& GTUSet<T>::operator=(GTUSet<T>&& other) noexcept { // move assignment
        if (this == &other) return *this; // controls for same locations
        _capacity = other._capacity; // other stuff similar to move constructor
        _size = other.size();
        _data = other._data;
        other._data = nullptr;
        cout << "move assignment is called" << endl;
        return *this; // returns itself
    }
    template <typename T>
    GTUSet<T>& GTUSet<T>::operator=(const GTUSet<T>& other) { // assignment overloading
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
    T& GTUSet<T>::operator[](int index) { // indexing operations
        if(index >= _size || index < 0) throw "Invalid index value";
        auto ptrData = _data.get(); // getting address to reach the value by using index operator
        return ptrData[index];
    }
    template <typename T>
    const T& GTUSet<T>::operator[](int index) const { // constant one
        if(index >= _size || index < 0) throw "Invalid index value";
        auto ptrData = _data.get();
        return ptrData[index];
    }
    template <typename T>
    void GTUSet<T>::add(const T& element) { // adds an element dynamically
        if(!exist(element)) { // if the given element does not exist then operations will be done
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
            sort(this->begin(), this->end()); // and sorting to make set ordered
        }
    }
    template <typename T> // erase the value pointed by the iterator
    void GTUSet<T>::erase(const typename Iterable<T>::GTUIterator& iterator) {
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
    template <typename T> // searches the given element
    bool GTUSet<T>::search(const T& element) const {
        return exist(element); // by using the already existing helper function
    }
    template <typename T>
    void GTUSet<T>::remove() {
        --_size; // removes the last element
    }
    template <typename T> // returns the intersection of sets
    GTUSet<T> GTUSet<T>::intersectSet(const GTUSet<T>& set) {
        GTUSet<T> is;
        for(int i = 0; i < size(); ++i)
            if(set.exist(this->operator[](i))) // checking for same values
                is.add(this->operator[](i)); // if same then add the element
        return is;
    }
    template <typename T> // returns the union of sets
    GTUSet<T> GTUSet<T>::unionSet(const GTUSet<T>& set) {
        GTUSet<T> u;
        for(int i = 0; i < size(); ++i)
            u.add(this->operator[](i)); // adds all element
        for(int i = 0; i < size(); ++i)
            u.add(set[i]); // adds all element but add function does not allow same values
        return u;

    }
    template <typename T> // checks if the given element already exists in set
    bool GTUSet<T>::exist(const T& element) const {
        bool existent = false;
        auto ptrData = _data.get();
        for(int i = 0; i < this->size(); ++i) 
            if(ptrData[i] == element) // checking equality
                existent = true;
        return existent;
    }
} // IterableGTU
#endif