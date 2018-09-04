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

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}