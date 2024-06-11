//
// Created by Gavin Mead on 6/10/24.
//

#include "context.h"

namespace cli {

    CommandContextBuilder* DefaultCommandContextBuilder::withArgTypeResolver(std::unique_ptr<ArgTypeResolver> argTypeResolver) {
        this->argTypeResolver = std::move(argTypeResolver);
        return this;
    }

    CommandContextBuilder* DefaultCommandContextBuilder::withFlagNameResolver(std::unique_ptr<FlagNameParser> parser) {
        this->flagNameParser = std::move(parser);
        return this;
    }

    std::unique_ptr<CommandContext> DefaultCommandContextBuilder::build() {
        return std::make_unique<CommandContext>();
    }
}