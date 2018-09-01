#ifndef UTILS_HPP_
#define UTILS_HPP_

#include <vector>
#include <ostream>

// Display a vector of type T to the required output stream
template<typename T>
void print_vector(std::ostream& out, const std::vector<T>& seq) {
    for (std::size_t i = 0; i < seq.size(); ++i) {
        out << seq[i] << " ";
    }
    out << '\n';
}

// Return a copy of a vector with all occurences of `item` removed
template<typename T>
std::vector<T> removeall(const T item, const std::vector<T>& seq) {
    std::vector<T> n_v;
    for (std::size_t i = 0; i < seq.size(); ++i) {
        if (seq[i] != item) {
            n_v.push_back(seq[i]);
        }
    }
    return n_v;
}

#endif