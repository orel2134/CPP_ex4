# MyContainer Project

## Overview
The MyContainer project implements a dynamic container class that can hold comparable objects such as integers, doubles, and strings. The container supports various operations including adding and removing elements, checking the size, and iterating through the elements in different orders.

## Features
- **Dynamic Element Management**: Add and remove elements dynamically.
- **Size Management**: Check the current number of elements in the container.
- **Custom Iterators**: Multiple iterators to traverse the container in different orders:
  - Ascending Order
  - Descending Order
  - Side Cross Order
  - Reverse Order
  - Original Order
  - Middle Out Order

## Classes
### MyContainer
- **add(const T& element)**: Adds a new element to the container.
- **remove(const T& element)**: Removes all occurrences of the specified element from the container. Throws an error if the element does not exist.
- **size()**: Returns the number of elements currently in the container.
- **operator<<**: Outputs the contents of the container in a readable format.

## Iterators
Each iterator class provides methods to traverse the MyContainer:
- **AscendingOrder**: Iterates from the smallest to the largest element.
- **DescendingOrder**: Iterates from the largest to the smallest element.
- **SideCrossOrder**: Alternates between the smallest and largest elements.
- **ReverseOrder**: Iterates through the container in reverse.
- **Order**: Iterates through the container in the order elements were added.
- **MiddleOutOrder**: Starts from the middle element and alternates left and right.

## Testing
Unit tests for the MyContainer class are located in `tests/MyContainerTests.cpp`. These tests ensure that all functionalities work as expected and that error handling is correctly implemented.

## Build Instructions
To build the project, use CMake. Navigate to the project directory and run the following commands:
```bash
mkdir build
cd build
cmake ..
make
```

## Running Tests
After building the project, you can run the tests using the following command:
```bash
./MyContainerTests
```

## License
This project is licensed under the MIT License. See the LICENSE file for more details.