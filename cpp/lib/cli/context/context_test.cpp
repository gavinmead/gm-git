//
// Created by Gavin Mead on 6/10/24.
//

#include "include/gtest/gtest.h"
#include "include/gmock/gmock.h"
#include "context.h"
#include "cpp/lib/cli/args/arg_type.h"
#include "cpp/lib/cli/mocks/arg_type_mock.h"
#include <memory>


using namespace cli;

TEST(CommandContextBuilder, TestDefaults) {
    DefaultCommandContextBuilder builder = DefaultCommandContextBuilder();
    auto ctx = builder.build();
    ASSERT_NE(ctx, nullptr);
    ASSERT_NE(ctx->GetArgTypeResolver(), nullptr);
    ASSERT_NE(ctx->GetFlagNameParser(), nullptr);
}

TEST(ContextBuilderTest, TestCustomArgTypeResolver) {
    std::unique_ptr<ArgTypeResolver> mockResolver = std::make_unique<cli::MockArgTypeResolver>();

    DefaultCommandContextBuilder builder = DefaultCommandContextBuilder();

    builder.withArgTypeResolver(std::move(mockResolver));
    auto ctx = builder.build();
    ASSERT_NE(ctx, nullptr);
    ASSERT_NE(ctx->GetArgTypeResolver(), nullptr);
    ASSERT_NE(ctx->GetFlagNameParser(), nullptr);
}