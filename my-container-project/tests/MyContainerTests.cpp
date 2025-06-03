#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest (1).h"
#include "MyContainer.hpp"
#include <string>
using namespace ariel;

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

TEST_CASE("Add, Remove, Size, Output - string") {
    MyContainer<std::string> c;
    c.addElement("a");
    c.addElement("b");
    c.addElement("a");
    CHECK(c.size() == 3);
    c.remove("a");
    CHECK(c.size() == 1);
    CHECK_THROWS_AS(c.remove("a"), std::runtime_error);
    std::ostringstream oss;
    oss << c;
    CHECK(oss.str() == "b ");
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

TEST_CASE("MiddleOutOrder Iterator - large container") {
    MyContainer<int> container;
    for (int i = 1; i <= 100; ++i) {
        container.addElement(i);
    }
    std::vector<int> expectedOrder;
    size_t mid = 100 / 2;
    expectedOrder.push_back(mid + 1);
    for (int left = mid, right = mid + 2; left >= 1 || right <= 100; --left, ++right) {
        if (left >= 1) expectedOrder.push_back(left);
        if (right <= 100) expectedOrder.push_back(right);
    }

    size_t index = 0;
    auto middleOutIterator = MyContainer<int>::MiddleOutOrder(container);
    for (auto it = middleOutIterator.begin(); it != middleOutIterator.end(); ++it, ++index) {
        CHECK(*it == expectedOrder[index]);
    }
}
