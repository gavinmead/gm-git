//
// Created by Gavin Mead on 5/19/24.
//

#include "command.h"
#include "gtest/gtest.h"
#include <memory>

using namespace cli;

TEST(CommandTest, TestDefaultConstructor) {
    auto cmd = std::make_unique<Command> ( "test" );
    ASSERT_NE(cmd, nullptr);

    EXPECT_EQ(cmd->Use(), "test");
    EXPECT_EQ(cmd->ShortDescription(), "");
    EXPECT_EQ(cmd->LongDescription(), "");
    EXPECT_EQ(cmd->CommandCount(), 0);
}

TEST(CommandTest, TestCustomConstructorArgs) {
    auto cmd = std::make_unique<Command> ( "test", "short", "long");

    ASSERT_NE(cmd, nullptr);

    EXPECT_EQ(cmd->Use(), "test");
    EXPECT_EQ(cmd->ShortDescription(), "short");
    EXPECT_EQ(cmd->LongDescription(), "long");
    EXPECT_EQ(cmd->CommandCount(), 0);
}

TEST(CommandTest, TestAddCommand) {
    auto root = std::make_unique<Command> ( "testRoot", "short", "long");
    auto sub = std::make_unique<Command> ( "sub");
    ASSERT_NE(root, nullptr);
    ASSERT_NE(sub, nullptr);

    root->AddCommand(std::move(sub));
    EXPECT_EQ(root->CommandCount(), 1);
}

TEST(CommandTest, TestAddNullCommand) {
    auto cmd = std::make_unique<Command> ( "test", "short", "long");

    ASSERT_NE(cmd, nullptr);
    cmd->AddCommand(nullptr);
    EXPECT_EQ(cmd->CommandCount(), 0);
}