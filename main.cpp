/* SONER GUNES 1901042623 */
#include <iostream>
#include <algorithm>
#include <string>
#include "iterable.h"
#include "iterable.cpp"
#include "gtuset.h"
#include "gtuset.cpp"
#include "gtuvector.h"
#include "gtuvector.cpp"
#include "gtuarray.h"
#include "gtuarray.cpp"
// including all libraries necessary
using namespace std;
using namespace IterableGTU;

void func(int i) { // test function for for_each algorithm
    cout << i << ' ';
}
void wait() { // to run program more readable
    cout << "PRESS ENTER" << endl;
    cin.get();
}

int main() { // testing classes functions
    GTUVector<int> myVector; // declaring a GTUVector object
    GTUVector<int>::GTUIterator it; // and its potential iterator
    for(int i = 0; i < 10; ++i)
        myVector.add(i * 2); // adding numbers

    wait();

    cout << "myVector contains after adding numbers 0 2 4 6 ... 18: ";
    it = myVector.begin(); // initializing iterator
    for(; it != myVector.end(); ++it)
        cout << *it << ' '; // displays all content
    cout << endl;

    wait();

    cout << "myVector contains after adding numbers 0 2 4 6 ... 18 by printing with for_each stl algorithm: ";
    for_each(myVector.begin(), myVector.end(), func); // for_each std algorithm
    cout << endl;

    wait();

    iter_swap(myVector.begin(), myVector.end() - 1); // iter_swap std algorithm
    cout << "myVector contains after swapping the first and last numbers by using iter_swap stl algorithm: ";
    for(const auto& i : myVector) // range-based for loop
        cout << i << ' ';
    cout << endl;

    wait();

    it = find(myVector.begin(), myVector.end(), 10); // find std algorithm
    if(it != myVector.end())
        cout << *it << " is found in myVector with find stl algorithm" << endl;
    else
        cout << "Element is not found in myVector" << endl;

    wait();

    it = find(myVector.begin(), myVector.end(), 11);
    if(it != myVector.end())
        cout << *it << " is found in myVector" << endl;
    else
        cout << "Element(11) is not found in myVector" << endl;

    wait();

    random_shuffle(myVector.begin(), myVector.end()); // random_shuffle std algorithm
    cout << "myVector contains after shuffling by using random_shuffle stl algorithm: ";
    for_each(myVector.begin(), myVector.end(), func);
    cout << endl;

    wait();

    sort(myVector.begin(), myVector.end()); // sort std algorithm
    cout << "myVector contains after being sorted by using sort stl algorithm: ";
    for_each(myVector.begin(), myVector.end(), func);
    cout << endl;

    wait();

    fill(myVector.begin(), myVector.end(), 99); // fill std algorithm
    cout << "myVector contains after filling all values with 99 by using fill stl algorithm: ";
    for_each(myVector.begin(), myVector.end(), func);
    cout << endl;

    wait(); 

    GTUVector<char> myCharVector(3); // constructor that takes capacity value
    myCharVector.add('a');
    myCharVector.add('s');
    myCharVector.add('d');
    cout << "myCharVector contains after adding a, s, d: ";
    for(auto i : myCharVector)
        cout << i << ' ';
    cout << endl;

    wait();

    GTUVector<char> myCharVector2(myCharVector); // copy constructor
    cout << "myCharVector2 contains after creating with copy constructor whose parameter is previous myCharVector: ";
    for(auto i : myCharVector2)
        cout << i << ' ';
    cout << endl;
    
    wait();

    GTUVector<char> myCharVector3;
    myCharVector3 = move(myCharVector2); // move assignment
    cout << "myCharVector3 contains after being assigned to myCharVector2 with move function by using move assignment: ";
    for(auto i : myCharVector3)
        cout << i << ' ';
    cout << endl;
    
    wait();

    GTUSet<int> mySet; // no-parameter constructor
    mySet.add(7);
    mySet.add(4);
    cout << "mySet contains after adding 7 and 4: ";
    for(const auto& i : mySet) // range-based for loop
        cout << i << ' ';
    cout << endl;

    wait();

    GTUSet<int> mySet2;
    mySet2.add(7);
    mySet2.add(7);
    mySet2.add(1);
    mySet2.add(3); // adding elements to set

    cout << "mySet2 contains after adding 7, 7, 1 and 3: ";
    for(const auto& i : mySet2) // range-based for loop
        cout << i << ' ';
    cout << endl;
    cout << "remember no duplicates are allowed in GTUSet" << endl;
    
    wait();

    GTUSet<int> mySet3 = mySet.intersectSet(mySet2); // move constructor (r-value)
    cout << "mySet3 contains after being constructed with move constructor by taking the intersect of mySet and mySet2: ";
    for(const auto& i : mySet3)
        cout << i << ' ';
    cout << endl;

    wait();

    mySet3 = mySet.unionSet(mySet2); // taking union of sets and assign the result by using move assignment
    cout << "mySet3 contains after being assigned with move assignment by taking the union of mySet and mySet2: ";
    for(const auto& i : mySet3)
        cout << i << ' ';
    cout << endl;

    wait();

    mySet2 = mySet3; // deep copy assignment
    cout << "mySet2 contains after being assigned to mySet3: ";
    for(const auto& i : mySet2)
        cout << i << ' ';
    cout << endl;

    wait();

    GTUSet<int> mySet4(move(mySet3)); // move constructor and std::move function to make value r-value
    cout << "mySet4 contains after being initialized to mySet3 with move function and move constructor: ";
    for(const auto& i : mySet4)
        cout << i << ' ';
    cout << endl;

    wait();

    GTUSet<int> mySet5(mySet4); // copy constructor
    cout << "mySet5 contains after being initialized to mySet4 with copy constructor: ";
    for(const auto& i : mySet5)
        cout << i << ' ';
    cout << endl;

    wait();

    mySet5.erase(mySet5.begin() + 1); // erase the element pointed by the given iterator
    cout << "mySet5 contains after its second element being erased with erase function: ";
    for(const auto& i : mySet5)
        cout << i << ' ';
    cout << endl;

    wait();

    // trying and catching exceptions
    cout << "trying negative capacity value for vector" << endl;
    try {
        GTUVector<int> myVector(-5);
    }
    catch (const char* message) {
        cerr << message << endl;
    }
    
    wait();

    cout << "trying negative capacity value for set" << endl;
    try {
        GTUSet<int> mySet(-1);
    }
    catch (const char* message) {
        cerr << message << endl;
    }
    
    wait();

    cout << "trying negative index value for array" << endl;
    try {
        GTUArray<bool, 5> myArray;
        myArray[-7];
    }
    catch (const char* message) {
        cerr << message << endl;
    }

    wait();

    cout << "trying out of range index value for array" << endl;
    try {
        GTUArray<bool, 5> myArray;
        myArray[5];
    }
    catch (const char* message) {
        cerr << message << endl;
    }

    wait();
    
    GTUArray<int, 10> myArray; // declaring fixed size array
    for(int i = 0; i < 10; ++i)
        myArray[i] = i;

    cout << "myArray contains after being added 0 1 2 3 ... 9: ";
    for(const auto& i : myArray) // range-based for loop
        cout << i << ' ';
    cout << endl;

    wait();

    cout << "trying to enter out of range index value" << endl;
    try {
        cout << myArray[10] << endl;
    }
    catch (const char* message) {
        cerr << message << endl;
    }

    wait();

    cout << "trying to enter negative index value" << endl;
    try {
        cout << myArray[-1] << endl;
    }
    catch (const char* message) {
        cerr << message << endl;
    } 

    wait();

    cout << "trying to enter out of range index value" << endl;
    try {
        cout << myArray[1000] << endl;
    }
    catch (const char* message) {
        cerr << message << endl;
    }

    wait();

    cout << "myVector contains: ";
    for(const auto& i : myVector)
        cout << i << ' ';
    cout << endl;

    wait();

    cout << "mySet contains: ";
    for(const auto& i : mySet)
        cout << i << ' ';
    cout << endl;

    wait();

    cout << "myArray contains: ";
    for(const auto& i : myArray)
        cout << i << ' ';
    cout << endl;

    wait();

    Iterable<int>* myIterables[3];
    myIterables[0] = &myVector;
    myIterables[1] = &mySet;
    myIterables[2] = &myArray;

    // polymorphic calls to test pure virtual function erase
    for(int i = 0; i < 5; ++i)
        myIterables[0]->erase(myIterables[0]->begin());
    
    myIterables[1]->erase(myIterables[1]->end() - 1);

    myIterables[2]->erase(myIterables[2]->begin() + 5);

    cout << "After some erasing process with polymorphic calls" << endl;

    wait();

    cout << "myVector contains: ";
    for(const auto& i : myVector)
        cout << i << ' ';
    cout << endl;

    wait();

    cout << "mySet contains: ";
    for(const auto& i : mySet)
        cout << i << ' ';
    cout << endl;

    wait();

    cout << "myArray contains: ";
    for(const auto& i : myArray)
        cout << i << ' ';
    cout << endl;

    wait();

    GTUSet<string> myStringSet;
    myStringSet.add("soner");
    myStringSet.add("gunes");
    myStringSet.add("abc");

    cout << "myStringSet contains: ";
    for(const auto& i : myStringSet)
        cout << i << ' ';
    cout << endl;

    wait();

    myStringSet.remove(); // deletes last element

    cout << "myStringSet contains after deleting last element: ";
    for(const auto& i : myStringSet)
        cout << i << ' ';
    cout << endl;

    wait();

    cout << "searching myStringSet..." << endl;
    if(myStringSet.search("soner"))
        cout << "soner found" << endl;
    else
        cout << "soner not found" << endl;
    if(myStringSet.search("gunes"))
        cout << "gunes found" << endl;
    else
        cout << "gunes not found" << endl;

    wait();

    GTUArray<double, 5> myDoubleArray;
    GTUArray<double, 5>::GTUIterator itArray;
    GTUArray<double, 5>::GTUIteratorConst citArray; // constant iterator using
    int i = 0;
    for(itArray = myDoubleArray.begin(); itArray != myDoubleArray.end(); ++itArray, ++i)
        *itArray = i * 3;
    cout << "myDoubleArray contains (using constant iterators): ";    
    for(citArray = myDoubleArray.cbegin(); citArray != myDoubleArray.cend(); ++citArray)
        cout << *citArray << ' ';
    cout << endl;

    wait();

    if(myDoubleArray.empty()) cout << "myDoubleArray empty" << endl;
    else  cout << "myDoubleArray not empty" << endl;
    
    wait();
    
    myDoubleArray.clear();
    cout << "After clearing myDoubleArray..." << endl;
    if(myDoubleArray.empty()) cout << "myDoubleArray empty" << endl;
    else  cout << "myDoubleArray not empty" << endl;

    wait();

    cout << "That's all, functions and classes have been tested!" << endl;

    return 0;
}