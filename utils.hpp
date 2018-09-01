#ifndef UTILS_HPP_
#define UTILS_HPP_

#include <vector>
#include <string>
#include <ostream>

// Display a vector of type T to the required output stream
template<typename T>
void print_vector(std::ostream& out, const std::vector<T>& seq) {
    for (auto i : seq) {
        out << i << " ";
    }
    out << '\n';
}

// Return a copy of a vector with all occurences of `item` removed
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

#endif