# Array-Based List Implementation in C++

This repository contains an implementation of a generic, array-based list (or dynamic array) in C++. The list supports basic operations such as insertion, removal, search, and retrieval of items. It is designed to be efficient and simple, with operations to maintain a list's size and elements within a statically allocated array.

## Table of Contents

- [Features](#features)
- [Class Interface](#class-interface)
  - [Constructors and Destructor](#constructors-and-destructor)
  - [Methods](#methods)
- [Usage Example](#usage-example)
- [Error Handling](#error-handling)

## Features

- **Generic Type:** The list is templated, so it can store elements of any type (e.g., integers, strings, custom objects).
- **Dynamic Size:** The list grows and shrinks based on user input.
- **Search Operations:** Efficient sequential search to locate items in the list.
- **Insertion/Removal:** Insert items at specified locations or at the end. Remove items by location or value.
- **Print/List Display:** Print all elements of the list in order.

## Class Interface

### Constructors and Destructor

#### `arrayBasedList(int size = 100)`
The constructor initializes the list with a specified size. If the provided size is invalid (zero or negative), it will throw an error.

#### `~arrayBasedList()`
The destructor deallocates the memory used by the list.

#### `arrayBasedList(const arrayBasedList<elemType>& otherList)`
The copy constructor creates a deep copy of another `arrayBasedList`.

### Methods

#### `bool isEmpty() const`
Checks if the list is empty.

#### `bool isFull() const`
Checks if the list is full (reached its maximum size).

#### `int listSize() const`
Returns the current number of items in the list.

#### `int maxListSize() const`
Returns the maximum size of the list.

#### `bool isItemEqual(int loc, const elemType& item) const`
Checks if the item at the specified location is equal to the given item.

#### `int seqSearch(const elemType& item) const`
Searches for the item in the list using a sequential search and returns the index of the first occurrence, or -1 if not found.

#### `void insertAt(int loc, const elemType& item)`
Inserts an item at the specified location in the list.

#### `void insertEnd(const elemType& item)`
Inserts an item at the end of the list.

#### `void removeAt(int loc)`
Removes the item at the specified location.

#### `void retrieveAt(int loc)`
Retrieves the item at the specified location.

#### `void replaceAt(int loc, const elemType& item)`
Replaces the item at the specified location with a new item.

#### `void clearList()`
Clears the entire list (removes all items).

#### `void insert(const elemType& item)`
Inserts an item at the end of the list if it does not already exist.

#### `void remove(const elemType& item)`
Removes the first occurrence of the item in the list.

#### `void print() const`
Prints all elements of the list.

## Usage Example

```cpp
#include "arrayBasedList.h"

int main() {
    arrayBasedList<int> list(10);

    list.insertEnd(5);
    list.insertEnd(10);
    list.insertEnd(15);

    list.print(); // Output: 5 10 15

    list.remove(10);
    list.print(); // Output: 5 15

    int item = list.seqSearch(15);
    cout << "Found item at index: " << item << endl; // Output: Found item at index: 1

    return 0;
} 
