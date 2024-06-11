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

TEST(ContextBuilderTest, TestCustomArgTypeResolver) {
    std::unique_ptr<ArgTypeResolver> mockResolver = std::make_unique<cli::MockArgTypeResolver>();

    auto builder = DefaultCommandContextBuilder().withArgTypeResolver(std::move(mockResolver));
    ASSERT_NE(builder, nullptr);

    auto ctx = builder->build();
    ASSERT_NE(ctx, nullptr);

}