//
// Created by Gavin Mead on 5/19/24.
//

#ifndef GM_GIT_COMMAND_H
#define GM_GIT_COMMAND_H

#include <memory>
#include <utility>
#include <vector>
#include <list>
#include "cpp/lib/cli/args/arg_type.h"

namespace cli {

    enum class CommandResult {
        ok,
        parse_error,
        invalid_flag,
    };

    class Command {
        using Run = int (*)(Command *cmd, char *argv[]);
    public:

        explicit Command(std::string name,
                         std::string use = "",
                         std::string shortDescription = "",
                         std::string longDescription = "",
                         std::shared_ptr<ArgTypeResolver> resolver = nullptr,
                         Run onRun = nullptr) :
                name(std::move(name)),
                use(std::move(use)),
                shortDescription(std::move(shortDescription)),
                longDescription(std::move(longDescription)) {

            subCommands = std::vector<std::unique_ptr<Command>>(),
            r = onRun;

            if (resolver == nullptr) {
                argTypeResolver = std::make_shared<ArgTypeResolver>();
            } else {
                argTypeResolver = resolver;
            }

        }

        ~Command() = default;

        std::string Name() const { return name; }
        std::string Use() const { return use; }

        std::string ShortDescription() const { return shortDescription; }

        std::string LongDescription() const { return longDescription; }

        unsigned long CommandCount() const { return subCommands.size(); }

        /**
         *
         * @param argc
         * @param argv
         * @return a command result determine success of failure
         */
        CommandResult Execute(int argc, const char* argv[]);

        /**
         * Adds a command as a sub command
         * @param command
         */
        void AddCommand(std::unique_ptr<Command> command);

        /**
         *
         * @return an unordered list of each subcommand registered to this command
         */
        std::list<std::string> GetSubCommandNames();

    private:
        std::string name;
        std::string use;
        std::string shortDescription;
        std::string longDescription;
        Run r;
        std::shared_ptr<ArgTypeResolver> argTypeResolver;
        std::vector<std::unique_ptr<Command>> subCommands;
    };


}

#endif //GM_GIT_COMMAND_H
