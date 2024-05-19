//
// Created by Gavin Mead on 5/19/24.
//

#include "command.h"
#include "include/gtest/gtest.h"


TEST(CliTest, TestAdd) {
    EXPECT_EQ(2, cli::add(1,1));
}