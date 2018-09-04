#include <vector>
#include <limits>
#include <cassert>
#include <iostream>
#include "../src/utils.hpp"

void test_removeall() {
    std::vector<int> vi_A = {1, 2, 3, 4, 3, 6, 7, 3, 9, 8, 3, 6, 7, 3, 3, 0, 3};
    int i_B = 3;
    std::vector<int> vi_result = removeall(i_B, vi_A);
    std::vector<int> vi_reqd_r = {1, 2, 4, 6, 7, 9, 8, 6, 7, 0};
    assert(vi_result == vi_reqd_r);
    std::vector<long> vl_A = {81276381, 9812739, 293874928, 9812739, 893764189, 293874, 9812739, 9183749, 9238744, 9812739, 293874688, 9812739};
    long l_B = 9812739;
    std::vector<long> vl_result = removeall(l_B, vl_A);
    std::vector<long> vl_reqd_r = {81276381, 293874928, 893764189, 293874, 9183749, 9238744, 293874688};
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
    std::vector<long> vl_A = {81276381, 9812739, 293874928, 9812739, 893764189, 293874, 9812739, 9183749, 9238744, 9812739, 293874688, 9812739};
    std::vector<long> vl_result = unique(vl_A);
    std::vector<long> vl_reqd_r = {293874, 9183749, 9238744, 9812739, 81276381, 293874688, 293874928, 893764189};
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

void test_product() {
    std::vector<int> vi_A = {1, 2, 3, 4};
    int i_result = product(vi_A);
    assert(i_result == 24);
    std::vector<long long> vll_A = {9823, 12983, 123, 3847, 2873};
    long long ll_result = product(vll_A);
    assert(ll_result == 173373263760957117);
    return;
}

void test_first() {
    std::vector<int> vi_A = {1, 2, 3, 4, 3, 6, 7, 3, 9, 8, 3, 6, 7, 3, 3, 0, 3};
    int i_result = first(vi_A);
    assert(i_result == 1);
    std::vector<long> vl_A = {81276381, 9812739, 293874928, 9812739, 893764189, 293874, 9812739, 9183749, 9238744, 9812739, 293874688, 9812739};
    long l_result = first(vl_A);
    assert(l_result == 81276381);
    std::vector<long long> vll_A = {};
    long long ll_result = first(vll_A);
    assert(ll_result == std::numeric_limits<long long>::min());
    return;
}

void test_is_in() {
    std::vector<char> vs_A = {'1', 'e', '2'};
    assert(is_in('e', vs_A));
    std::vector<int> vi_A = {1, 5, 7, 7, 4};
    assert(!is_in(2, vi_A));
    return;
}

void test_mode() {
    std::vector<int> vi_A = {12, 32, 2, 1, 2, 3, 2, 3, 2, 3, 44, 3, 12, 4, 9, 0, 3, 45, 3};
    assert(mode(vi_A.begin(), vi_A.end()) == 3);
    std::string s_A = "absndkwoajfkalwpdlsdlfllalsflfdslgflal";
    assert(mode(s_A.begin(), s_A.end()) == 'l');
    return;
}

void test_powerset() {
    std::vector<int> vi_A = {1, 2, 3, 4};
    std::vector<std::vector<int>> vvi_result = powerset(vi_A.begin(), vi_A.end());
    std::vector<std::vector<int>> vvi_reqd_r = {{}, {1}, {2}, {1, 2}, {3}, {1, 3}, {2, 3}, {1, 2, 3}, {4}, {1, 4}, {2, 4}, {1, 2, 4}, {3, 4}, {1, 3, 4}, {2, 3, 4}, {1, 2, 3, 4}};
    assert(vvi_result == vvi_reqd_r);
    std::string s_A = "abc";
    std::vector<std::vector<char>> vvc_result = powerset(s_A.begin(), s_A.end());
    std::vector<std::vector<char>> vvc_reqd_r = {{}, {'a'}, {'b'}, {'a', 'b'}, {'c'}, {'a', 'c'}, {'b', 'c'}, {'a', 'b', 'c'}};
    assert(vvc_result == vvc_reqd_r);
    return;
}

void test_argmax() {
    std::vector<int> vi_A = {2, 5, 8, 7, 4, 0, -1, 3};
    int i_result = argmax(vi_A.begin(), vi_A.end());
    std::cout << i_result << std::endl;
    return;
}

int main() {
    test_removeall();
    test_unique();
    test_count();
    test_product();
    test_first();
    test_is_in();
    test_mode();
    test_powerset();
    test_argmax();
    return 0;
}