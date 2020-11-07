#include <gtest/gtest.h>
#include "compare.h"

TEST(compare_test, compare_test_isomorphic_1) {
    bool isomorphic;
    double processTime;
    int ret = compare("./input/lcc_yeast.igraph", "./input/sfl_lcc_yeast.igraph", &isomorphic, &processTime);
    ASSERT_EQ(1, ret);
    EXPECT_TRUE(isomorphic);
}

TEST(compare_test, compare_test_isomorphic_2) {
    bool isomorphic;
    double processTime;
    int ret = compare("./input/lcc_hprd.igraph", "./input/sfl_lcc_hprd.igraph", &isomorphic, &processTime);
    ASSERT_EQ(1, ret);
    EXPECT_TRUE(isomorphic);
}

TEST(compare_test, compare_test_isomorphic_3) {
    bool isomorphic;
    double processTime;
    int ret = compare("./input/lcc_human.igraph", "./input/sfl_lcc_human.igraph", &isomorphic, &processTime);
    ASSERT_EQ(1, ret);
    EXPECT_TRUE(isomorphic);
}

TEST(compare_test, compare_test_nonisomorphic_1) {
    bool isomorphic;
    double processTime;
    int ret = compare("./input/lcc_hprd.igraph", "./input/sfl_lcc_human.igraph", &isomorphic, &processTime);
    ASSERT_EQ(1, ret);
    EXPECT_FALSE(isomorphic);
}

TEST(compare_test, compare_test_fail_1) {
    bool isomorphic;
    double processTime;
    int ret = compare("./input/lcc_hprd.igraph", "./input/non_existed.igraph", &isomorphic, &processTime);
    EXPECT_EQ(0, ret);
}

TEST(compare_test_small, compare_test_isomorphic_0_0_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_0.igraph", "./input/sfl_lcc_0_0_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_0_0_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_0.igraph", "./input/sfl_lcc_0_0_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_0_0_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_0.igraph", "./input/sfl_lcc_0_0_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_0_0_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_0.igraph", "./input/sfl_lcc_0_0_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_0_0_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_0.igraph", "./input/sfl_lcc_0_0_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_0_1_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_1.igraph", "./input/sfl_lcc_0_1_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_0_1_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_1.igraph", "./input/sfl_lcc_0_1_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_0_1_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_1.igraph", "./input/sfl_lcc_0_1_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_0_1_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_1.igraph", "./input/sfl_lcc_0_1_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_0_1_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_1.igraph", "./input/sfl_lcc_0_1_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_0_2_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_2.igraph", "./input/sfl_lcc_0_2_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_0_2_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_2.igraph", "./input/sfl_lcc_0_2_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_0_2_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_2.igraph", "./input/sfl_lcc_0_2_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_0_2_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_2.igraph", "./input/sfl_lcc_0_2_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_0_2_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_2.igraph", "./input/sfl_lcc_0_2_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_0_3_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_3.igraph", "./input/sfl_lcc_0_3_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_0_3_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_3.igraph", "./input/sfl_lcc_0_3_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_0_3_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_3.igraph", "./input/sfl_lcc_0_3_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_0_3_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_3.igraph", "./input/sfl_lcc_0_3_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_0_3_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_3.igraph", "./input/sfl_lcc_0_3_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_0_4_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_4.igraph", "./input/sfl_lcc_0_4_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_0_4_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_4.igraph", "./input/sfl_lcc_0_4_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_0_4_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_4.igraph", "./input/sfl_lcc_0_4_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_0_4_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_4.igraph", "./input/sfl_lcc_0_4_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_0_4_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_4.igraph", "./input/sfl_lcc_0_4_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_0_5_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_5.igraph", "./input/sfl_lcc_0_5_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_0_5_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_5.igraph", "./input/sfl_lcc_0_5_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_0_5_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_5.igraph", "./input/sfl_lcc_0_5_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_0_5_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_5.igraph", "./input/sfl_lcc_0_5_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_0_5_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_5.igraph", "./input/sfl_lcc_0_5_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

/*
TEST(compare_test_small, compare_test_isomorphic_0_6_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_6.igraph", "./input/sfl_lcc_0_6_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_0_6_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_6.igraph", "./input/sfl_lcc_0_6_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_0_6_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_6.igraph", "./input/sfl_lcc_0_6_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_0_6_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_6.igraph", "./input/sfl_lcc_0_6_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_0_6_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_6.igraph", "./input/sfl_lcc_0_6_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_0_7_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_7.igraph", "./input/sfl_lcc_0_7_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_0_7_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_7.igraph", "./input/sfl_lcc_0_7_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_0_7_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_7.igraph", "./input/sfl_lcc_0_7_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_0_7_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_7.igraph", "./input/sfl_lcc_0_7_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_0_7_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_7.igraph", "./input/sfl_lcc_0_7_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_0_8_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_8.igraph", "./input/sfl_lcc_0_8_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_0_8_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_8.igraph", "./input/sfl_lcc_0_8_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_0_8_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_8.igraph", "./input/sfl_lcc_0_8_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_0_8_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_8.igraph", "./input/sfl_lcc_0_8_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_0_8_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_8.igraph", "./input/sfl_lcc_0_8_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_0_9_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_9.igraph", "./input/sfl_lcc_0_9_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_0_9_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_9.igraph", "./input/sfl_lcc_0_9_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_0_9_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_9.igraph", "./input/sfl_lcc_0_9_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_0_9_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_9.igraph", "./input/sfl_lcc_0_9_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_0_9_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_9.igraph", "./input/sfl_lcc_0_9_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_1_0_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_0.igraph", "./input/sfl_lcc_1_0_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_1_0_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_0.igraph", "./input/sfl_lcc_1_0_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_1_0_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_0.igraph", "./input/sfl_lcc_1_0_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_1_0_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_0.igraph", "./input/sfl_lcc_1_0_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_1_0_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_0.igraph", "./input/sfl_lcc_1_0_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_1_1_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_1.igraph", "./input/sfl_lcc_1_1_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_1_1_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_1.igraph", "./input/sfl_lcc_1_1_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_1_1_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_1.igraph", "./input/sfl_lcc_1_1_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_1_1_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_1.igraph", "./input/sfl_lcc_1_1_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_1_1_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_1.igraph", "./input/sfl_lcc_1_1_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_1_2_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_2.igraph", "./input/sfl_lcc_1_2_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_1_2_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_2.igraph", "./input/sfl_lcc_1_2_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_1_2_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_2.igraph", "./input/sfl_lcc_1_2_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_1_2_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_2.igraph", "./input/sfl_lcc_1_2_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_1_2_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_2.igraph", "./input/sfl_lcc_1_2_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_1_3_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_3.igraph", "./input/sfl_lcc_1_3_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_1_3_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_3.igraph", "./input/sfl_lcc_1_3_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_1_3_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_3.igraph", "./input/sfl_lcc_1_3_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_1_3_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_3.igraph", "./input/sfl_lcc_1_3_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_1_3_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_3.igraph", "./input/sfl_lcc_1_3_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_1_4_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_4.igraph", "./input/sfl_lcc_1_4_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_1_4_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_4.igraph", "./input/sfl_lcc_1_4_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_1_4_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_4.igraph", "./input/sfl_lcc_1_4_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_1_4_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_4.igraph", "./input/sfl_lcc_1_4_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_1_4_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_4.igraph", "./input/sfl_lcc_1_4_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_1_5_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_5.igraph", "./input/sfl_lcc_1_5_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_1_5_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_5.igraph", "./input/sfl_lcc_1_5_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_1_5_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_5.igraph", "./input/sfl_lcc_1_5_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_1_5_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_5.igraph", "./input/sfl_lcc_1_5_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_1_5_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_5.igraph", "./input/sfl_lcc_1_5_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_1_6_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_6.igraph", "./input/sfl_lcc_1_6_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_1_6_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_6.igraph", "./input/sfl_lcc_1_6_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_1_6_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_6.igraph", "./input/sfl_lcc_1_6_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_1_6_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_6.igraph", "./input/sfl_lcc_1_6_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_1_6_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_6.igraph", "./input/sfl_lcc_1_6_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_1_7_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_7.igraph", "./input/sfl_lcc_1_7_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_1_7_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_7.igraph", "./input/sfl_lcc_1_7_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_1_7_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_7.igraph", "./input/sfl_lcc_1_7_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_1_7_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_7.igraph", "./input/sfl_lcc_1_7_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_1_7_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_7.igraph", "./input/sfl_lcc_1_7_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_1_8_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_8.igraph", "./input/sfl_lcc_1_8_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_1_8_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_8.igraph", "./input/sfl_lcc_1_8_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_1_8_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_8.igraph", "./input/sfl_lcc_1_8_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_1_8_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_8.igraph", "./input/sfl_lcc_1_8_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_1_8_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_8.igraph", "./input/sfl_lcc_1_8_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_1_9_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_9.igraph", "./input/sfl_lcc_1_9_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_1_9_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_9.igraph", "./input/sfl_lcc_1_9_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_1_9_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_9.igraph", "./input/sfl_lcc_1_9_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_1_9_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_9.igraph", "./input/sfl_lcc_1_9_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_1_9_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_9.igraph", "./input/sfl_lcc_1_9_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_2_0_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_0.igraph", "./input/sfl_lcc_2_0_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_2_0_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_0.igraph", "./input/sfl_lcc_2_0_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_2_0_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_0.igraph", "./input/sfl_lcc_2_0_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_2_0_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_0.igraph", "./input/sfl_lcc_2_0_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_2_0_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_0.igraph", "./input/sfl_lcc_2_0_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_2_1_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_1.igraph", "./input/sfl_lcc_2_1_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_2_1_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_1.igraph", "./input/sfl_lcc_2_1_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_2_1_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_1.igraph", "./input/sfl_lcc_2_1_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_2_1_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_1.igraph", "./input/sfl_lcc_2_1_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_2_1_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_1.igraph", "./input/sfl_lcc_2_1_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_2_2_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_2.igraph", "./input/sfl_lcc_2_2_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_2_2_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_2.igraph", "./input/sfl_lcc_2_2_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_2_2_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_2.igraph", "./input/sfl_lcc_2_2_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_2_2_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_2.igraph", "./input/sfl_lcc_2_2_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_2_2_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_2.igraph", "./input/sfl_lcc_2_2_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_2_3_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_3.igraph", "./input/sfl_lcc_2_3_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_2_3_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_3.igraph", "./input/sfl_lcc_2_3_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_2_3_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_3.igraph", "./input/sfl_lcc_2_3_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_2_3_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_3.igraph", "./input/sfl_lcc_2_3_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_2_3_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_3.igraph", "./input/sfl_lcc_2_3_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_2_4_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_4.igraph", "./input/sfl_lcc_2_4_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_2_4_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_4.igraph", "./input/sfl_lcc_2_4_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_2_4_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_4.igraph", "./input/sfl_lcc_2_4_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_2_4_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_4.igraph", "./input/sfl_lcc_2_4_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_2_4_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_4.igraph", "./input/sfl_lcc_2_4_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_2_5_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_5.igraph", "./input/sfl_lcc_2_5_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_2_5_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_5.igraph", "./input/sfl_lcc_2_5_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_2_5_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_5.igraph", "./input/sfl_lcc_2_5_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_2_5_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_5.igraph", "./input/sfl_lcc_2_5_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_2_5_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_5.igraph", "./input/sfl_lcc_2_5_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_2_6_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_6.igraph", "./input/sfl_lcc_2_6_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_2_6_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_6.igraph", "./input/sfl_lcc_2_6_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_2_6_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_6.igraph", "./input/sfl_lcc_2_6_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_2_6_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_6.igraph", "./input/sfl_lcc_2_6_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_2_6_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_6.igraph", "./input/sfl_lcc_2_6_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_2_7_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_7.igraph", "./input/sfl_lcc_2_7_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_2_7_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_7.igraph", "./input/sfl_lcc_2_7_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_2_7_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_7.igraph", "./input/sfl_lcc_2_7_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_2_7_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_7.igraph", "./input/sfl_lcc_2_7_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_2_7_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_7.igraph", "./input/sfl_lcc_2_7_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_2_8_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_8.igraph", "./input/sfl_lcc_2_8_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_2_8_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_8.igraph", "./input/sfl_lcc_2_8_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_2_8_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_8.igraph", "./input/sfl_lcc_2_8_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_2_8_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_8.igraph", "./input/sfl_lcc_2_8_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_2_8_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_8.igraph", "./input/sfl_lcc_2_8_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_2_9_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_9.igraph", "./input/sfl_lcc_2_9_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_2_9_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_9.igraph", "./input/sfl_lcc_2_9_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_2_9_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_9.igraph", "./input/sfl_lcc_2_9_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_2_9_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_9.igraph", "./input/sfl_lcc_2_9_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_2_9_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_9.igraph", "./input/sfl_lcc_2_9_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_3_0_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_0.igraph", "./input/sfl_lcc_3_0_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_3_0_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_0.igraph", "./input/sfl_lcc_3_0_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_3_0_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_0.igraph", "./input/sfl_lcc_3_0_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_3_0_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_0.igraph", "./input/sfl_lcc_3_0_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_3_0_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_0.igraph", "./input/sfl_lcc_3_0_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_3_1_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_1.igraph", "./input/sfl_lcc_3_1_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_3_1_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_1.igraph", "./input/sfl_lcc_3_1_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_3_1_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_1.igraph", "./input/sfl_lcc_3_1_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_3_1_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_1.igraph", "./input/sfl_lcc_3_1_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_3_1_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_1.igraph", "./input/sfl_lcc_3_1_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_3_2_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_2.igraph", "./input/sfl_lcc_3_2_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_3_2_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_2.igraph", "./input/sfl_lcc_3_2_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_3_2_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_2.igraph", "./input/sfl_lcc_3_2_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_3_2_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_2.igraph", "./input/sfl_lcc_3_2_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_3_2_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_2.igraph", "./input/sfl_lcc_3_2_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_3_3_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_3.igraph", "./input/sfl_lcc_3_3_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_3_3_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_3.igraph", "./input/sfl_lcc_3_3_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_3_3_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_3.igraph", "./input/sfl_lcc_3_3_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_3_3_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_3.igraph", "./input/sfl_lcc_3_3_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_3_3_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_3.igraph", "./input/sfl_lcc_3_3_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_3_4_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_4.igraph", "./input/sfl_lcc_3_4_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_3_4_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_4.igraph", "./input/sfl_lcc_3_4_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_3_4_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_4.igraph", "./input/sfl_lcc_3_4_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_3_4_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_4.igraph", "./input/sfl_lcc_3_4_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_3_4_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_4.igraph", "./input/sfl_lcc_3_4_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_3_5_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_5.igraph", "./input/sfl_lcc_3_5_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_3_5_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_5.igraph", "./input/sfl_lcc_3_5_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_3_5_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_5.igraph", "./input/sfl_lcc_3_5_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_3_5_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_5.igraph", "./input/sfl_lcc_3_5_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_3_5_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_5.igraph", "./input/sfl_lcc_3_5_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_3_6_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_6.igraph", "./input/sfl_lcc_3_6_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_3_6_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_6.igraph", "./input/sfl_lcc_3_6_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_3_6_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_6.igraph", "./input/sfl_lcc_3_6_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_3_6_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_6.igraph", "./input/sfl_lcc_3_6_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_3_6_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_6.igraph", "./input/sfl_lcc_3_6_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_3_7_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_7.igraph", "./input/sfl_lcc_3_7_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_3_7_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_7.igraph", "./input/sfl_lcc_3_7_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_3_7_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_7.igraph", "./input/sfl_lcc_3_7_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_3_7_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_7.igraph", "./input/sfl_lcc_3_7_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_3_7_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_7.igraph", "./input/sfl_lcc_3_7_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_3_8_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_8.igraph", "./input/sfl_lcc_3_8_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_3_8_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_8.igraph", "./input/sfl_lcc_3_8_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_3_8_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_8.igraph", "./input/sfl_lcc_3_8_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_3_8_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_8.igraph", "./input/sfl_lcc_3_8_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_3_8_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_8.igraph", "./input/sfl_lcc_3_8_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_3_9_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_9.igraph", "./input/sfl_lcc_3_9_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_3_9_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_9.igraph", "./input/sfl_lcc_3_9_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_3_9_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_9.igraph", "./input/sfl_lcc_3_9_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_3_9_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_9.igraph", "./input/sfl_lcc_3_9_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_3_9_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_9.igraph", "./input/sfl_lcc_3_9_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_4_0_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_0.igraph", "./input/sfl_lcc_4_0_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_4_0_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_0.igraph", "./input/sfl_lcc_4_0_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_4_0_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_0.igraph", "./input/sfl_lcc_4_0_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_4_0_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_0.igraph", "./input/sfl_lcc_4_0_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_4_0_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_0.igraph", "./input/sfl_lcc_4_0_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_4_1_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_1.igraph", "./input/sfl_lcc_4_1_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_4_1_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_1.igraph", "./input/sfl_lcc_4_1_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_4_1_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_1.igraph", "./input/sfl_lcc_4_1_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_4_1_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_1.igraph", "./input/sfl_lcc_4_1_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_4_1_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_1.igraph", "./input/sfl_lcc_4_1_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_4_2_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_2.igraph", "./input/sfl_lcc_4_2_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_4_2_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_2.igraph", "./input/sfl_lcc_4_2_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_4_2_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_2.igraph", "./input/sfl_lcc_4_2_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_4_2_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_2.igraph", "./input/sfl_lcc_4_2_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_4_2_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_2.igraph", "./input/sfl_lcc_4_2_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_4_3_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_3.igraph", "./input/sfl_lcc_4_3_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_4_3_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_3.igraph", "./input/sfl_lcc_4_3_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_4_3_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_3.igraph", "./input/sfl_lcc_4_3_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_4_3_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_3.igraph", "./input/sfl_lcc_4_3_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_4_3_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_3.igraph", "./input/sfl_lcc_4_3_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_4_4_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_4.igraph", "./input/sfl_lcc_4_4_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_4_4_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_4.igraph", "./input/sfl_lcc_4_4_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_4_4_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_4.igraph", "./input/sfl_lcc_4_4_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_4_4_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_4.igraph", "./input/sfl_lcc_4_4_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_4_4_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_4.igraph", "./input/sfl_lcc_4_4_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_4_5_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_5.igraph", "./input/sfl_lcc_4_5_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_4_5_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_5.igraph", "./input/sfl_lcc_4_5_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_4_5_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_5.igraph", "./input/sfl_lcc_4_5_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_4_5_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_5.igraph", "./input/sfl_lcc_4_5_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_4_5_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_5.igraph", "./input/sfl_lcc_4_5_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_4_6_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_6.igraph", "./input/sfl_lcc_4_6_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_4_6_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_6.igraph", "./input/sfl_lcc_4_6_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_4_6_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_6.igraph", "./input/sfl_lcc_4_6_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_4_6_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_6.igraph", "./input/sfl_lcc_4_6_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_4_6_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_6.igraph", "./input/sfl_lcc_4_6_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_4_7_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_7.igraph", "./input/sfl_lcc_4_7_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_4_7_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_7.igraph", "./input/sfl_lcc_4_7_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_4_7_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_7.igraph", "./input/sfl_lcc_4_7_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_4_7_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_7.igraph", "./input/sfl_lcc_4_7_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_4_7_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_7.igraph", "./input/sfl_lcc_4_7_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_4_8_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_8.igraph", "./input/sfl_lcc_4_8_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_4_8_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_8.igraph", "./input/sfl_lcc_4_8_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_4_8_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_8.igraph", "./input/sfl_lcc_4_8_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_4_8_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_8.igraph", "./input/sfl_lcc_4_8_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_4_8_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_8.igraph", "./input/sfl_lcc_4_8_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_4_9_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_9.igraph", "./input/sfl_lcc_4_9_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_4_9_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_9.igraph", "./input/sfl_lcc_4_9_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_4_9_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_9.igraph", "./input/sfl_lcc_4_9_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_4_9_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_9.igraph", "./input/sfl_lcc_4_9_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_4_9_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_9.igraph", "./input/sfl_lcc_4_9_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_19_0_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_0.igraph", "./input/sfl_lcc_19_0_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_19_0_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_0.igraph", "./input/sfl_lcc_19_0_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_19_0_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_0.igraph", "./input/sfl_lcc_19_0_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_19_0_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_0.igraph", "./input/sfl_lcc_19_0_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_19_0_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_0.igraph", "./input/sfl_lcc_19_0_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_19_1_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_1.igraph", "./input/sfl_lcc_19_1_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_19_1_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_1.igraph", "./input/sfl_lcc_19_1_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_19_1_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_1.igraph", "./input/sfl_lcc_19_1_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_19_1_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_1.igraph", "./input/sfl_lcc_19_1_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_19_1_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_1.igraph", "./input/sfl_lcc_19_1_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_19_2_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_2.igraph", "./input/sfl_lcc_19_2_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_19_2_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_2.igraph", "./input/sfl_lcc_19_2_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_19_2_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_2.igraph", "./input/sfl_lcc_19_2_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_19_2_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_2.igraph", "./input/sfl_lcc_19_2_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_19_2_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_2.igraph", "./input/sfl_lcc_19_2_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_19_3_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_3.igraph", "./input/sfl_lcc_19_3_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_19_3_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_3.igraph", "./input/sfl_lcc_19_3_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_19_3_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_3.igraph", "./input/sfl_lcc_19_3_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_19_3_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_3.igraph", "./input/sfl_lcc_19_3_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_19_3_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_3.igraph", "./input/sfl_lcc_19_3_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_19_4_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_4.igraph", "./input/sfl_lcc_19_4_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_19_4_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_4.igraph", "./input/sfl_lcc_19_4_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_19_4_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_4.igraph", "./input/sfl_lcc_19_4_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_19_4_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_4.igraph", "./input/sfl_lcc_19_4_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_19_4_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_4.igraph", "./input/sfl_lcc_19_4_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_19_5_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_5.igraph", "./input/sfl_lcc_19_5_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_19_5_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_5.igraph", "./input/sfl_lcc_19_5_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_19_5_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_5.igraph", "./input/sfl_lcc_19_5_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_19_5_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_5.igraph", "./input/sfl_lcc_19_5_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_19_5_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_5.igraph", "./input/sfl_lcc_19_5_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_19_6_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_6.igraph", "./input/sfl_lcc_19_6_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_19_6_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_6.igraph", "./input/sfl_lcc_19_6_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_19_6_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_6.igraph", "./input/sfl_lcc_19_6_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_19_6_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_6.igraph", "./input/sfl_lcc_19_6_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_19_6_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_6.igraph", "./input/sfl_lcc_19_6_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_19_7_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_7.igraph", "./input/sfl_lcc_19_7_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_19_7_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_7.igraph", "./input/sfl_lcc_19_7_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_19_7_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_7.igraph", "./input/sfl_lcc_19_7_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_19_7_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_7.igraph", "./input/sfl_lcc_19_7_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_19_7_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_7.igraph", "./input/sfl_lcc_19_7_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_19_8_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_8.igraph", "./input/sfl_lcc_19_8_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_19_8_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_8.igraph", "./input/sfl_lcc_19_8_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_19_8_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_8.igraph", "./input/sfl_lcc_19_8_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_19_8_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_8.igraph", "./input/sfl_lcc_19_8_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_19_8_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_8.igraph", "./input/sfl_lcc_19_8_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_19_9_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_9.igraph", "./input/sfl_lcc_19_9_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_19_9_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_9.igraph", "./input/sfl_lcc_19_9_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_19_9_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_9.igraph", "./input/sfl_lcc_19_9_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_19_9_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_9.igraph", "./input/sfl_lcc_19_9_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_19_9_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_9.igraph", "./input/sfl_lcc_19_9_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_20_0_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_0.igraph", "./input/sfl_lcc_20_0_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_20_0_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_0.igraph", "./input/sfl_lcc_20_0_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_20_0_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_0.igraph", "./input/sfl_lcc_20_0_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_20_0_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_0.igraph", "./input/sfl_lcc_20_0_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_20_0_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_0.igraph", "./input/sfl_lcc_20_0_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_20_1_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_1.igraph", "./input/sfl_lcc_20_1_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_20_1_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_1.igraph", "./input/sfl_lcc_20_1_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_20_1_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_1.igraph", "./input/sfl_lcc_20_1_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_20_1_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_1.igraph", "./input/sfl_lcc_20_1_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_20_1_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_1.igraph", "./input/sfl_lcc_20_1_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_20_2_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_2.igraph", "./input/sfl_lcc_20_2_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_20_2_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_2.igraph", "./input/sfl_lcc_20_2_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_20_2_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_2.igraph", "./input/sfl_lcc_20_2_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_20_2_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_2.igraph", "./input/sfl_lcc_20_2_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_20_2_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_2.igraph", "./input/sfl_lcc_20_2_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_20_3_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_3.igraph", "./input/sfl_lcc_20_3_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_20_3_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_3.igraph", "./input/sfl_lcc_20_3_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_20_3_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_3.igraph", "./input/sfl_lcc_20_3_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_20_3_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_3.igraph", "./input/sfl_lcc_20_3_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_20_3_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_3.igraph", "./input/sfl_lcc_20_3_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_20_4_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_4.igraph", "./input/sfl_lcc_20_4_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_20_4_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_4.igraph", "./input/sfl_lcc_20_4_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_20_4_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_4.igraph", "./input/sfl_lcc_20_4_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_20_4_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_4.igraph", "./input/sfl_lcc_20_4_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_20_4_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_4.igraph", "./input/sfl_lcc_20_4_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_20_5_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_5.igraph", "./input/sfl_lcc_20_5_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_20_5_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_5.igraph", "./input/sfl_lcc_20_5_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_20_5_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_5.igraph", "./input/sfl_lcc_20_5_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_20_5_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_5.igraph", "./input/sfl_lcc_20_5_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_20_5_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_5.igraph", "./input/sfl_lcc_20_5_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_20_6_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_6.igraph", "./input/sfl_lcc_20_6_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_20_6_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_6.igraph", "./input/sfl_lcc_20_6_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_20_6_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_6.igraph", "./input/sfl_lcc_20_6_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_20_6_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_6.igraph", "./input/sfl_lcc_20_6_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_20_6_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_6.igraph", "./input/sfl_lcc_20_6_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_20_7_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_7.igraph", "./input/sfl_lcc_20_7_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_20_7_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_7.igraph", "./input/sfl_lcc_20_7_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_20_7_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_7.igraph", "./input/sfl_lcc_20_7_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_20_7_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_7.igraph", "./input/sfl_lcc_20_7_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_20_7_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_7.igraph", "./input/sfl_lcc_20_7_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_20_8_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_8.igraph", "./input/sfl_lcc_20_8_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_20_8_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_8.igraph", "./input/sfl_lcc_20_8_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_20_8_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_8.igraph", "./input/sfl_lcc_20_8_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_20_8_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_8.igraph", "./input/sfl_lcc_20_8_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_20_8_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_8.igraph", "./input/sfl_lcc_20_8_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_20_9_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_9.igraph", "./input/sfl_lcc_20_9_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_20_9_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_9.igraph", "./input/sfl_lcc_20_9_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_20_9_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_9.igraph", "./input/sfl_lcc_20_9_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_20_9_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_9.igraph", "./input/sfl_lcc_20_9_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_20_9_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_9.igraph", "./input/sfl_lcc_20_9_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_21_0_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_0.igraph", "./input/sfl_lcc_21_0_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_21_0_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_0.igraph", "./input/sfl_lcc_21_0_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_21_0_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_0.igraph", "./input/sfl_lcc_21_0_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_21_0_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_0.igraph", "./input/sfl_lcc_21_0_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_21_0_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_0.igraph", "./input/sfl_lcc_21_0_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_21_1_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_1.igraph", "./input/sfl_lcc_21_1_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_21_1_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_1.igraph", "./input/sfl_lcc_21_1_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_21_1_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_1.igraph", "./input/sfl_lcc_21_1_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_21_1_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_1.igraph", "./input/sfl_lcc_21_1_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_21_1_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_1.igraph", "./input/sfl_lcc_21_1_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_21_2_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_2.igraph", "./input/sfl_lcc_21_2_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_21_2_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_2.igraph", "./input/sfl_lcc_21_2_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_21_2_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_2.igraph", "./input/sfl_lcc_21_2_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_21_2_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_2.igraph", "./input/sfl_lcc_21_2_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_21_2_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_2.igraph", "./input/sfl_lcc_21_2_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_21_3_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_3.igraph", "./input/sfl_lcc_21_3_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_21_3_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_3.igraph", "./input/sfl_lcc_21_3_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_21_3_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_3.igraph", "./input/sfl_lcc_21_3_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_21_3_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_3.igraph", "./input/sfl_lcc_21_3_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_21_3_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_3.igraph", "./input/sfl_lcc_21_3_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_21_4_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_4.igraph", "./input/sfl_lcc_21_4_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_21_4_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_4.igraph", "./input/sfl_lcc_21_4_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_21_4_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_4.igraph", "./input/sfl_lcc_21_4_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_21_4_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_4.igraph", "./input/sfl_lcc_21_4_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_21_4_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_4.igraph", "./input/sfl_lcc_21_4_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_21_5_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_5.igraph", "./input/sfl_lcc_21_5_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_21_5_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_5.igraph", "./input/sfl_lcc_21_5_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_21_5_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_5.igraph", "./input/sfl_lcc_21_5_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_21_5_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_5.igraph", "./input/sfl_lcc_21_5_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_21_5_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_5.igraph", "./input/sfl_lcc_21_5_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_21_6_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_6.igraph", "./input/sfl_lcc_21_6_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_21_6_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_6.igraph", "./input/sfl_lcc_21_6_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_21_6_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_6.igraph", "./input/sfl_lcc_21_6_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_21_6_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_6.igraph", "./input/sfl_lcc_21_6_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_21_6_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_6.igraph", "./input/sfl_lcc_21_6_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_21_7_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_7.igraph", "./input/sfl_lcc_21_7_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_21_7_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_7.igraph", "./input/sfl_lcc_21_7_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_21_7_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_7.igraph", "./input/sfl_lcc_21_7_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_21_7_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_7.igraph", "./input/sfl_lcc_21_7_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_21_7_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_7.igraph", "./input/sfl_lcc_21_7_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_21_8_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_8.igraph", "./input/sfl_lcc_21_8_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_21_8_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_8.igraph", "./input/sfl_lcc_21_8_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_21_8_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_8.igraph", "./input/sfl_lcc_21_8_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_21_8_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_8.igraph", "./input/sfl_lcc_21_8_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_21_8_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_8.igraph", "./input/sfl_lcc_21_8_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_21_9_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_9.igraph", "./input/sfl_lcc_21_9_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_21_9_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_9.igraph", "./input/sfl_lcc_21_9_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_21_9_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_9.igraph", "./input/sfl_lcc_21_9_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_21_9_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_9.igraph", "./input/sfl_lcc_21_9_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_21_9_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_9.igraph", "./input/sfl_lcc_21_9_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_22_0_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_0.igraph", "./input/sfl_lcc_22_0_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_22_0_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_0.igraph", "./input/sfl_lcc_22_0_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_22_0_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_0.igraph", "./input/sfl_lcc_22_0_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_22_0_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_0.igraph", "./input/sfl_lcc_22_0_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_22_0_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_0.igraph", "./input/sfl_lcc_22_0_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_22_1_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_1.igraph", "./input/sfl_lcc_22_1_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_22_1_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_1.igraph", "./input/sfl_lcc_22_1_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_22_1_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_1.igraph", "./input/sfl_lcc_22_1_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_22_1_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_1.igraph", "./input/sfl_lcc_22_1_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_22_1_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_1.igraph", "./input/sfl_lcc_22_1_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_22_2_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_2.igraph", "./input/sfl_lcc_22_2_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_22_2_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_2.igraph", "./input/sfl_lcc_22_2_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_22_2_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_2.igraph", "./input/sfl_lcc_22_2_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_22_2_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_2.igraph", "./input/sfl_lcc_22_2_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_22_2_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_2.igraph", "./input/sfl_lcc_22_2_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_22_3_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_3.igraph", "./input/sfl_lcc_22_3_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_22_3_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_3.igraph", "./input/sfl_lcc_22_3_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_22_3_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_3.igraph", "./input/sfl_lcc_22_3_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_22_3_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_3.igraph", "./input/sfl_lcc_22_3_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_22_3_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_3.igraph", "./input/sfl_lcc_22_3_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_22_4_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_4.igraph", "./input/sfl_lcc_22_4_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_22_4_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_4.igraph", "./input/sfl_lcc_22_4_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_22_4_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_4.igraph", "./input/sfl_lcc_22_4_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_22_4_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_4.igraph", "./input/sfl_lcc_22_4_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_22_4_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_4.igraph", "./input/sfl_lcc_22_4_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_22_5_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_5.igraph", "./input/sfl_lcc_22_5_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_22_5_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_5.igraph", "./input/sfl_lcc_22_5_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_22_5_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_5.igraph", "./input/sfl_lcc_22_5_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_22_5_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_5.igraph", "./input/sfl_lcc_22_5_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_22_5_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_5.igraph", "./input/sfl_lcc_22_5_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_22_6_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_6.igraph", "./input/sfl_lcc_22_6_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_22_6_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_6.igraph", "./input/sfl_lcc_22_6_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_22_6_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_6.igraph", "./input/sfl_lcc_22_6_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_22_6_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_6.igraph", "./input/sfl_lcc_22_6_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_22_6_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_6.igraph", "./input/sfl_lcc_22_6_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_22_7_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_7.igraph", "./input/sfl_lcc_22_7_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_22_7_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_7.igraph", "./input/sfl_lcc_22_7_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_22_7_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_7.igraph", "./input/sfl_lcc_22_7_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_22_7_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_7.igraph", "./input/sfl_lcc_22_7_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_22_7_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_7.igraph", "./input/sfl_lcc_22_7_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_22_8_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_8.igraph", "./input/sfl_lcc_22_8_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_22_8_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_8.igraph", "./input/sfl_lcc_22_8_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_22_8_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_8.igraph", "./input/sfl_lcc_22_8_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_22_8_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_8.igraph", "./input/sfl_lcc_22_8_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_22_8_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_8.igraph", "./input/sfl_lcc_22_8_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_22_9_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_9.igraph", "./input/sfl_lcc_22_9_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_22_9_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_9.igraph", "./input/sfl_lcc_22_9_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_22_9_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_9.igraph", "./input/sfl_lcc_22_9_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_22_9_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_9.igraph", "./input/sfl_lcc_22_9_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}

TEST(compare_test_small, compare_test_isomorphic_22_9_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_9.igraph", "./input/sfl_lcc_22_9_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_TRUE(isomorphic);
}
*/

TEST(compare_test_small, compare_test_nonisomorphic_0_0_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_0.igraph", "./input/_sfl_lcc_0_0_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_0_0_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_0.igraph", "./input/_sfl_lcc_0_0_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_0_0_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_0.igraph", "./input/_sfl_lcc_0_0_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_0_0_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_0.igraph", "./input/_sfl_lcc_0_0_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_0_0_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_0.igraph", "./input/_sfl_lcc_0_0_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_0_1_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_1.igraph", "./input/_sfl_lcc_0_1_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_0_1_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_1.igraph", "./input/_sfl_lcc_0_1_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_0_1_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_1.igraph", "./input/_sfl_lcc_0_1_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_0_1_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_1.igraph", "./input/_sfl_lcc_0_1_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_0_1_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_1.igraph", "./input/_sfl_lcc_0_1_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_0_2_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_2.igraph", "./input/_sfl_lcc_0_2_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_0_2_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_2.igraph", "./input/_sfl_lcc_0_2_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_0_2_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_2.igraph", "./input/_sfl_lcc_0_2_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_0_2_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_2.igraph", "./input/_sfl_lcc_0_2_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_0_2_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_2.igraph", "./input/_sfl_lcc_0_2_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_0_3_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_3.igraph", "./input/_sfl_lcc_0_3_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_0_3_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_3.igraph", "./input/_sfl_lcc_0_3_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_0_3_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_3.igraph", "./input/_sfl_lcc_0_3_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_0_3_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_3.igraph", "./input/_sfl_lcc_0_3_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_0_3_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_3.igraph", "./input/_sfl_lcc_0_3_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_0_4_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_4.igraph", "./input/_sfl_lcc_0_4_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_0_4_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_4.igraph", "./input/_sfl_lcc_0_4_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_0_4_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_4.igraph", "./input/_sfl_lcc_0_4_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_0_4_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_4.igraph", "./input/_sfl_lcc_0_4_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_0_4_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_4.igraph", "./input/_sfl_lcc_0_4_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_0_5_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_5.igraph", "./input/_sfl_lcc_0_5_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_0_5_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_5.igraph", "./input/_sfl_lcc_0_5_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_0_5_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_5.igraph", "./input/_sfl_lcc_0_5_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_0_5_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_5.igraph", "./input/_sfl_lcc_0_5_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_0_5_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_5.igraph", "./input/_sfl_lcc_0_5_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

/*
TEST(compare_test_small, compare_test_nonisomorphic_0_6_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_6.igraph", "./input/_sfl_lcc_0_6_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_0_6_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_6.igraph", "./input/_sfl_lcc_0_6_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_0_6_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_6.igraph", "./input/_sfl_lcc_0_6_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_0_6_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_6.igraph", "./input/_sfl_lcc_0_6_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_0_6_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_6.igraph", "./input/_sfl_lcc_0_6_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_0_7_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_7.igraph", "./input/_sfl_lcc_0_7_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_0_7_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_7.igraph", "./input/_sfl_lcc_0_7_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_0_7_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_7.igraph", "./input/_sfl_lcc_0_7_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_0_7_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_7.igraph", "./input/_sfl_lcc_0_7_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_0_7_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_7.igraph", "./input/_sfl_lcc_0_7_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_0_8_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_8.igraph", "./input/_sfl_lcc_0_8_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_0_8_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_8.igraph", "./input/_sfl_lcc_0_8_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_0_8_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_8.igraph", "./input/_sfl_lcc_0_8_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_0_8_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_8.igraph", "./input/_sfl_lcc_0_8_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_0_8_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_8.igraph", "./input/_sfl_lcc_0_8_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_0_9_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_9.igraph", "./input/_sfl_lcc_0_9_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_0_9_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_9.igraph", "./input/_sfl_lcc_0_9_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_0_9_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_9.igraph", "./input/_sfl_lcc_0_9_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_0_9_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_9.igraph", "./input/_sfl_lcc_0_9_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_0_9_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_0_9.igraph", "./input/_sfl_lcc_0_9_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_1_0_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_0.igraph", "./input/_sfl_lcc_1_0_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_1_0_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_0.igraph", "./input/_sfl_lcc_1_0_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_1_0_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_0.igraph", "./input/_sfl_lcc_1_0_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_1_0_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_0.igraph", "./input/_sfl_lcc_1_0_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_1_0_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_0.igraph", "./input/_sfl_lcc_1_0_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_1_1_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_1.igraph", "./input/_sfl_lcc_1_1_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_1_1_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_1.igraph", "./input/_sfl_lcc_1_1_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_1_1_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_1.igraph", "./input/_sfl_lcc_1_1_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_1_1_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_1.igraph", "./input/_sfl_lcc_1_1_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_1_1_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_1.igraph", "./input/_sfl_lcc_1_1_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_1_2_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_2.igraph", "./input/_sfl_lcc_1_2_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_1_2_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_2.igraph", "./input/_sfl_lcc_1_2_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_1_2_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_2.igraph", "./input/_sfl_lcc_1_2_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_1_2_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_2.igraph", "./input/_sfl_lcc_1_2_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_1_2_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_2.igraph", "./input/_sfl_lcc_1_2_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_1_3_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_3.igraph", "./input/_sfl_lcc_1_3_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_1_3_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_3.igraph", "./input/_sfl_lcc_1_3_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_1_3_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_3.igraph", "./input/_sfl_lcc_1_3_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_1_3_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_3.igraph", "./input/_sfl_lcc_1_3_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_1_3_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_3.igraph", "./input/_sfl_lcc_1_3_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_1_4_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_4.igraph", "./input/_sfl_lcc_1_4_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_1_4_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_4.igraph", "./input/_sfl_lcc_1_4_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_1_4_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_4.igraph", "./input/_sfl_lcc_1_4_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_1_4_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_4.igraph", "./input/_sfl_lcc_1_4_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_1_4_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_4.igraph", "./input/_sfl_lcc_1_4_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_1_5_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_5.igraph", "./input/_sfl_lcc_1_5_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_1_5_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_5.igraph", "./input/_sfl_lcc_1_5_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_1_5_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_5.igraph", "./input/_sfl_lcc_1_5_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_1_5_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_5.igraph", "./input/_sfl_lcc_1_5_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_1_5_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_5.igraph", "./input/_sfl_lcc_1_5_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_1_6_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_6.igraph", "./input/_sfl_lcc_1_6_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_1_6_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_6.igraph", "./input/_sfl_lcc_1_6_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_1_6_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_6.igraph", "./input/_sfl_lcc_1_6_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_1_6_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_6.igraph", "./input/_sfl_lcc_1_6_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_1_6_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_6.igraph", "./input/_sfl_lcc_1_6_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_1_7_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_7.igraph", "./input/_sfl_lcc_1_7_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_1_7_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_7.igraph", "./input/_sfl_lcc_1_7_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_1_7_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_7.igraph", "./input/_sfl_lcc_1_7_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_1_7_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_7.igraph", "./input/_sfl_lcc_1_7_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_1_7_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_7.igraph", "./input/_sfl_lcc_1_7_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_1_8_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_8.igraph", "./input/_sfl_lcc_1_8_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_1_8_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_8.igraph", "./input/_sfl_lcc_1_8_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_1_8_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_8.igraph", "./input/_sfl_lcc_1_8_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_1_8_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_8.igraph", "./input/_sfl_lcc_1_8_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_1_8_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_8.igraph", "./input/_sfl_lcc_1_8_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_1_9_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_9.igraph", "./input/_sfl_lcc_1_9_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_1_9_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_9.igraph", "./input/_sfl_lcc_1_9_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_1_9_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_9.igraph", "./input/_sfl_lcc_1_9_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_1_9_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_9.igraph", "./input/_sfl_lcc_1_9_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_1_9_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_1_9.igraph", "./input/_sfl_lcc_1_9_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_2_0_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_0.igraph", "./input/_sfl_lcc_2_0_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_2_0_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_0.igraph", "./input/_sfl_lcc_2_0_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_2_0_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_0.igraph", "./input/_sfl_lcc_2_0_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_2_0_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_0.igraph", "./input/_sfl_lcc_2_0_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_2_0_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_0.igraph", "./input/_sfl_lcc_2_0_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_2_1_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_1.igraph", "./input/_sfl_lcc_2_1_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_2_1_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_1.igraph", "./input/_sfl_lcc_2_1_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_2_1_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_1.igraph", "./input/_sfl_lcc_2_1_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_2_1_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_1.igraph", "./input/_sfl_lcc_2_1_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_2_1_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_1.igraph", "./input/_sfl_lcc_2_1_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_2_2_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_2.igraph", "./input/_sfl_lcc_2_2_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_2_2_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_2.igraph", "./input/_sfl_lcc_2_2_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_2_2_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_2.igraph", "./input/_sfl_lcc_2_2_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_2_2_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_2.igraph", "./input/_sfl_lcc_2_2_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_2_2_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_2.igraph", "./input/_sfl_lcc_2_2_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_2_3_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_3.igraph", "./input/_sfl_lcc_2_3_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_2_3_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_3.igraph", "./input/_sfl_lcc_2_3_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_2_3_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_3.igraph", "./input/_sfl_lcc_2_3_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_2_3_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_3.igraph", "./input/_sfl_lcc_2_3_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_2_3_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_3.igraph", "./input/_sfl_lcc_2_3_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_2_4_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_4.igraph", "./input/_sfl_lcc_2_4_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_2_4_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_4.igraph", "./input/_sfl_lcc_2_4_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_2_4_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_4.igraph", "./input/_sfl_lcc_2_4_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_2_4_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_4.igraph", "./input/_sfl_lcc_2_4_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_2_4_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_4.igraph", "./input/_sfl_lcc_2_4_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_2_5_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_5.igraph", "./input/_sfl_lcc_2_5_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_2_5_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_5.igraph", "./input/_sfl_lcc_2_5_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_2_5_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_5.igraph", "./input/_sfl_lcc_2_5_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_2_5_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_5.igraph", "./input/_sfl_lcc_2_5_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_2_5_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_5.igraph", "./input/_sfl_lcc_2_5_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_2_6_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_6.igraph", "./input/_sfl_lcc_2_6_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_2_6_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_6.igraph", "./input/_sfl_lcc_2_6_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_2_6_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_6.igraph", "./input/_sfl_lcc_2_6_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_2_6_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_6.igraph", "./input/_sfl_lcc_2_6_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_2_6_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_6.igraph", "./input/_sfl_lcc_2_6_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_2_7_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_7.igraph", "./input/_sfl_lcc_2_7_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_2_7_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_7.igraph", "./input/_sfl_lcc_2_7_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_2_7_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_7.igraph", "./input/_sfl_lcc_2_7_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_2_7_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_7.igraph", "./input/_sfl_lcc_2_7_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_2_7_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_7.igraph", "./input/_sfl_lcc_2_7_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_2_8_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_8.igraph", "./input/_sfl_lcc_2_8_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_2_8_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_8.igraph", "./input/_sfl_lcc_2_8_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_2_8_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_8.igraph", "./input/_sfl_lcc_2_8_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_2_8_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_8.igraph", "./input/_sfl_lcc_2_8_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_2_8_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_8.igraph", "./input/_sfl_lcc_2_8_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_2_9_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_9.igraph", "./input/_sfl_lcc_2_9_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_2_9_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_9.igraph", "./input/_sfl_lcc_2_9_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_2_9_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_9.igraph", "./input/_sfl_lcc_2_9_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_2_9_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_9.igraph", "./input/_sfl_lcc_2_9_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_2_9_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_2_9.igraph", "./input/_sfl_lcc_2_9_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_3_0_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_0.igraph", "./input/_sfl_lcc_3_0_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_3_0_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_0.igraph", "./input/_sfl_lcc_3_0_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_3_0_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_0.igraph", "./input/_sfl_lcc_3_0_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_3_0_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_0.igraph", "./input/_sfl_lcc_3_0_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_3_0_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_0.igraph", "./input/_sfl_lcc_3_0_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_3_1_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_1.igraph", "./input/_sfl_lcc_3_1_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_3_1_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_1.igraph", "./input/_sfl_lcc_3_1_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_3_1_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_1.igraph", "./input/_sfl_lcc_3_1_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_3_1_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_1.igraph", "./input/_sfl_lcc_3_1_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_3_1_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_1.igraph", "./input/_sfl_lcc_3_1_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_3_2_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_2.igraph", "./input/_sfl_lcc_3_2_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_3_2_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_2.igraph", "./input/_sfl_lcc_3_2_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_3_2_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_2.igraph", "./input/_sfl_lcc_3_2_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_3_2_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_2.igraph", "./input/_sfl_lcc_3_2_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_3_2_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_2.igraph", "./input/_sfl_lcc_3_2_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_3_3_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_3.igraph", "./input/_sfl_lcc_3_3_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_3_3_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_3.igraph", "./input/_sfl_lcc_3_3_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_3_3_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_3.igraph", "./input/_sfl_lcc_3_3_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_3_3_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_3.igraph", "./input/_sfl_lcc_3_3_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_3_3_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_3.igraph", "./input/_sfl_lcc_3_3_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_3_4_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_4.igraph", "./input/_sfl_lcc_3_4_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_3_4_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_4.igraph", "./input/_sfl_lcc_3_4_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_3_4_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_4.igraph", "./input/_sfl_lcc_3_4_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_3_4_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_4.igraph", "./input/_sfl_lcc_3_4_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_3_4_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_4.igraph", "./input/_sfl_lcc_3_4_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_3_5_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_5.igraph", "./input/_sfl_lcc_3_5_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_3_5_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_5.igraph", "./input/_sfl_lcc_3_5_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_3_5_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_5.igraph", "./input/_sfl_lcc_3_5_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_3_5_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_5.igraph", "./input/_sfl_lcc_3_5_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_3_5_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_5.igraph", "./input/_sfl_lcc_3_5_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_3_6_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_6.igraph", "./input/_sfl_lcc_3_6_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_3_6_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_6.igraph", "./input/_sfl_lcc_3_6_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_3_6_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_6.igraph", "./input/_sfl_lcc_3_6_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_3_6_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_6.igraph", "./input/_sfl_lcc_3_6_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_3_6_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_6.igraph", "./input/_sfl_lcc_3_6_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_3_7_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_7.igraph", "./input/_sfl_lcc_3_7_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_3_7_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_7.igraph", "./input/_sfl_lcc_3_7_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_3_7_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_7.igraph", "./input/_sfl_lcc_3_7_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_3_7_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_7.igraph", "./input/_sfl_lcc_3_7_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_3_7_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_7.igraph", "./input/_sfl_lcc_3_7_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_3_8_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_8.igraph", "./input/_sfl_lcc_3_8_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_3_8_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_8.igraph", "./input/_sfl_lcc_3_8_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_3_8_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_8.igraph", "./input/_sfl_lcc_3_8_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_3_8_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_8.igraph", "./input/_sfl_lcc_3_8_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_3_8_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_8.igraph", "./input/_sfl_lcc_3_8_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_3_9_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_9.igraph", "./input/_sfl_lcc_3_9_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_3_9_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_9.igraph", "./input/_sfl_lcc_3_9_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_3_9_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_9.igraph", "./input/_sfl_lcc_3_9_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_3_9_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_9.igraph", "./input/_sfl_lcc_3_9_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_3_9_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_3_9.igraph", "./input/_sfl_lcc_3_9_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_4_0_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_0.igraph", "./input/_sfl_lcc_4_0_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_4_0_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_0.igraph", "./input/_sfl_lcc_4_0_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_4_0_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_0.igraph", "./input/_sfl_lcc_4_0_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_4_0_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_0.igraph", "./input/_sfl_lcc_4_0_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_4_0_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_0.igraph", "./input/_sfl_lcc_4_0_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_4_1_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_1.igraph", "./input/_sfl_lcc_4_1_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_4_1_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_1.igraph", "./input/_sfl_lcc_4_1_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_4_1_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_1.igraph", "./input/_sfl_lcc_4_1_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_4_1_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_1.igraph", "./input/_sfl_lcc_4_1_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_4_1_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_1.igraph", "./input/_sfl_lcc_4_1_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_4_2_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_2.igraph", "./input/_sfl_lcc_4_2_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_4_2_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_2.igraph", "./input/_sfl_lcc_4_2_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_4_2_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_2.igraph", "./input/_sfl_lcc_4_2_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_4_2_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_2.igraph", "./input/_sfl_lcc_4_2_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_4_2_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_2.igraph", "./input/_sfl_lcc_4_2_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_4_3_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_3.igraph", "./input/_sfl_lcc_4_3_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_4_3_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_3.igraph", "./input/_sfl_lcc_4_3_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_4_3_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_3.igraph", "./input/_sfl_lcc_4_3_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_4_3_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_3.igraph", "./input/_sfl_lcc_4_3_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_4_3_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_3.igraph", "./input/_sfl_lcc_4_3_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_4_4_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_4.igraph", "./input/_sfl_lcc_4_4_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_4_4_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_4.igraph", "./input/_sfl_lcc_4_4_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_4_4_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_4.igraph", "./input/_sfl_lcc_4_4_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_4_4_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_4.igraph", "./input/_sfl_lcc_4_4_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_4_4_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_4.igraph", "./input/_sfl_lcc_4_4_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_4_5_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_5.igraph", "./input/_sfl_lcc_4_5_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_4_5_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_5.igraph", "./input/_sfl_lcc_4_5_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_4_5_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_5.igraph", "./input/_sfl_lcc_4_5_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_4_5_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_5.igraph", "./input/_sfl_lcc_4_5_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_4_5_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_5.igraph", "./input/_sfl_lcc_4_5_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_4_6_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_6.igraph", "./input/_sfl_lcc_4_6_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_4_6_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_6.igraph", "./input/_sfl_lcc_4_6_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_4_6_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_6.igraph", "./input/_sfl_lcc_4_6_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_4_6_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_6.igraph", "./input/_sfl_lcc_4_6_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_4_6_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_6.igraph", "./input/_sfl_lcc_4_6_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_4_7_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_7.igraph", "./input/_sfl_lcc_4_7_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_4_7_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_7.igraph", "./input/_sfl_lcc_4_7_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_4_7_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_7.igraph", "./input/_sfl_lcc_4_7_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_4_7_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_7.igraph", "./input/_sfl_lcc_4_7_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_4_7_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_7.igraph", "./input/_sfl_lcc_4_7_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_4_8_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_8.igraph", "./input/_sfl_lcc_4_8_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_4_8_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_8.igraph", "./input/_sfl_lcc_4_8_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_4_8_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_8.igraph", "./input/_sfl_lcc_4_8_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_4_8_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_8.igraph", "./input/_sfl_lcc_4_8_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_4_8_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_8.igraph", "./input/_sfl_lcc_4_8_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_4_9_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_9.igraph", "./input/_sfl_lcc_4_9_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_4_9_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_9.igraph", "./input/_sfl_lcc_4_9_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_4_9_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_9.igraph", "./input/_sfl_lcc_4_9_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_4_9_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_9.igraph", "./input/_sfl_lcc_4_9_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_4_9_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_4_9.igraph", "./input/_sfl_lcc_4_9_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_19_0_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_0.igraph", "./input/_sfl_lcc_19_0_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_19_0_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_0.igraph", "./input/_sfl_lcc_19_0_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_19_0_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_0.igraph", "./input/_sfl_lcc_19_0_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_19_0_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_0.igraph", "./input/_sfl_lcc_19_0_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_19_0_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_0.igraph", "./input/_sfl_lcc_19_0_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_19_1_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_1.igraph", "./input/_sfl_lcc_19_1_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_19_1_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_1.igraph", "./input/_sfl_lcc_19_1_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_19_1_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_1.igraph", "./input/_sfl_lcc_19_1_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_19_1_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_1.igraph", "./input/_sfl_lcc_19_1_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_19_1_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_1.igraph", "./input/_sfl_lcc_19_1_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_19_2_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_2.igraph", "./input/_sfl_lcc_19_2_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_19_2_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_2.igraph", "./input/_sfl_lcc_19_2_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_19_2_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_2.igraph", "./input/_sfl_lcc_19_2_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_19_2_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_2.igraph", "./input/_sfl_lcc_19_2_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_19_2_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_2.igraph", "./input/_sfl_lcc_19_2_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_19_3_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_3.igraph", "./input/_sfl_lcc_19_3_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_19_3_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_3.igraph", "./input/_sfl_lcc_19_3_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_19_3_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_3.igraph", "./input/_sfl_lcc_19_3_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_19_3_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_3.igraph", "./input/_sfl_lcc_19_3_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_19_3_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_3.igraph", "./input/_sfl_lcc_19_3_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_19_4_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_4.igraph", "./input/_sfl_lcc_19_4_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_19_4_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_4.igraph", "./input/_sfl_lcc_19_4_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_19_4_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_4.igraph", "./input/_sfl_lcc_19_4_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_19_4_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_4.igraph", "./input/_sfl_lcc_19_4_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_19_4_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_4.igraph", "./input/_sfl_lcc_19_4_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_19_5_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_5.igraph", "./input/_sfl_lcc_19_5_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_19_5_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_5.igraph", "./input/_sfl_lcc_19_5_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_19_5_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_5.igraph", "./input/_sfl_lcc_19_5_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_19_5_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_5.igraph", "./input/_sfl_lcc_19_5_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_19_5_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_5.igraph", "./input/_sfl_lcc_19_5_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_19_6_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_6.igraph", "./input/_sfl_lcc_19_6_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_19_6_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_6.igraph", "./input/_sfl_lcc_19_6_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_19_6_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_6.igraph", "./input/_sfl_lcc_19_6_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_19_6_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_6.igraph", "./input/_sfl_lcc_19_6_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_19_6_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_6.igraph", "./input/_sfl_lcc_19_6_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_19_7_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_7.igraph", "./input/_sfl_lcc_19_7_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_19_7_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_7.igraph", "./input/_sfl_lcc_19_7_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_19_7_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_7.igraph", "./input/_sfl_lcc_19_7_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_19_7_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_7.igraph", "./input/_sfl_lcc_19_7_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_19_7_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_7.igraph", "./input/_sfl_lcc_19_7_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_19_8_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_8.igraph", "./input/_sfl_lcc_19_8_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_19_8_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_8.igraph", "./input/_sfl_lcc_19_8_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_19_8_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_8.igraph", "./input/_sfl_lcc_19_8_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_19_8_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_8.igraph", "./input/_sfl_lcc_19_8_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_19_8_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_8.igraph", "./input/_sfl_lcc_19_8_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_19_9_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_9.igraph", "./input/_sfl_lcc_19_9_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_19_9_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_9.igraph", "./input/_sfl_lcc_19_9_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_19_9_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_9.igraph", "./input/_sfl_lcc_19_9_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_19_9_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_9.igraph", "./input/_sfl_lcc_19_9_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_19_9_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_19_9.igraph", "./input/_sfl_lcc_19_9_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_20_0_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_0.igraph", "./input/_sfl_lcc_20_0_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_20_0_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_0.igraph", "./input/_sfl_lcc_20_0_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_20_0_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_0.igraph", "./input/_sfl_lcc_20_0_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_20_0_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_0.igraph", "./input/_sfl_lcc_20_0_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_20_0_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_0.igraph", "./input/_sfl_lcc_20_0_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_20_1_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_1.igraph", "./input/_sfl_lcc_20_1_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_20_1_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_1.igraph", "./input/_sfl_lcc_20_1_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_20_1_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_1.igraph", "./input/_sfl_lcc_20_1_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_20_1_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_1.igraph", "./input/_sfl_lcc_20_1_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_20_1_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_1.igraph", "./input/_sfl_lcc_20_1_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_20_2_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_2.igraph", "./input/_sfl_lcc_20_2_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_20_2_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_2.igraph", "./input/_sfl_lcc_20_2_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_20_2_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_2.igraph", "./input/_sfl_lcc_20_2_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_20_2_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_2.igraph", "./input/_sfl_lcc_20_2_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_20_2_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_2.igraph", "./input/_sfl_lcc_20_2_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_20_3_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_3.igraph", "./input/_sfl_lcc_20_3_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_20_3_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_3.igraph", "./input/_sfl_lcc_20_3_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_20_3_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_3.igraph", "./input/_sfl_lcc_20_3_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_20_3_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_3.igraph", "./input/_sfl_lcc_20_3_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_20_3_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_3.igraph", "./input/_sfl_lcc_20_3_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_20_4_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_4.igraph", "./input/_sfl_lcc_20_4_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_20_4_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_4.igraph", "./input/_sfl_lcc_20_4_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_20_4_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_4.igraph", "./input/_sfl_lcc_20_4_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_20_4_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_4.igraph", "./input/_sfl_lcc_20_4_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_20_4_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_4.igraph", "./input/_sfl_lcc_20_4_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_20_5_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_5.igraph", "./input/_sfl_lcc_20_5_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_20_5_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_5.igraph", "./input/_sfl_lcc_20_5_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_20_5_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_5.igraph", "./input/_sfl_lcc_20_5_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_20_5_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_5.igraph", "./input/_sfl_lcc_20_5_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_20_5_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_5.igraph", "./input/_sfl_lcc_20_5_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_20_6_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_6.igraph", "./input/_sfl_lcc_20_6_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_20_6_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_6.igraph", "./input/_sfl_lcc_20_6_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_20_6_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_6.igraph", "./input/_sfl_lcc_20_6_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_20_6_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_6.igraph", "./input/_sfl_lcc_20_6_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_20_6_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_6.igraph", "./input/_sfl_lcc_20_6_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_20_7_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_7.igraph", "./input/_sfl_lcc_20_7_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_20_7_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_7.igraph", "./input/_sfl_lcc_20_7_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_20_7_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_7.igraph", "./input/_sfl_lcc_20_7_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_20_7_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_7.igraph", "./input/_sfl_lcc_20_7_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_20_7_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_7.igraph", "./input/_sfl_lcc_20_7_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_20_8_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_8.igraph", "./input/_sfl_lcc_20_8_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_20_8_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_8.igraph", "./input/_sfl_lcc_20_8_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_20_8_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_8.igraph", "./input/_sfl_lcc_20_8_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_20_8_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_8.igraph", "./input/_sfl_lcc_20_8_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_20_8_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_8.igraph", "./input/_sfl_lcc_20_8_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_20_9_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_9.igraph", "./input/_sfl_lcc_20_9_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_20_9_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_9.igraph", "./input/_sfl_lcc_20_9_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_20_9_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_9.igraph", "./input/_sfl_lcc_20_9_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_20_9_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_9.igraph", "./input/_sfl_lcc_20_9_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_20_9_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_20_9.igraph", "./input/_sfl_lcc_20_9_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_21_0_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_0.igraph", "./input/_sfl_lcc_21_0_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_21_0_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_0.igraph", "./input/_sfl_lcc_21_0_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_21_0_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_0.igraph", "./input/_sfl_lcc_21_0_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_21_0_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_0.igraph", "./input/_sfl_lcc_21_0_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_21_0_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_0.igraph", "./input/_sfl_lcc_21_0_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_21_1_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_1.igraph", "./input/_sfl_lcc_21_1_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_21_1_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_1.igraph", "./input/_sfl_lcc_21_1_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_21_1_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_1.igraph", "./input/_sfl_lcc_21_1_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_21_1_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_1.igraph", "./input/_sfl_lcc_21_1_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_21_1_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_1.igraph", "./input/_sfl_lcc_21_1_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_21_2_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_2.igraph", "./input/_sfl_lcc_21_2_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_21_2_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_2.igraph", "./input/_sfl_lcc_21_2_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_21_2_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_2.igraph", "./input/_sfl_lcc_21_2_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_21_2_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_2.igraph", "./input/_sfl_lcc_21_2_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_21_2_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_2.igraph", "./input/_sfl_lcc_21_2_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_21_3_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_3.igraph", "./input/_sfl_lcc_21_3_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_21_3_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_3.igraph", "./input/_sfl_lcc_21_3_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_21_3_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_3.igraph", "./input/_sfl_lcc_21_3_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_21_3_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_3.igraph", "./input/_sfl_lcc_21_3_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_21_3_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_3.igraph", "./input/_sfl_lcc_21_3_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_21_4_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_4.igraph", "./input/_sfl_lcc_21_4_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_21_4_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_4.igraph", "./input/_sfl_lcc_21_4_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_21_4_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_4.igraph", "./input/_sfl_lcc_21_4_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_21_4_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_4.igraph", "./input/_sfl_lcc_21_4_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_21_4_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_4.igraph", "./input/_sfl_lcc_21_4_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_21_5_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_5.igraph", "./input/_sfl_lcc_21_5_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_21_5_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_5.igraph", "./input/_sfl_lcc_21_5_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_21_5_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_5.igraph", "./input/_sfl_lcc_21_5_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_21_5_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_5.igraph", "./input/_sfl_lcc_21_5_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_21_5_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_5.igraph", "./input/_sfl_lcc_21_5_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_21_6_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_6.igraph", "./input/_sfl_lcc_21_6_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_21_6_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_6.igraph", "./input/_sfl_lcc_21_6_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_21_6_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_6.igraph", "./input/_sfl_lcc_21_6_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_21_6_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_6.igraph", "./input/_sfl_lcc_21_6_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_21_6_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_6.igraph", "./input/_sfl_lcc_21_6_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_21_7_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_7.igraph", "./input/_sfl_lcc_21_7_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_21_7_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_7.igraph", "./input/_sfl_lcc_21_7_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_21_7_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_7.igraph", "./input/_sfl_lcc_21_7_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_21_7_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_7.igraph", "./input/_sfl_lcc_21_7_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_21_7_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_7.igraph", "./input/_sfl_lcc_21_7_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_21_8_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_8.igraph", "./input/_sfl_lcc_21_8_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_21_8_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_8.igraph", "./input/_sfl_lcc_21_8_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_21_8_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_8.igraph", "./input/_sfl_lcc_21_8_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_21_8_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_8.igraph", "./input/_sfl_lcc_21_8_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_21_8_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_8.igraph", "./input/_sfl_lcc_21_8_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_21_9_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_9.igraph", "./input/_sfl_lcc_21_9_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_21_9_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_9.igraph", "./input/_sfl_lcc_21_9_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_21_9_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_9.igraph", "./input/_sfl_lcc_21_9_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_21_9_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_9.igraph", "./input/_sfl_lcc_21_9_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_21_9_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_21_9.igraph", "./input/_sfl_lcc_21_9_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_22_0_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_0.igraph", "./input/_sfl_lcc_22_0_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_22_0_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_0.igraph", "./input/_sfl_lcc_22_0_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_22_0_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_0.igraph", "./input/_sfl_lcc_22_0_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_22_0_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_0.igraph", "./input/_sfl_lcc_22_0_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_22_0_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_0.igraph", "./input/_sfl_lcc_22_0_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_22_1_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_1.igraph", "./input/_sfl_lcc_22_1_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_22_1_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_1.igraph", "./input/_sfl_lcc_22_1_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_22_1_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_1.igraph", "./input/_sfl_lcc_22_1_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_22_1_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_1.igraph", "./input/_sfl_lcc_22_1_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_22_1_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_1.igraph", "./input/_sfl_lcc_22_1_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_22_2_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_2.igraph", "./input/_sfl_lcc_22_2_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_22_2_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_2.igraph", "./input/_sfl_lcc_22_2_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_22_2_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_2.igraph", "./input/_sfl_lcc_22_2_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_22_2_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_2.igraph", "./input/_sfl_lcc_22_2_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_22_2_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_2.igraph", "./input/_sfl_lcc_22_2_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_22_3_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_3.igraph", "./input/_sfl_lcc_22_3_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_22_3_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_3.igraph", "./input/_sfl_lcc_22_3_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_22_3_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_3.igraph", "./input/_sfl_lcc_22_3_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_22_3_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_3.igraph", "./input/_sfl_lcc_22_3_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_22_3_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_3.igraph", "./input/_sfl_lcc_22_3_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_22_4_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_4.igraph", "./input/_sfl_lcc_22_4_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_22_4_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_4.igraph", "./input/_sfl_lcc_22_4_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_22_4_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_4.igraph", "./input/_sfl_lcc_22_4_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_22_4_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_4.igraph", "./input/_sfl_lcc_22_4_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_22_4_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_4.igraph", "./input/_sfl_lcc_22_4_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_22_5_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_5.igraph", "./input/_sfl_lcc_22_5_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_22_5_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_5.igraph", "./input/_sfl_lcc_22_5_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_22_5_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_5.igraph", "./input/_sfl_lcc_22_5_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_22_5_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_5.igraph", "./input/_sfl_lcc_22_5_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_22_5_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_5.igraph", "./input/_sfl_lcc_22_5_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_22_6_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_6.igraph", "./input/_sfl_lcc_22_6_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_22_6_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_6.igraph", "./input/_sfl_lcc_22_6_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_22_6_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_6.igraph", "./input/_sfl_lcc_22_6_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_22_6_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_6.igraph", "./input/_sfl_lcc_22_6_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_22_6_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_6.igraph", "./input/_sfl_lcc_22_6_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_22_7_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_7.igraph", "./input/_sfl_lcc_22_7_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_22_7_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_7.igraph", "./input/_sfl_lcc_22_7_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_22_7_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_7.igraph", "./input/_sfl_lcc_22_7_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_22_7_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_7.igraph", "./input/_sfl_lcc_22_7_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_22_7_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_7.igraph", "./input/_sfl_lcc_22_7_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_22_8_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_8.igraph", "./input/_sfl_lcc_22_8_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_22_8_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_8.igraph", "./input/_sfl_lcc_22_8_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_22_8_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_8.igraph", "./input/_sfl_lcc_22_8_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_22_8_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_8.igraph", "./input/_sfl_lcc_22_8_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_22_8_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_8.igraph", "./input/_sfl_lcc_22_8_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_22_9_0) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_9.igraph", "./input/_sfl_lcc_22_9_0.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_22_9_1) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_9.igraph", "./input/_sfl_lcc_22_9_1.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_22_9_2) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_9.igraph", "./input/_sfl_lcc_22_9_2.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_22_9_3) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_9.igraph", "./input/_sfl_lcc_22_9_3.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}

TEST(compare_test_small, compare_test_nonisomorphic_22_9_4) {
	bool isomorphic;
	double processTime;
	int ret = compare("./input/lcc_22_9.igraph", "./input/_sfl_lcc_22_9_4.igraph", &isomorphic, &processTime);
	ASSERT_EQ(1, ret);
	EXPECT_FALSE(isomorphic);
}
*/

