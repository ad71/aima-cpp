#include <gtest/gtest.h>

#include <vector>
#include <limits>
#include <iostream>
#include "../src/utils.hpp"

TEST(VI_A, REMOVEALL) {
    std::vector<int> vi_A = {1, 2, 3, 4, 3, 6, 7, 3, 9, 8, 3, 6, 7, 3, 3, 0, 3};
    int i_B = 3;
    std::vector<int> vi_result = removeall(i_B, vi_A);
    std::vector<int> vi_reqd_r = {1, 2, 4, 6, 7, 9, 8, 6, 7, 0};
    ASSERT_EQ(vi_result, vi_reqd_r);
}

TEST(VL_A, REMOVEALL) {
    std::vector<long> vl_A = {81276381, 9812739, 293874928, 9812739, 893764189, 293874, 9812739, 9183749, 9238744, 9812739, 293874688, 9812739};
    long l_B = 9812739;
    std::vector<long> vl_result = removeall(l_B, vl_A);
    std::vector<long> vl_reqd_r = {81276381, 293874928, 893764189, 293874, 9183749, 9238744, 293874688};
    ASSERT_EQ(vl_result, vl_reqd_r);
}

TEST(S_A, REMOVEALL) {
    std::string s_A = "acgtcagtcgacgtgactgactgactgtat";
    char c_B = 'a';
    std::string s_result = removeall(c_B, s_A);
    std::string s_reqd_r = "cgtcgtcgcgtgctgctgctgtt";
    ASSERT_EQ(s_result, s_reqd_r);
}

TEST(VI_A, UNIQUE) {
    std::vector<int> vi_A = {1, 2, 3, 4, 3, 6, 7, 3, 9, 8, 3, 6, 7, 3, 3, 0, 3};
    std::vector<int> vi_result = unique(vi_A);
    std::vector<int> vi_reqd_r = {0, 1, 2, 3, 4, 6, 7, 8, 9};
    ASSERT_EQ(vi_result, vi_reqd_r);
}

TEST(VL_A, UNIQUE) {
    std::vector<long> vl_A = {81276381, 9812739, 293874928, 9812739, 893764189, 293874, 9812739, 9183749, 9238744, 9812739, 293874688, 9812739};
    std::vector<long> vl_result = unique(vl_A);
    std::vector<long> vl_reqd_r = {293874, 9183749, 9238744, 9812739, 81276381, 293874688, 293874928, 893764189};
    ASSERT_EQ(vl_result, vl_reqd_r);
}

TEST(VI_A, COUNT) {
    std::vector<int> vi_A = {1, 2, 3, 4, 3, 6, 7, 3, 9, 8, 3, 6, 7, 3, 3, 0, 3};
    std::size_t l_result = count(vi_A);
    ASSERT_EQ(l_result, 16);
}

TEST(VB_A, COUNT) {
    std::vector<bool> vb_A = {true, true, false, false, false, true, false, true};
    std::size_t l_result = count(vb_A);
    ASSERT_EQ(l_result, 4);
}

TEST(VI_A, PRODUCT) {
    std::vector<int> vi_A = {1, 2, 3, 4};
    int i_result = product(vi_A);
    ASSERT_EQ(i_result, 24);
}

TEST(VLL_A, PRODUCT) {
    std::vector<long long> vll_A = {9823, 12983, 123, 3847, 2873};
    long long ll_result = product(vll_A);
    ASSERT_EQ(ll_result, 173373263760957117);
}

TEST(VI_A, FIRST) {
    std::vector<int> vi_A = {1, 2, 3, 4, 3, 6, 7, 3, 9, 8, 3, 6, 7, 3, 3, 0, 3};
    int i_result = first(vi_A);
    ASSERT_EQ(i_result, 1);
}

TEST(VL_A, FIRST) {
    std::vector<long> vl_A = {81276381, 9812739, 293874928, 9812739, 893764189, 293874, 9812739, 9183749, 9238744, 9812739, 293874688, 9812739};
    long l_result = first(vl_A);
    ASSERT_EQ(l_result, 81276381);
}

TEST(VLL_A, FIRST) {
    std::vector<long long> vll_A = {};
    long long ll_result = first(vll_A);
    ASSERT_EQ(ll_result, std::numeric_limits<long long>::min());
}

TEST(VS_A, IS_IN) {
    std::vector<char> vs_A = {'1', 'e', '2'};
    ASSERT_EQ(is_in('e', vs_A), true);
}

TEST(VI_A, IS_IN) {
    std::vector<int> vi_A = {1, 5, 7, 7, 4};
    ASSERT_EQ(is_in(2, vi_A), false);
}

TEST(VI_A, MODE) {
    std::vector<int> vi_A = {12, 32, 2, 1, 2, 3, 2, 3, 2, 3, 44, 3, 12, 4, 9, 0, 3, 45, 3};
    ASSERT_EQ(mode(vi_A.begin(), vi_A.end()), 3);
}

TEST(S_A, MODE) {
    std::string s_A = "absndkwoajfkalwpdlsdlfllalsflfdslgflal";
    ASSERT_EQ(mode(s_A.begin(), s_A.end()), 'l');
}

TEST(VI_A, POWERSET) {
    std::vector<int> vi_A = {1, 2, 3, 4};
    std::vector<std::vector<int>> vvi_result = powerset(vi_A.begin(), vi_A.end());
    std::vector<std::vector<int>> vvi_reqd_r = {{}, {1}, {2}, {1, 2}, {3}, {1, 3}, {2, 3}, {1, 2, 3}, {4}, {1, 4}, {2, 4}, {1, 2, 4}, {3, 4}, {1, 3, 4}, {2, 3, 4}, {1, 2, 3, 4}};
    ASSERT_EQ(vvi_result, vvi_reqd_r);
}

TEST(S_A, POWERSET) {
    std::string s_A = "abc";
    std::vector<std::vector<char>> vvc_result = powerset(s_A.begin(), s_A.end());
    std::vector<std::vector<char>> vvc_reqd_r = {{}, {'a'}, {'b'}, {'a', 'b'}, {'c'}, {'a', 'c'}, {'b', 'c'}, {'a', 'b', 'c'}};
    ASSERT_EQ(vvc_result, vvc_reqd_r);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}