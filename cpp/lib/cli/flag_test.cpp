//
// Created by Gavin Mead on 5/22/24.
//

#include "gtest/gtest.h"
#include "flag.h"
#include <memory>

using namespace cli;

TEST(FlagTest, DefaultConstructor) {
    int x = 1;
    auto f = Flag<int>(&x, 0, "t");
    EXPECT_NE(&f, nullptr);

    EXPECT_EQ(f.Value(), &x);
    EXPECT_EQ(f.ShortName(), "t");
    EXPECT_EQ(f.LongName(), "");
    EXPECT_EQ(f.HelpText(), "");
}

//TEST(FlagTest, ConstructorInit) {
//    int x = 0;
//    auto f = Flag<int>(&x, "t", "test", "help");
//    EXPECT_NE(&f, nullptr);
//    EXPECT_EQ(f.ShortName(), "t");
//    EXPECT_EQ(f.LongName(), "test");
//    EXPECT_EQ(f.HelpText(), "help");
//}