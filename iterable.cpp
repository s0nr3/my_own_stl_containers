/* SONER GUNES 1901042623 */
#ifndef ITERABLE_CPP
#define ITERABLE_CPP
// implementing guards because of the templated stuff
#include "iterable.h" // including related header file
namespace IterableGTU { // adding to namespace IterableGTU
    template <typename T>
    typename Iterable<T>::GTUIterator& Iterable<T>::GTUIterator::operator++() {
        ++_ptr; // pre-fix incrementing
        return *this;
    }
    template <typename T>
    typename Iterable<T>::GTUIterator Iterable<T>::GTUIterator::operator++(int) {
        GTUIterator temp = *this;
        ++(*this); // post-fix incrementing
        return temp;
    }
    template <typename T>
    typename Iterable<T>::GTUIterator& Iterable<T>::GTUIterator::operator--() {
        --_ptr; // pre-fix decrementing
        return *this;
    }
    template <typename T>
    typename Iterable<T>::GTUIterator Iterable<T>::GTUIterator::operator--(int) {
        GTUIterator temp = *this;
        --(*this); // post-fix decrementing
        return temp;
    }
}
#endif // ITERABLE_CPP












