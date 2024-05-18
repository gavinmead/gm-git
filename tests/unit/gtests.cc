//
// Created by Gavin Mead on 5/18/24.
//


#include "gtest/gtest.h"

TEST(ExpectTest, TrueIsTrue) {
    EXPECT_TRUE(true);
}

TEST(ExpectTest, FalseIsFale) {
    EXPECT_FALSE(false);
}