//
// Created by Gavin Mead on 5/18/24.
//

#include "cpp/lib/my_math.h"
#include "gtest/gtest.h"

TEST(MyMathSuite, TestAdd) {
    EXPECT_EQ(2, add(1,1));
}

TEST(MyMathSuite, TestSub) {
    EXPECT_EQ(2, sub(3,1));
}