/* Search (Chapters 3-4)
The way to use this code is to subclass Problem to create a class of problems,
then create problem instances and solve them with calls to the various search
functions.
*/

#ifndef SEARCH_HPP_
#define SEARCH_HPP_

#include <cmath>
#include <vector>

#include "utils.hpp"

// Returns the highest possible value of a given type
template<typename T>
T infinity(T x) {
    return std::numeric_limits<T>::max();
}

// ----------------------------------------------------------------------------------------

// The abstract class for a formal problem. You should subclass this and implement the
// methods actions and result, and possibly the constructor, goal_test and path_cost.
// Then you will create instances of your subclass and solve them with
// the various search functions.
// @param T: typename of elements in state vectors
// @param U: typename of action entity
// @param V: typename of cost entity
template<typename T, typename U, typename V>
class Problem {
public:
    // The constructor specifies the initial state, and possibly a goal state, if there is a unique goal.
    // Your subclass's constructor can add other arguments.
    Problem(std::vector<T>& initial, std::vector<T>& goal={}) : initial_(initial), goal_(goal) {}

    // Return the actions that can be executed in the given state. The result would typically be a vector,
    // but if there are many actions, consider yielding them one at a time in an iterator, rather than
    // building them all at once.
    virtual std::vector<U> actions(const std::vector<T>& state) = 0;

    // Return the state that results from executing the given action in the given state. The action must
    // be one of this.actions(state).
    virtual std::vector<T> result(const std::vector<T>& state, const U& action) = 0;

    // For optimization problems, each state has a value. Hill-climbing and related algorithms
    // try to maximize this value.
    virtual V value(const std::vector<T>& state) = 0;

    // Return true if the state is a goal. The default method compares the state to this.goal_ or checks
    // for state in this.goal_ if it is a vector, as specified in the constructor. Override this method
    // if checking against a single this.goal_ is not enough.
    bool goal_test(const std::vector<T>& state);

    // Return the cost if a solution path that arrives at state2 from state1 via action, assuming cost c
    // to get upto state1. If the problem is such that the path doesn't matter, this function will only
    // look at state2. If the path does matter, it will consider c and maybe state1 and action.
    // The default method costs 1 for every step in the path.
    V path_cost(const V& c, const std::vector<T>& state1, const U& action, const std::vector<T>& state2);

protected:
    std::vector<T> initial_;    // inheritable vector of type T defining the initial state
    std::vector<T> goal_;       // inheritable vector of type T defining the required goal state
};

// @param state: a vector of type T denoting the current state.
template<typename T, typename U, typename V>
bool Problem<T, U, V>::goal_test(const std::vector<T>& state) {
    if (this.goal_.size() > 1) {
        // iterate over all elements of the state vector
        for (std::size_t i = 0; i < state.size(); ++i) {
            if (!is_in(state[i], this.goal_)) {
                return false;
            }
        }
        return true;
    }
    return state == this.goal_;
}

// @param c: the cost of a unit operation
// @param state1: the initial state, applicable only when the path matters
// @param action: the action taken to reach state2
// @param state2: the final state
template<typename T, typename U, typename V>
V Problem<T, U, V>::path_cost(const V& c, const std::vector<T>& state1, const U& action, const std::vector<T>& state2) {
    // path cost defaults to one more than the last cost
    return c + 1;
}

// ----------------------------------------------------------------------------------------

template<typename T, typename U, typename V>
class Node {
public:
    Node(const std::vector<T>& state, const Node<T, U, V>& parent=NULL, const U& action=NULL, const V& path_cost=0) : state_(state), parent_(parent), action_(action), path_cost_(path_cost), depth_(0) {
        if (parent != NULL) {
            this.depth_ = parent.depth_ + 1L;
        }
    }
};

#endif