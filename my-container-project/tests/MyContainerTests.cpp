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

TEST_CASE("MiddleOutOrder Iterator - int odd") {
    MyContainer<int> c;
    c.addElement(7); c.addElement(15); c.addElement(6); c.addElement(1); c.addElement(2);
    std::vector<int> expected = {6,15,1,7,2};
    size_t i = 0;
    auto it = MyContainer<int>::MiddleOutOrder(c);
    for (auto iter = it.begin(); iter != it.end(); ++iter, ++i) CHECK(*iter == expected[i]);
}

TEST_CASE("MiddleOutOrder Iterator - int even") {
    MyContainer<int> c;
    c.addElement(8); c.addElement(3); c.addElement(10); c.addElement(2); c.addElement(6); c.addElement(4);
    std::vector<int> expected = {2,10,6,3,4,8};
    size_t i = 0;
    auto it = MyContainer<int>::MiddleOutOrder(c);
    for (auto iter = it.begin(); iter != it.end(); ++iter, ++i) CHECK(*iter == expected[i]);
}

TEST_CASE("Iterators - empty container") {
    MyContainer<int> c;
    auto asc = MyContainer<int>::AscendingOrder(c);
    auto desc = MyContainer<int>::DescendingOrder(c);
    auto side = MyContainer<int>::SideCrossOrder(c);
    auto rev = MyContainer<int>::ReverseOrder(c);
    auto ord = MyContainer<int>::Order(c);
    auto mid = MyContainer<int>::MiddleOutOrder(c);
    CHECK(asc.begin() == asc.end());
    CHECK(desc.begin() == desc.end());
    CHECK(side.begin() == side.end());
    CHECK(rev.begin() == rev.end());
    CHECK(ord.begin() == ord.end());
    CHECK(mid.begin() == mid.end());
}

TEST_CASE("Iterators - single element") {
    MyContainer<int> c;
    c.addElement(42);
    std::vector<int> expected = {42};
    auto asc = MyContainer<int>::AscendingOrder(c);
    auto desc = MyContainer<int>::DescendingOrder(c);
    auto side = MyContainer<int>::SideCrossOrder(c);
    auto rev = MyContainer<int>::ReverseOrder(c);
    auto ord = MyContainer<int>::Order(c);
    auto mid = MyContainer<int>::MiddleOutOrder(c);
    CHECK(*asc.begin() == 42);
    CHECK(*desc.begin() == 42);
    CHECK(*side.begin() == 42);
    CHECK(*rev.begin() == 42);
    CHECK(*ord.begin() == 42);
    CHECK(*mid.begin() == 42);
}

TEST_CASE("Iterators - duplicates") {
    MyContainer<int> c;
    c.addElement(5); c.addElement(5); c.addElement(1); c.addElement(1); c.addElement(3);
    std::vector<int> asc_exp = {1,1,3,5,5};
    std::vector<int> desc_exp = {5,5,3,1,1};
    std::vector<int> side_exp = {1,5,1,5,3};
    std::vector<int> rev_exp = {3,1,1,5,5};
    std::vector<int> ord_exp = {5,5,1,1,3};
    std::vector<int> mid_exp = {1,5,1,5,3};
    size_t i = 0;
    auto asc = MyContainer<int>::AscendingOrder(c);
    for (auto it = asc.begin(); it != asc.end(); ++it, ++i) CHECK(*it == asc_exp[i]);
    i = 0; auto desc = MyContainer<int>::DescendingOrder(c);
    for (auto it = desc.begin(); it != desc.end(); ++it, ++i) CHECK(*it == desc_exp[i]);
    i = 0; auto side = MyContainer<int>::SideCrossOrder(c);
    for (auto it = side.begin(); it != side.end(); ++it, ++i) CHECK(*it == side_exp[i]);
    i = 0; auto rev = MyContainer<int>::ReverseOrder(c);
    for (auto it = rev.begin(); it != rev.end(); ++it, ++i) CHECK(*it == rev_exp[i]);
    i = 0; auto ord = MyContainer<int>::Order(c);
    for (auto it = ord.begin(); it != ord.end(); ++it, ++i) CHECK(*it == ord_exp[i]);
    i = 0; auto mid = MyContainer<int>::MiddleOutOrder(c);
    for (auto it = mid.begin(); it != mid.end(); ++it, ++i) CHECK(*it == mid_exp[i]);
}
