//
// Created by Gavin Mead on 5/31/24.
//

#include "include/gtest/gtest.h"
#include "cpp/lib/cli/flags/flag.h"
#include <memory>
#include <stdexcept>

using namespace cli;

TEST(FlagTest, TestStringFlag) {
    auto entry = std::make_shared<std::string>("");
    auto defaultValue = "default";

    auto sf = StringFlag(std::weak_ptr<std::string>(entry), defaultValue, "t", "test", "");
    ASSERT_EQ(sf.ShortName(), "t");

    ASSERT_EQ(*entry, "");
    sf.processString("test");
    ASSERT_EQ(*entry, "test");
}

TEST(FlagTest, TestIntFlag) {
    auto entry = std::make_shared<int>(0);
    int defaultValue = 0;

    auto iFlag = IntFlag(std::weak_ptr<int>(entry), defaultValue, "t", "test", "");
    ASSERT_EQ(*entry, 0);
    iFlag.processString("100");
    ASSERT_EQ(*entry, 100);
}

TEST(FlagTest, TestInvalidIntFlag) {
    auto entry = std::make_shared<int>(0);
    int defaultValue = 0;

    auto iFlag = IntFlag(std::weak_ptr<int>(entry), defaultValue, "t", "test", "");
    ASSERT_EQ(*entry, 0);
    EXPECT_THROW({
        iFlag.processString("a100");
    }, std::invalid_argument);

}

TEST(FlagTest, TestOptional) {
    auto result = divide(10, 2);
    ASSERT_TRUE(result.has_value());
}

TEST(FlagTest, ParseFlagNameShortOk) {
    const char* arg = "-f";
    auto f = FlagName{};
    f.parseFlagName(arg);
    ASSERT_EQ(f.isLongName, false);
    ASSERT_EQ(f.name, "f");
    ASSERT_EQ(f.valid, true);
}

TEST(FlagTest, ParseFlagNameShortNotOk) {
    const char* arg = "-1";
    auto f = FlagName{};
    f.parseFlagName(arg);
    ASSERT_EQ(f.isLongName, false);
    ASSERT_EQ(f.name, "1");
    ASSERT_EQ(f.valid, false);
}

TEST(FlagTest, ParseFlagNameLongOk) {
    const char* arg = "--foo";
    auto f = FlagName{};
    f.parseFlagName(arg);
    ASSERT_EQ(f.isLongName, true);
    ASSERT_EQ(f.name, "foo");
    ASSERT_EQ(f.valid, true);
}

TEST(FlagTest, ParseFlagNameLongNotOk) {
    const char* arg = "--1foo";
    auto f = FlagName{};
    f.parseFlagName(arg);
    ASSERT_EQ(f.isLongName, true);
    ASSERT_EQ(f.name, "1foo");
    ASSERT_EQ(f.valid, false);
}

TEST(FlagTest, DefaultFlagNameParserOk) {
    const char* arg = "--foo";
    auto p = DefaultFlagNameParser();
    auto f = p.parse(arg);
    ASSERT_EQ(f.isLongName, true);
    ASSERT_EQ(f.name, "foo");
    ASSERT_EQ(f.valid, true);
}