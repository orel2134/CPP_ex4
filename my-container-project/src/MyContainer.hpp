#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include <stdexcept>

namespace my_container_project {

/**
 * @brief A generic container class supporting custom iteration orders.
 * @tparam T Element type (default: int)
 */
template<typename T = int>
class MyContainer {
private:
    std::vector<T> elements;

public:
    MyContainer() = default;
    ~MyContainer() = default;

    /**
     * @brief Adds an element to the container.
     * @param element The element to add.
     */
    void addElement(const T& element) {
        elements.push_back(element);
    }

    /**
     * @brief Removes an element from the container.
     * @param element The element to remove.
     * @throws std::runtime_error If the element is not found.
     */
    void remove(const T& element) {
        auto it = std::remove(elements.begin(), elements.end(), element);
        if (it == elements.end())
            throw std::runtime_error("Element not found in container");
        elements.erase(it, elements.end());
    }

    /**
     * @brief Returns the number of elements in the container.
     * @return size_t The size of the container.
     */
    size_t size() const {
        return elements.size();
    }

    /**
     * @brief Accessor for the internal elements vector.
     * @return const reference to the vector of elements.
     */
    const std::vector<T>& getElements() const { return elements; }

    /**
     * @brief Output stream operator for printing the container.
     * @param os Output stream.
     * @param cont The container to print.
     * @return Output stream with elements.
     */
    friend std::ostream& operator<<(std::ostream& os, const MyContainer<T>& cont) {
        for (const auto& el : cont.elements)
            os << el << " ";
        return os;
    }

    /**
     * @brief Ascending order iterator wrapper class.
     */
    class AscendingOrder {
    private:
        std::vector<T> sorted_elements;
    public:
        /**
         * @brief Constructs AscendingOrder iterator from container.
         * @param container Source container.
         */
        AscendingOrder(const MyContainer& container)
            : sorted_elements(container.elements) {
            std::sort(sorted_elements.begin(), sorted_elements.end());
        }

        /**
         * @brief Iterator class for AscendingOrder.
         */

        class Iterator {
        private:
            const std::vector<T>& ref;
            size_t idx;
        public:
            Iterator(const std::vector<T>& v, size_t i) : ref(v), idx(i) {}

            const T& operator*() const { return ref.at(idx); }

            Iterator& operator++() { ++idx; return *this; } // Prefix increment

            Iterator operator++(int) { Iterator temp = *this; ++(*this); return temp; } // Postfix increment

            Iterator& operator--() { --idx; return *this; } // Prefix decrement

            Iterator operator--(int) { Iterator temp = *this; --(*this); return temp; } // Postfix decrement

            Iterator operator+(size_t n) const { return Iterator(ref, idx + n); } // Advance by n

            Iterator operator-(size_t n) const { return Iterator(ref, idx - n); } // Retreat by n

            const T& operator[](size_t n) const { return ref.at(idx + n); } // Access by index

            bool operator!=(const Iterator& other) const { return idx != other.idx || &ref != &other.ref; }

            bool operator==(const Iterator& other) const { return !(*this != other); }
        };

        Iterator begin() const { return Iterator(sorted_elements, 0); }
        Iterator end() const { return Iterator(sorted_elements, sorted_elements.size()); }
    };

    /**
     * @brief Descending order iterator wrapper class.
     */
    class DescendingOrder {
    private:
        std::vector<T> sorted_elements;
    public:
        /**
         * @brief Constructs DescendingOrder iterator from container.
         * @param container Source container.
         */
        DescendingOrder(const MyContainer& container)
            : sorted_elements(container.elements) {
            std::sort(sorted_elements.begin(), sorted_elements.end(), std::greater<T>());
        }

        class Iterator {
        private:
            const std::vector<T>& ref;
            size_t idx;
        public:
            Iterator(const std::vector<T>& v, size_t i) : ref(v), idx(i) {}

            const T& operator*() const { return ref.at(idx); }

            Iterator& operator++() { ++idx; return *this; } // Prefix increment

            Iterator operator++(int) { Iterator temp = *this; ++(*this); return temp; } // Postfix increment

            Iterator& operator--() { --idx; return *this; } // Prefix decrement

            Iterator operator--(int) { Iterator temp = *this; --(*this); return temp; } // Postfix decrement

            Iterator operator+(size_t n) const { return Iterator(ref, idx + n); } // Advance by n

            Iterator operator-(size_t n) const { return Iterator(ref, idx - n); } // Retreat by n

            const T& operator[](size_t n) const { return ref.at(idx + n); } // Access by index

            bool operator!=(const Iterator& other) const { return idx != other.idx || &ref != &other.ref; }

            bool operator==(const Iterator& other) const { return !(*this != other); }
        };

        Iterator begin() const { return Iterator(sorted_elements, 0); }
        Iterator end() const { return Iterator(sorted_elements, sorted_elements.size()); }
    };

    /**
     * @brief Side-cross order iterator: left-right alternation from sorted list.
     */
    class SideCrossOrder {
    private:
        std::vector<T> cross_ordered;
    public:
        /**
         * @brief Constructs SideCrossOrder iterator from container.
         * @param container Source container.
         */
        SideCrossOrder(const MyContainer& container) {
            std::vector<T> temp = container.elements;
            std::sort(temp.begin(), temp.end());
            size_t left = 0, right = temp.size() ? temp.size() - 1 : 0;
            while (!temp.empty() && left <= right) {
                if (left == right) {
                    cross_ordered.push_back(temp[left]);
                } else {
                    cross_ordered.push_back(temp[left]);
                    cross_ordered.push_back(temp[right]);
                }
                ++left;
                if (right > 0) --right;
            }
        }

        class Iterator {
        private:
            const std::vector<T>& ref;
            size_t idx;
        public:
            Iterator(const std::vector<T>& v, size_t i) : ref(v), idx(i) {}

            const T& operator*() const { return ref.at(idx); }

            Iterator& operator++() { ++idx; return *this; } // Prefix increment

            Iterator operator++(int) { Iterator temp = *this; ++(*this); return temp; } // Postfix increment

            Iterator& operator--() { --idx; return *this; } // Prefix decrement

            Iterator operator--(int) { Iterator temp = *this; --(*this); return temp; } // Postfix decrement

            Iterator operator+(size_t n) const { return Iterator(ref, idx + n); } // Advance by n

            Iterator operator-(size_t n) const { return Iterator(ref, idx - n); } // Retreat by n

            const T& operator[](size_t n) const { return ref.at(idx + n); } // Access by index

            bool operator!=(const Iterator& other) const { return idx != other.idx || &ref != &other.ref; }

            bool operator==(const Iterator& other) const { return !(*this != other); }
        };

        Iterator begin() const { return Iterator(cross_ordered, 0); }
        Iterator end() const { return Iterator(cross_ordered, cross_ordered.size()); }
    };

    /**
     * @brief Reverse order iterator (original insertion order, reversed).
     */
    class ReverseOrder {
    private:
        const std::vector<T>& ref_elements;
    public:
        ReverseOrder(const MyContainer& container)
            : ref_elements(container.elements) {}

        class Iterator {
        private:
            const std::vector<T>& ref;
            int idx;
        public:
            Iterator(const std::vector<T>& v, int i) : ref(v), idx(i) {}
            const T& operator*() const { return ref.at(idx); }
            Iterator& operator++() { --idx; return *this; }
            bool operator!=(const Iterator& other) const { return idx != other.idx || &ref != &other.ref; }
            bool operator==(const Iterator& other) const { return !(*this != other); }
        };

        Iterator begin() const { return Iterator(ref_elements, static_cast<int>(ref_elements.size()) - 1); }
        Iterator end() const { return Iterator(ref_elements, -1); }
    };

    /**
     * @brief Original order iterator (in insertion order).
     */
    class Order {
    private:
        const std::vector<T>& ref_elements;
    public:
        Order(const MyContainer& container)
            : ref_elements(container.elements) {}

        class Iterator {
        private:
            const std::vector<T>& ref;
            size_t idx;
        public:
            Iterator(const std::vector<T>& v, size_t i) : ref(v), idx(i) {}

            const T& operator*() const { return ref.at(idx); }

            Iterator& operator++() { ++idx; return *this; } // Prefix increment

            Iterator operator++(int) { Iterator temp = *this; ++(*this); return temp; } // Postfix increment

            Iterator& operator--() { --idx; return *this; } // Prefix decrement

            Iterator operator--(int) { Iterator temp = *this; --(*this); return temp; } // Postfix decrement

            Iterator operator+(size_t n) const { return Iterator(ref, idx + n); } // Advance by n

            Iterator operator-(size_t n) const { return Iterator(ref, idx - n); } // Retreat by n

            const T& operator[](size_t n) const { return ref.at(idx + n); } // Access by index

            bool operator!=(const Iterator& other) const { return idx != other.idx || &ref != &other.ref; }

            bool operator==(const Iterator& other) const { return !(*this != other); }
        };

        Iterator begin() const { return Iterator(ref_elements, 0); }
        Iterator end() const { return Iterator(ref_elements, ref_elements.size()); }
    };




    /**
     * @brief Middle-out order iterator: center first, then left, then right.
     */
    class MiddleOutOrder {
    private:
        std::vector<T> midout_elements;

    public:
        /**
         * @brief Constructs a middle-out order iterator from the container.
         * If number of elements is even, middle index is rounded down.
         * @param container Source container.
         */
        MiddleOutOrder(const MyContainer& container) {
            const std::vector<T>& temp = container.getElements();
            size_t n = temp.size();
            if (n == 0) return;

            size_t mid = (n % 2 == 0) ? (n / 2 - 1) : (n / 2);
            midout_elements.push_back(temp[mid]);

            int left = static_cast<int>(mid) - 1;
            int right = static_cast<int>(mid) + 1;

            while (left >= 0 || right < static_cast<int>(n)) {
                if (left >= 0) {
                    midout_elements.push_back(temp[left]);
                    --left;
                }
                if (right < static_cast<int>(n)) {
                    midout_elements.push_back(temp[right]);
                    ++right;
                }
            }
        }

        auto begin() const { return midout_elements.begin(); }
        auto end() const { return midout_elements.end(); }
    };
};

} // namespace my_container_project
