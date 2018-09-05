#include <gtest/gtest.h>

#include <vector>
#include <limits>
#include <iostream>
#include <functional>

#include "../src/utils.hpp"

TEST(REMOVEALL, VI_A) {
    std::vector<int> vi_A = {1, 2, 3, 4, 3, 6, 7, 3, 9, 8, 3, 6, 7, 3, 3, 0, 3};
    int i_B = 3;
    std::vector<int> vi_result = removeall(i_B, vi_A);
    std::vector<int> vi_reqd_r = {1, 2, 4, 6, 7, 9, 8, 6, 7, 0};
    ASSERT_EQ(vi_result, vi_reqd_r);
}

TEST(REMOVEALL, VL_A) {
    std::vector<long> vl_A = {81276381, 9812739, 293874928, 9812739, 893764189, 293874, 9812739, 9183749, 9238744, 9812739, 293874688, 9812739};
    long l_B = 9812739;
    std::vector<long> vl_result = removeall(l_B, vl_A);
    std::vector<long> vl_reqd_r = {81276381, 293874928, 893764189, 293874, 9183749, 9238744, 293874688};
    ASSERT_EQ(vl_result, vl_reqd_r);
}

TEST(REMOVEALL, S_A) {
    std::string s_A = "acgtcagtcgacgtgactgactgactgtat";
    char c_B = 'a';
    std::string s_result = removeall(c_B, s_A);
    std::string s_reqd_r = "cgtcgtcgcgtgctgctgctgtt";
    ASSERT_EQ(s_result, s_reqd_r);
}

TEST(UNIQUE, VI_A) {
    std::vector<int> vi_A = {1, 2, 3, 4, 3, 6, 7, 3, 9, 8, 3, 6, 7, 3, 3, 0, 3};
    std::vector<int> vi_result = unique(vi_A);
    std::vector<int> vi_reqd_r = {0, 1, 2, 3, 4, 6, 7, 8, 9};
    ASSERT_EQ(vi_result, vi_reqd_r);
}

TEST(UNIQUE, VL_A) {
    std::vector<long> vl_A = {81276381, 9812739, 293874928, 9812739, 893764189, 293874, 9812739, 9183749, 9238744, 9812739, 293874688, 9812739};
    std::vector<long> vl_result = unique(vl_A);
    std::vector<long> vl_reqd_r = {293874, 9183749, 9238744, 9812739, 81276381, 293874688, 293874928, 893764189};
    ASSERT_EQ(vl_result, vl_reqd_r);
}

TEST(COUNT, VI_A) {
    std::vector<int> vi_A = {1, 2, 3, 4, 3, 6, 7, 3, 9, 8, 3, 6, 7, 3, 3, 0, 3};
    std::size_t l_result = count(vi_A);
    ASSERT_EQ(l_result, 16);
}

TEST(COUNT, VB_A) {
    std::vector<bool> vb_A = {true, true, false, false, false, true, false, true};
    std::size_t l_result = count(vb_A);
    ASSERT_EQ(l_result, 4);
}

TEST(PRODUCT, VI_A) {
    std::vector<int> vi_A = {1, 2, 3, 4};
    long long i_result = product(vi_A);
    ASSERT_EQ(i_result, 24);
}

TEST(PRODUCT, VLL_A) {
    std::vector<long long> vll_A = {9823, 12983, 123, 3847, 2873};
    long long ll_result = product(vll_A);
    ASSERT_EQ(ll_result, 173373263760957117);
}

TEST(FIRST, VI_A) {
    std::vector<int> vi_A = {1, 2, 3, 4, 3, 6, 7, 3, 9, 8, 3, 6, 7, 3, 3, 0, 3};
    int i_result = first(vi_A);
    ASSERT_EQ(i_result, 1);
}

TEST(FIRST, VL_A) {
    std::vector<long> vl_A = {81276381, 9812739, 293874928, 9812739, 893764189, 293874, 9812739, 9183749, 9238744, 9812739, 293874688, 9812739};
    long l_result = first(vl_A);
    ASSERT_EQ(l_result, 81276381);
}

TEST(FIRST, VLL_A) {
    std::vector<long long> vll_A = {};
    long long ll_result = first(vll_A);
    ASSERT_EQ(ll_result, std::numeric_limits<long long>::min());
}

TEST(IS_IN, VS_A) {
    std::vector<char> vs_A = {'1', 'e', '2'};
    ASSERT_EQ(is_in('e', vs_A), true);
}

TEST(IS_IN, VI_A) {
    std::vector<int> vi_A = {1, 5, 7, 7, 4};
    ASSERT_EQ(is_in(2, vi_A), false);
}

TEST(MODE, VI_A) {
    std::vector<int> vi_A = {12, 32, 2, 1, 2, 3, 2, 3, 2, 3, 44, 3, 12, 4, 9, 0, 3, 45, 3};
    ASSERT_EQ(mode(vi_A.begin(), vi_A.end()), 3);
}

TEST(MODE, S_A) {
    std::string s_A = "absndkwoajfkalwpdlsdlfllalsflfdslgflal";
    ASSERT_EQ(mode(s_A.begin(), s_A.end()), 'l');
}

TEST(POWERSET, VI_A) {
    std::vector<int> vi_A = {1, 2, 3, 4};
    std::vector<std::vector<int>> vvi_result = powerset(vi_A.begin(), vi_A.end());
    std::vector<std::vector<int>> vvi_reqd_r = {{}, {1}, {2}, {1, 2}, {3}, {1, 3}, {2, 3}, {1, 2, 3}, {4}, {1, 4}, {2, 4}, {1, 2, 4}, {3, 4}, {1, 3, 4}, {2, 3, 4}, {1, 2, 3, 4}};
    ASSERT_EQ(vvi_result, vvi_reqd_r);
}

TEST(POWERSET, S_A) {
    std::string s_A = "abc";
    std::vector<std::vector<char>> vvc_result = powerset(s_A.begin(), s_A.end());
    std::vector<std::vector<char>> vvc_reqd_r = {{}, {'a'}, {'b'}, {'a', 'b'}, {'c'}, {'a', 'c'}, {'b', 'c'}, {'a', 'b', 'c'}};
    ASSERT_EQ(vvc_result, vvc_reqd_r);
}

TEST(ARGMAX, VI_A) {
    std::vector<int> vi_A = {2, 5, 8, 7, 4, 0, -1, 3};
    int i_result = argmax(vi_A.begin(), vi_A.end());
    ASSERT_EQ(i_result, 8);
}

TEST(ARGMAX, VL_A) {
    std::vector<long> vl_A = {913, -28973, 128, 12987, -13874, 18764, -29378, -23434, -9485, 2348};
    long l_result = argmax(vl_A.begin(), vl_A.end(), std::function<bool(long, long)>(Compare<long>::absolute));
    ASSERT_EQ(l_result, -29378);
}

TEST(ARGMAX, VS_A) {
    std::vector<std::string> vs_A = {"one", "two", "three", "four", "five", "six", "seventeen", "fourteen", "forty"};
    std::string s_result = argmax(vs_A.begin(), vs_A.end(), std::function<bool(std::string, std::string)>(Compare<std::string>::length));
    ASSERT_EQ(s_result, "seventeen");
}

TEST(ARGMIN, VI_A) {
    std::vector<int> vi_A = {2, 5, 8, 7, 4, 0, -1, 3};
    int i_result = argmin(vi_A.begin(), vi_A.end());
    ASSERT_EQ(i_result, -1);
}

TEST(ARGMIN, VL_A) {
    std::vector<long> vl_A = {913, -28973, 128, 12987, -13874, 18764, -29378, -23434, -9485, 2348};
    long l_result = argmin(vl_A.begin(), vl_A.end(), std::function<bool(long, long)>(Compare<long>::absolute));
    ASSERT_EQ(l_result, 128);
}

TEST(ARGMIN, VS_A) {
    std::vector<std::string> vs_A = {"one", "two", "three", "four", "five", "six", "seventeen", "fourteen", "forty"};
    std::string s_result = argmin(vs_A.begin(), vs_A.end(), std::function<bool(std::string, std::string)>(Compare<std::string>::length));
    ASSERT_EQ(s_result, "one");
}

TEST(SHUFFLE, VI_A) {
    std::vector<int> vi_A = {1, 2, 3, 4};
    shuffle(vi_A.begin(), vi_A.end());
    std::vector<int> vi_result{3, 4, 2, 1};
    EXPECT_EQ(vi_A, vi_result);
}

TEST(SHUFFLE, VLL_A) {
    std::vector<long long> vll_A = {187263, 91827391, 2873};
    shuffle(vll_A.begin(), vll_A.end(), 9123U);
    std::vector<long long> vll_result{2873, 187263, 91827391};
    EXPECT_EQ(vll_A, vll_result);
}

TEST(SHUFFLE, S_A) {
    std::string s_A = "iawhud";
    shuffle(s_A.begin(), s_A.end(), 42U);
    EXPECT_EQ(s_A, "awhudi");
}

TEST(ARGMAX_RANDOM_TIE, VI_A) {
    std::vector<int> vi_A = {2, 5, 8, 7, 4, 0, -1, 3};
    int i_result = argmax_random_tie(vi_A.begin(), vi_A.end());
    EXPECT_EQ(i_result, 8);
}

TEST(ARGMAX_RANDOM_TIE, VL_A) {
    std::vector<long> vl_A = {913, -28973, 128, 12987, -13874, 18764, -29378, -23434, -9485, 2348};
    long l_result = argmax_random_tie(vl_A.begin(), vl_A.end(), std::function<bool(long, long)>(Compare<long>::absolute));
    EXPECT_EQ(l_result, -29378);
}

TEST(ARGMAX_RANDOM_TIE, VS_A) {
    std::vector<std::string> vs_A = {"one", "two", "three", "four", "five", "six", "sixteen", "fifteen", "forty"};
    std::string s_result = argmax_random_tie(vs_A.begin(), vs_A.end(), std::function<bool(std::string, std::string)>(Compare<std::string>::length));
    EXPECT_EQ(s_result, "fifteen");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}