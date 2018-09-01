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
    std::string s_A = "acgtcagtcgacgtgactgactgactgtat";
    char c_B = 'a';
    std::string s_result = removeall(c_B, s_A);
    std::string s_reqd_r = "cgtcgtcgcgtgctgctgctgtt";
    assert(s_result == s_reqd_r);
    return;
}

void test_unique() {
    std::vector<int> vi_A = {1, 2, 3, 4, 3, 6, 7, 3, 9, 8, 3, 6, 7, 3, 3, 0, 3};
    std::vector<int> vi_result = unique(vi_A);
    std::vector<int> vi_reqd_r = {0, 1, 2, 3, 4, 6, 7, 8, 9};
    assert(vi_result == vi_reqd_r);
    std::vector<long> vl_A = {81276381, 9812739, 2938749287, 9812739, 893764189, 293874, 9812739, 9183749, 9238744, 9812739, 293874688, 9812739};
    std::vector<long> vl_result = unique(vl_A);
    std::vector<long> vl_reqd_r = {293874, 9183749, 9238744, 9812739, 81276381, 293874688, 893764189, 2938749287};
    assert(vl_result == vl_reqd_r);
    return;
}

void test_count() {
    std::vector<int> vi_A = {1, 2, 3, 4, 3, 6, 7, 3, 9, 8, 3, 6, 7, 3, 3, 0, 3};
    std::size_t l_result = count(vi_A);
    assert(l_result == 16);
    std::vector<bool> vb_A = {true, true, false, false, false, true, false, true};
    l_result = count(vb_A);
    assert(l_result == 4);
    return;
}

int main() {
    test_removeall();
    test_unique();
    test_count();
    return 0;
}