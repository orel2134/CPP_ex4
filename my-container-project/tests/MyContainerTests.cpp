#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest (1).h"
#include "MyContainer.hpp"
#include <string>
using namespace my_container_project;

TEST_CASE("Add, Remove, Size, Output - int") {
    MyContainer<int> c;
    CHECK(c.size() == 0);
    c.addElement(5);
    c.addElement(10);
    c.addElement(5);
    CHECK(c.size() == 3);
    c.remove(5);
    CHECK(c.size() == 1);
    CHECK_THROWS_AS(c.remove(5), std::runtime_error);
    std::ostringstream oss;
    oss << c;
    CHECK(oss.str() == "10 ");
}

TEST_CASE("Add, Remove, Size, Output - char") {
    MyContainer<char> container;
    CHECK(container.size() == 0);
    container.addElement('x');
    container.addElement('y');
    container.addElement('z');
    CHECK(container.size() == 3);
    container.remove('y');
    CHECK(container.size() == 2);
    CHECK_THROWS_AS(container.remove('y'), std::runtime_error);
    std::ostringstream oss;
    oss << container;
    CHECK(oss.str() == "x z ");
}

TEST_CASE("Add, Remove, Size, Output - string") {
    MyContainer<std::string> container;
    CHECK(container.size() == 0);
    container.addElement("hello");
    container.addElement("world");
    container.addElement("hello");
    CHECK(container.size() == 3);
    container.remove("hello");
    CHECK(container.size() == 1);
    CHECK_THROWS_AS(container.remove("hello"), std::runtime_error);
    std::ostringstream oss;
    oss << container;
    CHECK(oss.str() == "world ");
}

TEST_CASE("Add, Remove, Size, Output - double") {
    MyContainer<double> c;
    c.addElement(1.1);
    c.addElement(2.2);
    c.addElement(1.1);
    CHECK(c.size() == 3);
    c.remove(1.1);
    CHECK(c.size() == 1);
    CHECK_THROWS_AS(c.remove(1.1), std::runtime_error);
    std::ostringstream oss;
    oss << c;
    CHECK(oss.str() == "2.2 ");
}

TEST_CASE("Add and Size - simple test") {
    MyContainer<int> c;
    CHECK(c.size() == 0);
    c.addElement(10);
    CHECK(c.size() == 1);
    c.addElement(20);
    CHECK(c.size() == 2);
}

TEST_CASE("Remove - simple test") {
    MyContainer<int> c;
    c.addElement(10);
    c.addElement(20);
    CHECK(c.size() == 2);
    c.remove(10);
    CHECK(c.size() == 1);
    CHECK_THROWS_AS(c.remove(10), std::runtime_error);
}

TEST_CASE("Output - simple test") {
    MyContainer<int> c;
    c.addElement(5);
    c.addElement(15);
    std::ostringstream oss;
    oss << c;
    CHECK(oss.str() == "5 15 ");
}

TEST_CASE("Empty container - simple test") {
    MyContainer<int> c;
    CHECK(c.size() == 0);
    CHECK_THROWS_AS(c.remove(1), std::runtime_error);
    std::ostringstream oss;
    oss << c;
    CHECK(oss.str() == "");
}

TEST_CASE("AscendingOrder Iterator - int") {
    MyContainer<int> c;
    c.addElement(7); c.addElement(15); c.addElement(6); c.addElement(1); c.addElement(2);
    std::vector<int> expected = {1,2,6,7,15};
    size_t i = 0;
    auto it = MyContainer<int>::AscendingOrder(c);
    for (auto iter = it.begin(); iter != it.end(); ++iter, ++i) CHECK(*iter == expected[i]);
}

TEST_CASE("DescendingOrder Iterator - int") {
    MyContainer<int> c;
    c.addElement(7); c.addElement(15); c.addElement(6); c.addElement(1); c.addElement(2);
    std::vector<int> expected = {15,7,6,2,1};
    size_t i = 0;
    auto it = MyContainer<int>::DescendingOrder(c);
    for (auto iter = it.begin(); iter != it.end(); ++iter, ++i) CHECK(*iter == expected[i]);
}

TEST_CASE("SideCrossOrder Iterator - int") {
    MyContainer<int> c;
    c.addElement(7); c.addElement(15); c.addElement(6); c.addElement(1); c.addElement(2);
    std::vector<int> expected = {1,15,2,7,6};
    size_t i = 0;
    auto it = MyContainer<int>::SideCrossOrder(c);
    for (auto iter = it.begin(); iter != it.end(); ++iter, ++i) CHECK(*iter == expected[i]);
}

TEST_CASE("ReverseOrder Iterator - int") {
    MyContainer<int> c;
    c.addElement(7); c.addElement(15); c.addElement(6); c.addElement(1); c.addElement(2);
    std::vector<int> expected = {2,1,6,15,7};
    size_t i = 0;
    auto it = MyContainer<int>::ReverseOrder(c);
    for (auto iter = it.begin(); iter != it.end(); ++iter, ++i) CHECK(*iter == expected[i]);
}

TEST_CASE("Order Iterator - int") {
    MyContainer<int> c;
    c.addElement(7); c.addElement(15); c.addElement(6); c.addElement(1); c.addElement(2);
    std::vector<int> expected = {7,15,6,1,2};
    size_t i = 0;
    auto it = MyContainer<int>::Order(c);
    for (auto iter = it.begin(); iter != it.end(); ++iter, ++i) CHECK(*iter == expected[i]);
}

TEST_CASE("AscendingOrder - simple test") {
    MyContainer<int> c;
    c.addElement(3);
    c.addElement(1);
    c.addElement(2);
    std::vector<int> expected = {1, 2, 3};
    size_t i = 0;
    auto it = MyContainer<int>::AscendingOrder(c);
    for (auto iter = it.begin(); iter != it.end(); ++iter, ++i) {
        CHECK(*iter == expected[i]);
    }
}

TEST_CASE("DescendingOrder - simple test") {
    MyContainer<int> c;
    c.addElement(3);
    c.addElement(1);
    c.addElement(2);
    std::vector<int> expected = {3, 2, 1};
    size_t i = 0;
    auto it = MyContainer<int>::DescendingOrder(c);
    for (auto iter = it.begin(); iter != it.end(); ++iter, ++i) {
        CHECK(*iter == expected[i]);
    }
}

TEST_CASE("SideCrossOrder - simple test") {
    MyContainer<int> c;
    c.addElement(3);
    c.addElement(1);
    c.addElement(2);
    std::vector<int> expected = {1, 3, 2};
    size_t i = 0;
    auto it = MyContainer<int>::SideCrossOrder(c);
    for (auto iter = it.begin(); iter != it.end(); ++iter, ++i) {
        CHECK(*iter == expected[i]);
    }
}

TEST_CASE("ReverseOrder - simple test") {
    MyContainer<int> c;
    c.addElement(3);
    c.addElement(1);
    c.addElement(2);
    std::vector<int> expected = {2, 1, 3};
    size_t i = 0;
    auto it = MyContainer<int>::ReverseOrder(c);
    for (auto iter = it.begin(); iter != it.end(); ++iter, ++i) {
        CHECK(*iter == expected[i]);
    }
}

TEST_CASE("Order - simple test") {
    MyContainer<int> c;
    c.addElement(3);
    c.addElement(1);
    c.addElement(2);
    std::vector<int> expected = {3, 1, 2};
    size_t i = 0;
    auto it = MyContainer<int>::Order(c);
    for (auto iter = it.begin(); iter != it.end(); ++iter, ++i) {
        CHECK(*iter == expected[i]);
    }
}

TEST_CASE("MiddleOutOrder Iterator - empty container") {
    MyContainer<int> container;
    std::vector<int> expectedOrder = {};

    size_t index = 0;
    auto middleOutIterator = MyContainer<int>::MiddleOutOrder(container);
    for (auto it = middleOutIterator.begin(); it != middleOutIterator.end(); ++it, ++index) {
        CHECK(*it == expectedOrder[index]);
    }
}

TEST_CASE("MiddleOutOrder Iterator - single element") {
    MyContainer<int> container;
    container.addElement(42);
    std::vector<int> expectedOrder = {42};

    size_t index = 0;
    auto middleOutIterator = MyContainer<int>::MiddleOutOrder(container);
    for (auto it = middleOutIterator.begin(); it != middleOutIterator.end(); ++it, ++index) {
        CHECK(*it == expectedOrder[index]);
    }
}

TEST_CASE("MiddleOutOrder Iterator - int odd with 3 elements") {
    MyContainer<int> container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    std::vector<int> expectedOrder = {2, 1, 3};

    size_t index = 0;
    auto middleOutIterator = MyContainer<int>::MiddleOutOrder(container);
    for (auto it = middleOutIterator.begin(); it != middleOutIterator.end(); ++it, ++index) {
        CHECK(*it == expectedOrder[index]);
    }
}

TEST_CASE("MiddleOutOrder Iterator - int with repeated elements") {
    MyContainer<int> container;
    container.addElement(1);
    container.addElement(1);
    container.addElement(1);
    container.addElement(1);
    container.addElement(1);
    std::vector<int> expectedOrder = {1, 1, 1, 1, 1};

    size_t index = 0;
    auto middleOutIterator = MyContainer<int>::MiddleOutOrder(container);
    for (auto it = middleOutIterator.begin(); it != middleOutIterator.end(); ++it, ++index) {
        CHECK(*it == expectedOrder[index]);
    }
}

// MiddleOutOrder Iterator Tests

//////////////////////////////////////////////////

TEST_CASE("MiddleOutOrder Iterator - 9 elements") {
    MyContainer<int> container;
    container.addElement(10);
    container.addElement(20);
    container.addElement(30);
    container.addElement(40);
    container.addElement(50);
    container.addElement(60);
    container.addElement(70);
    container.addElement(80);
    container.addElement(90);

    std::vector<int> expectedOrder = {50, 40, 60, 30, 70, 20, 80, 10, 90};

    size_t index = 0;
    auto middleOutIterator = MyContainer<int>::MiddleOutOrder(container);
    for (auto it = middleOutIterator.begin(); it != middleOutIterator.end(); ++it, ++index) {
        CHECK(*it == expectedOrder[index]);
    }
}

TEST_CASE("MiddleOutOrder Iterator - 5 elements") {
    MyContainer<int> container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);

    std::vector<int> expectedOrder = {3, 2, 4, 1, 5};

    size_t index = 0;
    auto middleOutIterator = MyContainer<int>::MiddleOutOrder(container);
    for (auto it = middleOutIterator.begin(); it != middleOutIterator.end(); ++it, ++index) {
        CHECK(*it == expectedOrder[index]);
    }
}

TEST_CASE("MiddleOutOrder Iterator - 7 elements") {
    MyContainer<int> container;
    container.addElement(10);
    container.addElement(20);
    container.addElement(30);
    container.addElement(40);
    container.addElement(50);
    container.addElement(60);
    container.addElement(70);

    std::vector<int> expectedOrder = {40, 30, 50, 20, 60, 10, 70};

    size_t index = 0;
    auto middleOutIterator = MyContainer<int>::MiddleOutOrder(container);
    for (auto it = middleOutIterator.begin(); it != middleOutIterator.end(); ++it, ++index) {
        CHECK(*it == expectedOrder[index]);
    }
}

TEST_CASE("MiddleOutOrder Iterator - 11 elements") {
    MyContainer<int> container;
    container.addElement(10);
    container.addElement(20);
    container.addElement(30);
    container.addElement(40);
    container.addElement(50);
    container.addElement(60);
    container.addElement(70);
    container.addElement(80);
    container.addElement(90);
    container.addElement(100);
    container.addElement(110);

    std::vector<int> expectedOrder = {60, 50, 70, 40, 80, 30, 90, 20, 100, 10, 110};

    size_t index = 0;
    auto middleOutIterator = MyContainer<int>::MiddleOutOrder(container);
    for (auto it = middleOutIterator.begin(); it != middleOutIterator.end(); ++it, ++index) {
        CHECK(*it == expectedOrder[index]);
    }
}



TEST_CASE("MiddleOutOrder Iterator - 6 elements") {
    MyContainer<int> container;
    container.addElement(10);
    container.addElement(20);
    container.addElement(30);
    container.addElement(40);
    container.addElement(50);
    container.addElement(60);

    std::vector<int> expectedOrder = {30, 20, 40, 10, 50, 60};

    size_t index = 0;
    auto middleOutIterator = MyContainer<int>::MiddleOutOrder(container);
    for (auto it = middleOutIterator.begin(); it != middleOutIterator.end(); ++it, ++index) {
        CHECK(*it == expectedOrder[index]);
    }
}




TEST_CASE("MiddleOutOrder Iterator - 8 elements") {
    MyContainer<int> container;
    container.addElement(10);
    container.addElement(20);
    container.addElement(30);
    container.addElement(40);
    container.addElement(50);
    container.addElement(60);
    container.addElement(70);
    container.addElement(80);

    std::vector<int> expectedOrder = {40, 30, 50, 20, 60, 10, 70, 80};

    size_t index = 0;
    auto middleOutIterator = MyContainer<int>::MiddleOutOrder(container);
    for (auto it = middleOutIterator.begin(); it != middleOutIterator.end(); ++it, ++index) {
        CHECK(*it == expectedOrder[index]);
    }
}
TEST_CASE("MiddleOutOrder Iterator - 4 elements") {
    MyContainer<int> container;
    container.addElement(10);
    container.addElement(20);
    container.addElement(30);
    container.addElement(40);

    std::vector<int> expectedOrder = {20, 10, 30, 40};

    size_t index = 0;
    auto middleOutIterator = MyContainer<int>::MiddleOutOrder(container);
    for (auto it = middleOutIterator.begin(); it != middleOutIterator.end(); ++it, ++index) {
        CHECK(*it == expectedOrder[index]);
    }
}

TEST_CASE("MiddleOutOrder Iterator - 10 elements") {
    MyContainer<int> container;
    container.addElement(10);
    container.addElement(20);
    container.addElement(30);
    container.addElement(40);
    container.addElement(50);
    container.addElement(60);
    container.addElement(70);
    container.addElement(80);
    container.addElement(90);
    container.addElement(100);

    std::vector<int> expectedOrder = {50, 40, 60, 30, 70, 20, 80, 10, 90, 100};

    size_t index = 0;
    auto middleOutIterator = MyContainer<int>::MiddleOutOrder(container);
    for (auto it = middleOutIterator.begin(); it != middleOutIterator.end(); ++it, ++index) {
        CHECK(*it == expectedOrder[index]);
    }
}

TEST_CASE("MiddleOutOrder Iterator - 2 elements") {
    MyContainer<int> container;
    container.addElement(10);
    container.addElement(20);

    std::vector<int> expectedOrder = {10, 20};

    size_t index = 0;
    auto middleOutIterator = MyContainer<int>::MiddleOutOrder(container);
    for (auto it = middleOutIterator.begin(); it != middleOutIterator.end(); ++it, ++index) {
        CHECK(*it == expectedOrder[index]);
    }
}

TEST_CASE("MiddleOutOrder Iterator - 12 elements") {
    MyContainer<int> container;
    container.addElement(10);
    container.addElement(20);
    container.addElement(30);
    container.addElement(40);
    container.addElement(50);
    container.addElement(60);
    container.addElement(70);
    container.addElement(80);
    container.addElement(90);
    container.addElement(100);
    container.addElement(110);
    container.addElement(120);

    std::vector<int> expectedOrder = {60, 50, 70, 40, 80, 30, 90, 20, 100, 10, 110, 120};

    size_t index = 0;
    auto middleOutIterator = MyContainer<int>::MiddleOutOrder(container);
    for (auto it = middleOutIterator.begin(); it != middleOutIterator.end(); ++it, ++index) {
        CHECK(*it == expectedOrder[index]);
    }
}

TEST_CASE("MiddleOutOrder Iterator - 3 elements") {
    MyContainer<int> container;
    container.addElement(10);
    container.addElement(20);
    container.addElement(30);

    std::vector<int> expectedOrder = {20, 10, 30};

    size_t index = 0;
    auto middleOutIterator = MyContainer<int>::MiddleOutOrder(container);
    for (auto it = middleOutIterator.begin(); it != middleOutIterator.end(); ++it, ++index) {
        CHECK(*it == expectedOrder[index]);
    }
}

TEST_CASE("MiddleOutOrder Iterator - 1 element") {
    MyContainer<int> container;
    container.addElement(10);

    std::vector<int> expectedOrder = {10};

    size_t index = 0;
    auto middleOutIterator = MyContainer<int>::MiddleOutOrder(container);
    for (auto it = middleOutIterator.begin(); it != middleOutIterator.end(); ++it, ++index) {
        CHECK(*it == expectedOrder[index]);
    }
}
// Added 5 new test cases for various functions
TEST_CASE("Add and Size - multiple elements") {
    MyContainer<int> container;
    container.addElement(10);
    container.addElement(20);
    container.addElement(30);
    container.addElement(40);
    CHECK(container.size() == 4);
}

TEST_CASE("Remove - element not found") {
    MyContainer<int> container;
    container.addElement(10);
    container.addElement(20);
    CHECK_THROWS_AS(container.remove(30), std::runtime_error);
}

TEST_CASE("Output - multiple elements") {
    MyContainer<int> container;
    container.addElement(10);
    container.addElement(20);
    container.addElement(30);
    std::ostringstream oss;
    oss << container;
    CHECK(oss.str() == "10 20 30 ");
}

TEST_CASE("AscendingOrder - empty container") {
    MyContainer<int> container;
    auto it = MyContainer<int>::AscendingOrder(container);
    CHECK(it.begin() == it.end());
}

TEST_CASE("DescendingOrder - single element") {
    MyContainer<int> container;
    container.addElement(42);
    auto it = MyContainer<int>::DescendingOrder(container);
    CHECK(*it.begin() == 42);
    CHECK(++it.begin() == it.end());
}

TEST_CASE("AscendingOrder Iterator") {
    MyContainer<int> c;
    c.addElement(3);
    c.addElement(1);
    c.addElement(2);

    MyContainer<int>::AscendingOrder asc(c);
    auto it = asc.begin();

    CHECK(*it == 1);
    ++it;
    CHECK(*it == 2);
    ++it;
    CHECK(*it == 3);
    ++it;
    CHECK(it == asc.end());
}

TEST_CASE("DescendingOrder Iterator") {
    MyContainer<int> c;
    c.addElement(3);
    c.addElement(1);
    c.addElement(2);

    MyContainer<int>::DescendingOrder desc(c);
    auto it = desc.begin();

    CHECK(*it == 3);
    ++it;
    CHECK(*it == 2);
    ++it;
    CHECK(*it == 1);
    ++it;
    CHECK(it == desc.end());
}

TEST_CASE("SideCrossOrder Iterator") {
    MyContainer<int> c;
    c.addElement(1);
    c.addElement(2);
    c.addElement(3);
    c.addElement(4);

    MyContainer<int>::SideCrossOrder sideCross(c);
    auto it = sideCross.begin();

    CHECK(*it == 1);
    ++it;
    CHECK(*it == 4);
    ++it;
    CHECK(*it == 2);
    ++it;
    CHECK(*it == 3);
    ++it;
    CHECK(it == sideCross.end());
}

TEST_CASE("ReverseOrder Iterator") {
    MyContainer<int> c;
    c.addElement(1);
    c.addElement(2);
    c.addElement(3);

    MyContainer<int>::ReverseOrder reverse(c);
    auto it = reverse.begin();

    CHECK(*it == 3);
    ++it;
    CHECK(*it == 2);
    ++it;
    CHECK(*it == 1);
    ++it;
    CHECK(it == reverse.end());
}

TEST_CASE("Order Iterator") {
    MyContainer<int> c;
    c.addElement(1);
    c.addElement(2);
    c.addElement(3);

    MyContainer<int>::Order order(c);
    auto it = order.begin();

    CHECK(*it == 1);
    ++it;
    CHECK(*it == 2);
    ++it;
    CHECK(*it == 3);
    ++it;
    CHECK(it == order.end());
}

TEST_CASE("MiddleOutOrder Iterator") {
    MyContainer<int> c;
    c.addElement(1);
    c.addElement(2);
    c.addElement(3);
    c.addElement(4);
    c.addElement(5);

    MyContainer<int>::MiddleOutOrder middleOut(c);
    auto it = middleOut.begin();

    CHECK(*it == 3);
    ++it;
    CHECK(*it == 2);
    ++it;
    CHECK(*it == 4);
    ++it;
    CHECK(*it == 1);
    ++it;
    CHECK(*it == 5);
    ++it;
    CHECK(it == middleOut.end());
}

TEST_CASE("MiddleOutOrder Iterator - string") {
    MyContainer<std::string> container;
    container.addElement("apple");
    container.addElement("banana");
    container.addElement("cherry");
    container.addElement("date");
    container.addElement("elderberry");

    std::vector<std::string> expectedOrder = {"cherry", "banana", "date", "apple", "elderberry"};

    size_t index = 0;
    auto middleOutIterator = MyContainer<std::string>::MiddleOutOrder(container);
    for (auto it = middleOutIterator.begin(); it != middleOutIterator.end(); ++it, ++index) {
        CHECK(*it == expectedOrder[index]);
    }
}

TEST_CASE("MiddleOutOrder Iterator - double") {
    MyContainer<double> container;
    container.addElement(1.1);
    container.addElement(2.2);
    container.addElement(3.3);
    container.addElement(4.4);
    container.addElement(5.5);

    std::vector<double> expectedOrder = {3.3, 2.2, 4.4, 1.1, 5.5};

    size_t index = 0;
    auto middleOutIterator = MyContainer<double>::MiddleOutOrder(container);
    for (auto it = middleOutIterator.begin(); it != middleOutIterator.end(); ++it, ++index) {
        CHECK(*it == expectedOrder[index]);
    }
}

TEST_CASE("MiddleOutOrder Iterator - char") {
    MyContainer<char> container;
    container.addElement('a');
    container.addElement('b');
    container.addElement('c');
    container.addElement('d');
    container.addElement('e');

    std::vector<char> expectedOrder = {'c', 'b', 'd', 'a', 'e'};

    size_t index = 0;
    auto middleOutIterator = MyContainer<char>::MiddleOutOrder(container);
    for (auto it = middleOutIterator.begin(); it != middleOutIterator.end(); ++it, ++index) {
        CHECK(*it == expectedOrder[index]);
    }
}

TEST_CASE("MiddleOutOrder Iterator - empty string container") {
    MyContainer<std::string> container;
    std::vector<std::string> expectedOrder = {};

    size_t index = 0;
    auto middleOutIterator = MyContainer<std::string>::MiddleOutOrder(container);
    for (auto it = middleOutIterator.begin(); it != middleOutIterator.end(); ++it, ++index) {
        CHECK(*it == expectedOrder[index]);
    }
}

TEST_CASE("MiddleOutOrder Iterator - single double element") {
    MyContainer<double> container;
    container.addElement(42.42);
    std::vector<double> expectedOrder = {42.42};

    size_t index = 0;
    auto middleOutIterator = MyContainer<double>::MiddleOutOrder(container);
    for (auto it = middleOutIterator.begin(); it != middleOutIterator.end(); ++it, ++index) {
        CHECK(*it == expectedOrder[index]);
    }
}

TEST_CASE("MiddleOutOrder Iterator - repeated char elements") {
    MyContainer<char> container;
    container.addElement('x');
    container.addElement('x');
    container.addElement('x');
    container.addElement('x');
    container.addElement('x');
    std::vector<char> expectedOrder = {'x', 'x', 'x', 'x', 'x'};

    size_t index = 0;
    auto middleOutIterator = MyContainer<char>::MiddleOutOrder(container);
    for (auto it = middleOutIterator.begin(); it != middleOutIterator.end(); ++it, ++index) {
        CHECK(*it == expectedOrder[index]);
    }
}



TEST_CASE("MiddleOutOrder Iterator - mixed string container") {
    MyContainer<std::string> container;
    container.addElement("apple");
    container.addElement("banana");
    container.addElement("cherry");
    container.addElement("date");
    container.addElement("elderberry");
    container.addElement("fig");
    container.addElement("grape");

    std::vector<std::string> expectedOrder = {"date", "cherry", "elderberry", "banana", "fig", "apple", "grape"};

    size_t index = 0;
    auto middleOutIterator = MyContainer<std::string>::MiddleOutOrder(container);
    for (auto it = middleOutIterator.begin(); it != middleOutIterator.end(); ++it, ++index) {
        CHECK(*it == expectedOrder[index]);
    }
}