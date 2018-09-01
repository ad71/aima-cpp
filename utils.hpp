#ifndef UTILS_HPP_
#define UTILS_HPP_

#include <vector>
#include <ostream>

template<typename T>
void print_vector(std::ostream& out, std::vector<T> seq) {
    for (std::size_t i = 0; i < seq.size(); ++i) {
        out << seq[i] << " ";
    }
    out << '\n';
}

#endif