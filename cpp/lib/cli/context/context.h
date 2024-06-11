//
// Created by Gavin Mead on 6/10/24.
//

#ifndef CLWB_CONTEXT_H
#define CLWB_CONTEXT_H

#include "cpp/lib/cli/flags/flag.h"
#include "cpp/lib/cli/args/arg_type.h"
#include "cpp/lib/cli/command/command.h"
#include <memory>

namespace cli {

    class CommandContext {
    public:
        explicit CommandContext(std::unique_ptr<FlagNameParser> flagNameParser,
                                std::unique_ptr<ArgTypeResolver> argTypeResolver) :
            flagNameParser(std::move(flagNameParser)),
            argTypeResolver(std::move(argTypeResolver)) {
        }
        ~CommandContext() = default;

        FlagNameParser* GetFlagNameParser() { return flagNameParser.get(); }

        ArgTypeResolver* GetArgTypeResolver() { return argTypeResolver.get(); }

    private:
        std::unique_ptr<FlagNameParser> flagNameParser;
        std::unique_ptr<ArgTypeResolver> argTypeResolver;

    };

    class CommandContextBuilder {
    public :
        virtual CommandContextBuilder& withFlagNameResolver(std::unique_ptr<FlagNameParser> parser) = 0;
        virtual CommandContextBuilder& withArgTypeResolver(std::unique_ptr<ArgTypeResolver> argTypeResolver) = 0;
        virtual std::unique_ptr<CommandContext> build() = 0;
    };

    class DefaultCommandContextBuilder : public CommandContextBuilder{
    public:
        DefaultCommandContextBuilder();
        ~DefaultCommandContextBuilder() = default;
        DefaultCommandContextBuilder& operator=(const DefaultCommandContextBuilder& rhs) = delete;
        DefaultCommandContextBuilder(DefaultCommandContextBuilder&& other) = default;
        DefaultCommandContextBuilder& operator=(DefaultCommandContextBuilder&& rhs) = default;


        CommandContextBuilder& withFlagNameResolver(std::unique_ptr<FlagNameParser> parser) override;
        CommandContextBuilder& withArgTypeResolver(std::unique_ptr<ArgTypeResolver> argTypeResolver) override;
        std::unique_ptr<CommandContext> build() override;

    private:
        std::unique_ptr<FlagNameParser> flagNameParser;
        std::unique_ptr<ArgTypeResolver> argTypeResolver;
    };
}

#endif //CLWB_CONTEXT_H
