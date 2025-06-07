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

## Recent Updates
- Added comprehensive unit tests for all iterators (`AscendingOrder`, `DescendingOrder`, `SideCrossOrder`, `ReverseOrder`, `Order`, `MiddleOutOrder`).
- Verified iterator functionality for edge cases and dynamic behavior.

## Testing
Unit tests for the `MyContainer` class and its iterators are located in `tests/MyContainerTests.cpp`. These tests ensure that:
- All iterators traverse the container correctly.
- Error handling is implemented for invalid operations.
- Dynamic addition and removal of elements work seamlessly with iterators.

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

### Alternative Testing Command
If you are in the parent directory of the project, you can run the following command to build and test:
```bash
cd my-container-project && make test
```

## Makefile Commands
The `Makefile` provides the following commands for building and testing the project:

- **`make test`**: Builds the project and runs all unit tests.
- **`make valgrind`**: Runs the unit tests with Valgrind to check for memory leaks.
- **`make clean`**: Cleans up all build artifacts and binaries.

### Example Usage
To build and run the tests:
```bash
make test
```

To check for memory leaks:
```bash
make valgrind
```

To clean the project:
```bash
make clean
```

## License
This project is licensed under the MIT License. See the LICENSE file for more details.