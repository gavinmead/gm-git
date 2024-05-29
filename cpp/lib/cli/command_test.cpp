//
// Created by Gavin Mead on 5/19/24.
//

#include "command.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "arg_type_mock.h"
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
    std::shared_ptr<MockArgTypeResolver> mockResolver = std::make_shared<MockArgTypeResolver>();
    EXPECT_CALL(*mockResolver, resolveArgType)
        .Times(1)
        .WillOnce(::testing::Return(ArgType::Flag));

    auto cmd = std::make_unique<Command>("test", "", "", "", mockResolver);
    ASSERT_NE(cmd, nullptr);

    const char* args[]={
            "test","-h",
    };
    int argc = sizeof(args)/sizeof(char*);

    auto result = cmd->Execute(argc, args);
    ASSERT_EQ(result, CommandResult::ok);

}

TEST(CommandTest, ExecuteWithSubCommand) {
    std::shared_ptr<MockArgTypeResolver> mockResolver = std::make_shared<MockArgTypeResolver>();
    EXPECT_CALL(*mockResolver, resolveArgType)
            .Times(1)
            .WillOnce(::testing::Return(ArgType::Command));

    auto rootCmd = std::make_unique<Command> ( "test", "", "", "", mockResolver);
    auto subCmd = std::make_unique<Command>("sub");

    ASSERT_NE(rootCmd, nullptr);
    ASSERT_NE(subCmd, nullptr);

    rootCmd->AddCommand(std::move(subCmd));

    const char* args[]={
            "test","sub",
    };
    int argc = sizeof(args)/sizeof(char*);

    auto result = rootCmd->Execute(argc, args);
    ASSERT_EQ(result, CommandResult::ok);
}

TEST(CommandTest, ExecuteSimpleMix) {
    std::shared_ptr<MockArgTypeResolver> mockResolver = std::make_shared<MockArgTypeResolver>();
    EXPECT_CALL(*mockResolver, resolveArgType)
            .Times(2)
            .WillOnce(::testing::Return(ArgType::Flag))
            .WillOnce(::testing::Return(ArgType::Command));

    auto rootCmd = std::make_unique<Command> ( "test", "", "", "", mockResolver);
    auto subCmd = std::make_unique<Command>("sub");

    ASSERT_NE(rootCmd, nullptr);
    ASSERT_NE(subCmd, nullptr);

    rootCmd->AddCommand(std::move(subCmd));

    const char* args[]={
            "test", "-d", "sub",
    };
    int argc = sizeof(args)/sizeof(char*);

    auto result = rootCmd->Execute(argc, args);
    ASSERT_EQ(result, CommandResult::ok);
}

TEST(CommandTest, MultiFlagAndSubCommands) {
    std::shared_ptr<MockArgTypeResolver> mockResolver = std::make_shared<MockArgTypeResolver>();
    EXPECT_CALL(*mockResolver, resolveArgType)
            .Times(5)
            .WillOnce(::testing::Return(ArgType::Flag))
            .WillOnce(::testing::Return(ArgType::Command))
            .WillOnce(::testing::Return(ArgType::Command))
            .WillOnce(::testing::Return(ArgType::Flag))
            .WillOnce(::testing::Return(ArgType::Argument));

    auto rootCmd = std::make_unique<Command> ( "test", "", "", "", mockResolver);
    auto subCmd = std::make_unique<Command>("sub", "", "", "", mockResolver);
    auto thirdCmd = std::make_unique<Command>("third", "", "", "", mockResolver);

    ASSERT_NE(rootCmd, nullptr);
    ASSERT_NE(subCmd, nullptr);
    ASSERT_NE(thirdCmd, nullptr);

    //The order command adds must be bottom up because of the move.
    subCmd->AddCommand(std::move(thirdCmd));
    rootCmd->AddCommand(std::move(subCmd));


    const char* args[]={
            "test", "-d", "sub", "third", "--foo", "argument"
    };
    int argc = sizeof(args)/sizeof(char*);

    auto result = rootCmd->Execute(argc, args);
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
