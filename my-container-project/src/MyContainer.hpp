#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include <stdexcept>

namespace ariel {

template<typename T = int>
class MyContainer {
private:
    std::vector<T> elements;

public:
    MyContainer() = default;
    ~MyContainer() = default;

    void addElement(const T& element) {
        elements.push_back(element);
    }
    void remove(const T& element) {
        auto it = std::remove(elements.begin(), elements.end(), element);
        if (it == elements.end())
            throw std::runtime_error("Element not found in container");
        elements.erase(it, elements.end());
    }
    size_t size() const {
        return elements.size();
    }
    const std::vector<T>& getElements() const { return elements; }

    // -- אופרטור פלט (להדפיס את הקונטיינר) --
    friend std::ostream& operator<<(std::ostream& os, const MyContainer<T>& cont) {
        for (const auto& el : cont.elements)
            os << el << " ";
        return os;
    }

    // ========== AscendingOrder ==========
    class AscendingOrder {
    private:
        std::vector<T> sorted_elements;
    public:
        AscendingOrder(const MyContainer& container)
            : sorted_elements(container.elements) {
            std::sort(sorted_elements.begin(), sorted_elements.end());
        }
        class Iterator {
        private:
            const std::vector<T>& ref;
            size_t idx;
        public:
            Iterator(const std::vector<T>& v, size_t i) : ref(v), idx(i) {}
            const T& operator*() const { return ref.at(idx); }
            Iterator& operator++() { ++idx; return *this; }
            bool operator!=(const Iterator& other) const { return idx != other.idx || &ref != &other.ref; }
            bool operator==(const Iterator& other) const { return !(*this != other); }
        };
        Iterator begin() const { return Iterator(sorted_elements, 0); }
        Iterator end()   const { return Iterator(sorted_elements, sorted_elements.size()); }
    };

    // ========== DescendingOrder ==========
    class DescendingOrder {
    private:
        std::vector<T> sorted_elements;
    public:
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
            Iterator& operator++() { ++idx; return *this; }
            bool operator!=(const Iterator& other) const { return idx != other.idx || &ref != &other.ref; }
            bool operator==(const Iterator& other) const { return !(*this != other); }
        };
        Iterator begin() const { return Iterator(sorted_elements, 0); }
        Iterator end()   const { return Iterator(sorted_elements, sorted_elements.size()); }
    };

    // ========== SideCrossOrder ==========
    class SideCrossOrder {
    private:
        std::vector<T> cross_ordered;
    public:
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
            Iterator& operator++() { ++idx; return *this; }
            bool operator!=(const Iterator& other) const { return idx != other.idx || &ref != &other.ref; }
            bool operator==(const Iterator& other) const { return !(*this != other); }
        };
        Iterator begin() const { return Iterator(cross_ordered, 0); }
        Iterator end()   const { return Iterator(cross_ordered, cross_ordered.size()); }
    };

    // ========== ReverseOrder ==========
    class ReverseOrder {
    private:
        const std::vector<T>& ref_elements;
    public:
        ReverseOrder(const MyContainer& container)
            : ref_elements(container.elements) {}
        class Iterator {
        private:
            const std::vector<T>& ref;
            int idx; // שים לב! int כדי לא להגיע למינוס-1
        public:
            Iterator(const std::vector<T>& v, int i) : ref(v), idx(i) {}
            const T& operator*() const { return ref.at(idx); }
            Iterator& operator++() { --idx; return *this; }
            bool operator!=(const Iterator& other) const { return idx != other.idx || &ref != &other.ref; }
            bool operator==(const Iterator& other) const { return !(*this != other); }
        };
        Iterator begin() const { return Iterator(ref_elements, static_cast<int>(ref_elements.size()) - 1); }
        Iterator end()   const { return Iterator(ref_elements, -1); }
    };

    // ========== Order ==========
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
            Iterator& operator++() { ++idx; return *this; }
            bool operator!=(const Iterator& other) const { return idx != other.idx || &ref != &other.ref; }
            bool operator==(const Iterator& other) const { return !(*this != other); }
        };
        Iterator begin() const { return Iterator(ref_elements, 0); }
        Iterator end()   const { return Iterator(ref_elements, ref_elements.size()); }
    };

    // ========== MiddleOutOrder ==========
    class MiddleOutOrder {
    private:
        std::vector<T> midout_elements;
    public:
        MiddleOutOrder(const MyContainer& container) {
            std::vector<T> temp = container.elements;
            std::sort(temp.begin(), temp.end()); // Ensure elements are sorted

            size_t n = temp.size();
            if (n == 0) return;
            size_t mid = n / 2; // Middle index rounded down
            midout_elements.push_back(temp[mid]);
            int left = mid - 1;
            int right = mid + 1;
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
        class Iterator {
        private:
            const std::vector<T>& ref;
            size_t idx;
        public:
            Iterator(const std::vector<T>& v, size_t i) : ref(v), idx(i) {}
            const T& operator*() const { return ref.at(idx); }
            Iterator& operator++() { ++idx; return *this; }
            bool operator!=(const Iterator& other) const { return idx != other.idx || &ref != &other.ref; }
            bool operator==(const Iterator& other) const { return !(*this != other); }
        };
        Iterator begin() const { return Iterator(midout_elements, 0); }
        Iterator end()   const { return Iterator(midout_elements, midout_elements.size()); }
    };
};

} // namespace ariel
