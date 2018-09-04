// Provides some utilities widely used by other modules

#ifndef UTILS_HPP_
#define UTILS_HPP_

#include <set>
#include <cmath>
#include <vector>
#include <string>
#include <limits>
#include <ostream>
#include <iostream>
#include <exception>
#include <algorithm>

// ----------------------------------------------------------------------------------------
// Functions on sequences and iterables

// Display a vector of type T to the required output stream.
template <typename T>
void print_vector(const std::vector<T>& seq, std::ostream& out=std::cout) {
    for (auto i : seq) {
        out << i << " ";
    }
    out << '\n';
}

// Display an iterable given the starting and ending iterators, to the required output stream.
template <class Iterator, class T = typename std::iterator_traits<Iterator>::value_type>
void print(Iterator first, Iterator last, std::ostream& out=std::cout) {
    for (auto it = first; it != last; ++it) {
        out << *it << " ";
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

// Return the first element of an iterable or the next element of a generator, or default.
template<typename T>
T first(const std::vector<T>& v, const T default_=std::numeric_limits<T>::min(), std::ostream& out=std::cout) {
    if (v.size() == 0) {
        return default_;
    }
    try {
        return *v.begin();
    } catch (std::exception& e) {
        out << e.what() << std::endl;
    }
    return default_;
}

// Checks if given element is in the vector.
template<typename T>
bool is_in(const T& data, const std::vector<T>& v) {
    for (auto i : v) {
        if (i == data) {
            return true;
        }
    }
    return false;
}

// Return the most common data item. If there are ties, return any one of them.
template<class Iterator, class T = typename std::iterator_traits<Iterator>::value_type>
T mode(const Iterator& first, const Iterator& last) {
    T o_mode = std::numeric_limits<T>::min();
    std::size_t o_count = 0;
    for (auto it = first; it != last; ++it) {
        T mode_ = *it;
        std::size_t count_ = 0;
        for (auto jt = first; jt != last; ++jt) {
            if (*jt == mode_) {
                count_++;
            }
        }

        if (count_ > o_count) {
            o_mode = mode_;
            o_count = count_;
        }
    }
    return o_mode;
}

// Return the set of all subsets of a given iterable.
template<class Iterator, class T = typename std::iterator_traits<Iterator>::value_type>
std::vector<std::vector<T>> powerset(const Iterator& first, const Iterator& last) {
    std::size_t n = last - first;
    std::size_t N = std::pow(2, n);

    std::vector<std::vector<T>> pset;
    for (std::size_t i = 0; i < N; ++i) {
        std::vector<T> r_;
        for (std::size_t j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                r_.push_back(*(first + j));
            }
        }
        pset.push_back(r_);
    }
    return pset;
}

// ----------------------------------------------------------------------------------------
// Argmin and Argmax

#endif