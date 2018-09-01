#include <vector>
#include <cassert>
#include <iostream>
#include "../utils.hpp"

void test_removeall() {
    std::vector<int> A = {1, 2, 3, 4, 3, 6, 7, 3, 9, 8, 3, 6, 7, 3, 3, 0, 3};
    int B = 3;
    std::vector<int> result = removeall(B, A);
    std::vector<int> reqd_r = {1, 2, 4, 6, 7, 9, 8, 6, 7, 0};
    assert(result == reqd_r);
    return;
}

int main() {
    test_removeall();
    return 0;
}