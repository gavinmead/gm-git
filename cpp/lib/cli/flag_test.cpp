//
// Created by Gavin Mead on 5/31/24.
//

#include "gtest/gtest.h"
#include "flag.h"
#include <memory>
#include <vector>

using namespace cli;

TEST(FlagTest, TestStringFlag) {
    auto entry = std::make_shared<std::string>("");
    auto defaultValue = "default";

    auto sf = StringFlag(std::weak_ptr<std::string>(entry), defaultValue, "t", "test", "");
    ASSERT_EQ(sf.ShortName(), "t");
}

TEST(FlagTest, TestVectorOfFlags) {
    auto entry = std::make_shared<std::string>("");
    auto defaultValue = "default";
    auto sf = StringFlag(std::weak_ptr<std::string>(entry), defaultValue, "t", "test", "");

    auto iEntry = std::make_shared<int>(0);
    int defaultIntValue = 0;
    auto intFlag = IntFlag(iEntry, defaultIntValue, "i", "int-flag", "");

    std::vector<Flag*> v = {&sf, &intFlag};
    ASSERT_EQ(2, v.size());

}

TEST(FlagTest, TestVectorOfAnyFlags) {
    auto sFlag = StringF();
    auto iFlag = IntF();

}

TEST(FlagTest, TestOptional) {
    auto result = divide(10, 2);
    ASSERT_TRUE(result.has_value());
}