/**
 * @file main.cpp
 * @brief Demonstrates the usage of the MyContainer class.
 *
 * This program creates a MyContainer object, adds elements to it, and demonstrates
 * various iteration orders such as ascending, descending, and others.
 */

#include <iostream>
#include "MyContainer.hpp"

using namespace my_container_project;

/**
 * @brief Main function demonstrating the usage of MyContainer.
 *
 * Adds elements, iterates in different orders, and removes an element.
 *
 * @return int Returns 0 upon successful execution.
 */
int main() {
    // Create a MyContainer object
    MyContainer<int> container;

    // Add elements to the container
    container.addElement(7);
    container.addElement(15);
    container.addElement(6);
    container.addElement(1);
    container.addElement(2);

    // Print the size of the container
    std::cout << "Size of container: " << container.size() << std::endl;

    // Demonstrate ascending order iteration
    std::cout << "Ascending Order: ";
    MyContainer<int>::AscendingOrder asc(container);
    for (auto it = asc.begin(); it != asc.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    // Demonstrate descending order iteration
    std::cout << "Descending Order: ";
    MyContainer<int>::DescendingOrder desc(container);
    for (auto it = desc.begin(); it != desc.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    // Demonstrate side-cross order iteration
    std::cout << "Side Cross Order: ";
    MyContainer<int>::SideCrossOrder sideCross(container);
    for (auto it = sideCross.begin(); it != sideCross.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    // Demonstrate reverse order iteration
    std::cout << "Reverse Order: ";
    MyContainer<int>::ReverseOrder reverse(container);
    for (auto it = reverse.begin(); it != reverse.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    // Demonstrate original order iteration
    std::cout << "Original Order: ";
    MyContainer<int>::Order order(container);
    for (auto it = order.begin(); it != order.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    // Demonstrate middle-out order iteration
    std::cout << "Middle Out Order: ";
    MyContainer<int>::MiddleOutOrder middleOut(container);
    for (auto it = middleOut.begin(); it != middleOut.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    // Remove an element and demonstrate the updated container
    container.remove(6);
    std::cout << "After removing 6, size of container: " << container.size() << std::endl;

    std::cout << "Updated Ascending Order: ";
    MyContainer<int>::AscendingOrder updatedAsc(container);
    for (auto it = updatedAsc.begin(); it != updatedAsc.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    return 0;
}
