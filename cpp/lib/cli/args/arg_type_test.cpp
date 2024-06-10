//
// Created by Gavin Mead on 5/25/24.
//

#include "cpp/lib/cli/args/arg_type.h"
#include "include/gtest/gtest.h"
#include <memory>
#include <list>

using namespace cli;

TEST(ArgTypeTest, TestIsSubCommand) {
    const char* arg = "test";
    auto l = std::list<std::string>{"foo", "bar", "test"};

    auto result = resolveArgType(arg, l);
    ASSERT_EQ(result, ArgType::Command);
}

TEST(ArgTypeTest, TestIsSubCommandAnywhereInList) {
    const char* arg = "test";
    auto l = std::list<std::string>{"foo", "test", "bar" };

    auto result = resolveArgType(arg, l);
    ASSERT_EQ(result, ArgType::Command);
}

TEST(ArgTypeTest, TestIsArgumentOnEmptyList) {
    const char* arg = "test";
    auto l = std::list<std::string>{};
    auto result = resolveArgType(arg, l);
    ASSERT_EQ(result, ArgType::Argument);
}

TEST(ArgTypeTest, TestIsFlag) {
    const char* arg = "-t";
    auto l = std::list<std::string>{};
    auto result = resolveArgType(arg, l);
    ASSERT_EQ(result, ArgType::Flag);
}

TEST(ArgTypeTest, TestIsNotFlagWithDash) {
    const char* arg = "test-with-dash";
    auto l = std::list<std::string>{};
    auto result = resolveArgType(arg, l);
    ASSERT_EQ(result, ArgType::Argument);
}

TEST(ArgTypeTest, TestIsFlagWithDashes) {
    const char* arg = "--test";
    auto l = std::list<std::string>{};
    auto result = resolveArgType(arg, l);
    ASSERT_EQ(result, ArgType::Flag);
}

TEST(ArgTypeTest, TestIsFlagWithSameSubCommand) {
    const char* arg = "--test";
    auto l = std::list<std::string>{"test"};
    auto result = resolveArgType(arg, l);
    ASSERT_EQ(result, ArgType::Flag);
}

TEST(ArgTypeTest, TestArgTypeResolver) {
    const char* arg = "--test";
    auto l = std::list<std::string>{"test"};
    auto resolver = ArgTypeResolver();
    auto result = resolver.resolveArgType(arg, l);
    ASSERT_EQ(result, ArgType::Flag);
}