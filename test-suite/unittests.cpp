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

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}