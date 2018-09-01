#ifndef UTILS_HPP_
#define UTILS_HPP_

#include <set>
#include <vector>
#include <string>
#include <ostream>

// ----------------------------------------------------------------------------------------
// Functions on sequences and iterables

// Display a vector of type T to the required output stream
template<typename T>
void print_vector(std::ostream& out, const std::vector<T>& seq) {
    for (auto i : seq) {
        out << i << " ";
    }
    out << '\n';
}

// Return a copy of a vector with all occurences of `item` removed.
template<typename T>
std::vector<T> removeall(const T item, const std::vector<T>& seq) {
    std::vector<T> n_v;
    for (auto i : seq) {
        if (i != item) {
            n_v.push_back(i);
        }
    }
    return n_v;
}

// Return a copy of a string with all occurences of `item` removed.
std::string removeall(const char item, const std::string& str) {
    std::string n_s = "";
    for (auto i : str) {
        if (i != item) {
            n_s += i;
        }
    }
    return n_s;
}

// Remove duplicate elements from a sequence of elements. Assumes hashable elements.
template<typename T>
std::vector<T> unique(std::vector<T> v) {
    std::set<T> s(std::make_move_iterator(v.begin()), std::make_move_iterator(v.end()));
    std::vector<T> n_v(std::make_move_iterator(s.begin()), std::make_move_iterator(s.end()));
    return n_v;
}

// Count the number of items in sequence that are interpreted as true.
template<typename T>
std::size_t count(const std::vector<T>& v) {
    std::size_t count_ = 0;
    for (auto i : v) {
        if (bool(i)) {
            count_++;
        }
    }
    return count_;
}

// Return the product of the numbers in a vector.
template<typename T>
long long product(const std::vector<T>& v) {
    long long result = 1;
    for (auto i : v) {
        result *= i;
    }
    return result;
}

#endif