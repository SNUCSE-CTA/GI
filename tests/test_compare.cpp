#include <gtest/gtest.h>
#include "compare.h"

TEST(compare_test, compare_test_isomorphic_1) {
    bool isomorphic;
    double processTime;
    int ret = compare("./input/lcc_hprd.igraph", "./input/sfl_lcc_hprd.igraph", &isomorphic, &processTime);
    ASSERT_EQ(1, ret);
    EXPECT_TRUE(isomorphic);
}
