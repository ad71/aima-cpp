// Provides some utilities widely used by other modules

#ifndef UTILS_HPP_
#define UTILS_HPP_

#include <set>
#include <cmath>
#include <vector>
#include <string>
#include <random>
#include <limits>
#include <chrono>
#include <ostream>
#include <iostream>
#include <exception>
#include <algorithm>
#include <functional>

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
    std::size_t N = static_cast<std::size_t>(std::pow(2, n));

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

// Commonly used custom compare functions.
template<typename T>
class Compare {
public:
    inline static bool identity(T, T);
    inline static bool absolute(T, T);
    inline static bool length(T, T);

private:
    Compare() {};
};

// Identity comparison function.
template<typename T>
inline bool Compare<T>::identity(T i, T j) {
    return i < j;
}

// Absolute value comparison function.
template<typename T>
inline bool Compare<T>::absolute(T i, T j) {
    return std::abs(i) < std::abs(j);
}

// Length comparison function.
template<typename T>
inline bool Compare<T>::length(T i, T j) {
    return i.size() < j.size();
}

// Return the maximum argument in the iterable corresponding to the given compare function.
template <class Iterator, class T = typename std::iterator_traits<Iterator>::value_type>
T argmax(const Iterator &first, const Iterator &last, std::function<bool(T, T)> cmp = Compare<T>::identity) {
    return *std::max_element(first, last, cmp);
}

// Return the minimum argument in the iterable corresponding to the given compare function.
template<class Iterator, class T = typename std::iterator_traits<Iterator>::value_type>
T argmin(const Iterator& first, const Iterator& last, std::function<bool(T, T)> cmp = Compare<T>::identity) {
    return *std::min_element(first, last, cmp);
}

// Randomly shuffle a copy of an iterable.
template<class Iterator, class T = typename std::iterator_traits<Iterator>::value_type>
void shuffle(const Iterator& first, const Iterator& last, unsigned seed = 0) {
    std::shuffle(first, last, std::default_random_engine(seed));
}

// Return a maximum of a given sequence. Break ties at random.
template<class Iterator, class T = typename std::iterator_traits<Iterator>::value_type>
T argmax_random_tie(const Iterator& first, const Iterator& last, std::function<bool(T, T)> cmp = Compare<T>::identity, bool random_seed = false, unsigned seed = 0) {
    if (random_seed) {
        seed = std::chrono::system_clock::now().time_since_epoch().count();
    }
    shuffle(first, last, seed);
    return argmax(first, last, cmp);
}

// Return a minimum of a given sequence. Break ties at random.
template<class Iterator, class T = typename std::iterator_traits<Iterator>::value_type>
T argmin_random_tie(const Iterator& first, const Iterator& last, std::function<bool(T, T)> cmp = Compare<T>::identity, bool random_seed = false, unsigned seed = 0) {
    if (random_seed) {
        seed = std::chrono::system_clock::now().time_since_epoch().count();
    }
    shuffle(first, last, seed);
    return argmin(first, last, cmp);
}

// ----------------------------------------------------------------------------------------

#endif