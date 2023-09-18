# Unordered Set
This is a C++ implementation of an unordered set data structure using hash tables. It provides a basic set of operations to insert, remove, find, and manipulate elements in the set. The implementation includes dynamic resizing to maintain a constant load factor and efficient hashing to ensure fast access times.
# Table of Contents
- [Getting Started](#Getting Started)
- [Usage](#Usage)
- [API Reference](#API Reference)
- [Examples](#Examples)
# Getting Started
To use this unordered set implementation, you can follow these steps:
- Clone the repository to your local machine.
- Compile the code using a C++ compiler.
- Run the test program.
The test program demonstrates how to use the unordered set with various operations.
# Usage
You can include the unordered_set.h header file in your C++ project to use the unordered_set class.
# API Reference
The unordered_set class provides the following public methods:
- unordered_set(): Default constructor.
- explicit unordered_set(int init_size): Constructor with an initial size.
- unordered_set(const unordered_set& other): Copy constructor.
- unordered_set& operator=(const unordered_set& other): Copy assignment operator.
- unordered_set(unordered_set&& other): Move constructor.
- unordered_set& operator=(unordered_set&& other): Move assignment operator.
- ~unordered_set(): Destructor.
For a complete list of methods and their descriptions, please refer to the unordered_set.h header file.
# Examples
You can find usage examples in the test_unordered_set function in the test.cpp file. This function demonstrates various operations on the unordered set.
