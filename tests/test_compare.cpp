#include <gtest/gtest.h>
#include "compare.h"

TEST(compare_test, compare_test_isomorphic_1) {
    bool isomorphic;
    double processTime;
    int ret = compare("./input/lcc_hprd.igraph", "./input/sfl_lcc_hprd.igraph", &isomorphic, &processTime);
    ASSERT_EQ(1, ret);
    EXPECT_TRUE(isomorphic);
}

TEST(compare_test, compare_test_isomorphic_2) {
    bool isomorphic;
    double processTime;
    int ret = compare("./input/lcc_hprd.igraph", "./input/sfl_lcc_human.igraph", &isomorphic, &processTime);
    ASSERT_EQ(1, ret);
    EXPECT_FALSE(isomorphic);
}

TEST(compare_test, compare_test_isomorphic_3) {
    bool isomorphic;
    double processTime;
    int ret = compare("./input/lcc_hprd.igraph", "./input/non_existed.igraph", &isomorphic, &processTime);
    EXPECT_EQ(0, ret);
}
