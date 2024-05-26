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

    EXPECT_EQ(cmd->Name(), "test");
    EXPECT_EQ(cmd->Use(), "");
    EXPECT_EQ(cmd->ShortDescription(), "");
    EXPECT_EQ(cmd->LongDescription(), "");
    EXPECT_EQ(cmd->CommandCount(), 0);
}

TEST(CommandTest, TestCustomConstructorArgs) {
    auto cmd = std::make_unique<Command> ( "test", "use", "short", "long");

    ASSERT_NE(cmd, nullptr);
    EXPECT_EQ(cmd->Name(), "test");
    EXPECT_EQ(cmd->Use(), "use");
    EXPECT_EQ(cmd->ShortDescription(), "short");
    EXPECT_EQ(cmd->LongDescription(), "long");
    EXPECT_EQ(cmd->CommandCount(), 0);
}

TEST(CommandTest, TestAddCommand) {
    auto root = std::make_unique<Command> ( "testRoot");
    auto sub = std::make_unique<Command> ( "sub");
    ASSERT_NE(root, nullptr);
    ASSERT_NE(sub, nullptr);

    root->AddCommand(std::move(sub));
    EXPECT_EQ(root->CommandCount(), 1);
}

TEST(CommandTest, TestAddNullCommand) {
    auto cmd = std::make_unique<Command> ( "test");

    ASSERT_NE(cmd, nullptr);
    cmd->AddCommand(nullptr);
    EXPECT_EQ(cmd->CommandCount(), 0);
}

TEST(CommandTest, ExecuteSimpleCommand) {
    auto cmd = std::make_unique<Command> ( "test");
    ASSERT_NE(cmd, nullptr);

    const char* args[]={
            "test","-h",
    };
    int argc = sizeof(args)/sizeof(char*);

    auto result = cmd->Execute(argc, args);
    ASSERT_EQ(result, CommandResult::ok);

}

TEST(CommandTest, GetSubCommandNamesTest) {
    auto rootCmd = std::make_unique<Command>("rootCmd");
    auto subCmd = std::make_unique<Command>("subCmd");

    rootCmd->AddCommand(std::move(subCmd));

    auto results = rootCmd->GetSubCommandNames();
    ASSERT_EQ(results.size(), 1);
    ASSERT_EQ(results.front(), "subCmd");
}