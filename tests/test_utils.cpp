#include <vector>
#include <cassert>
#include <iostream>
#include "../utils.hpp"

void test_removeall() {
    std::vector<int> vi_A = {1, 2, 3, 4, 3, 6, 7, 3, 9, 8, 3, 6, 7, 3, 3, 0, 3};
    int i_B = 3;
    std::vector<int> vi_result = removeall(i_B, vi_A);
    std::vector<int> vi_reqd_r = {1, 2, 4, 6, 7, 9, 8, 6, 7, 0};
    assert(vi_result == vi_reqd_r);
    std::vector<long> vl_A = {81276381, 9812739, 2938749287, 9812739, 893764189, 293874, 9812739, 9183749, 9238744, 9812739, 293874688, 9812739};
    long l_B = 9812739;
    std::vector<long> vl_result = removeall(l_B, vl_A);
    std::vector<long> vl_reqd_r = {81276381, 2938749287, 893764189, 293874, 9183749, 9238744, 293874688};
    assert(vl_result == vl_reqd_r);
    return;
}

int main() {
    test_removeall();
    return 0;
}