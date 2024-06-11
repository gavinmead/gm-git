//
// Created by Gavin Mead on 6/10/24.
//

#include "context.h"
#include "cpp/lib/cli/flags/flag.h"
#include "cpp/lib/cli/args/arg_type.h"

namespace cli {

    DefaultCommandContextBuilder::DefaultCommandContextBuilder() {
        this->argTypeResolver = std::make_unique<ArgTypeResolver>(ArgTypeResolver());
        this->flagNameParser = std::make_unique<DefaultFlagNameParser>(DefaultFlagNameParser());
    }

    CommandContextBuilder& DefaultCommandContextBuilder::withArgTypeResolver(std::unique_ptr<ArgTypeResolver> argTypeResolver) {
        this->argTypeResolver = std::move(argTypeResolver);
        return *this;
    }

    CommandContextBuilder& DefaultCommandContextBuilder::withFlagNameResolver(std::unique_ptr<FlagNameParser> parser) {
        this->flagNameParser = std::move(parser);
        return *this;
    }

    std::unique_ptr<CommandContext> DefaultCommandContextBuilder::build() {
        return std::make_unique<CommandContext>(std::move(this->flagNameParser),
                                                std::move(this->argTypeResolver));
    }
}