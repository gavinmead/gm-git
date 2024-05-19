//
// Created by Gavin Mead on 5/19/24.
//

#ifndef GM_GIT_COMMAND_H
#define GM_GIT_COMMAND_H

#include <memory>
#include <utility>
#include <vector>

namespace cli {

    class Command {
    public:
        explicit Command(std::string use, std::string shortDescription="", std::string longDescription="") :
            use(std::move(use)),
            shortDescription(std::move(shortDescription)),
            longDescription(std::move(longDescription)) {
            subCommands = std::vector<std::unique_ptr<Command>>();
        }
        ~Command() = default;

        std::string Use() const { return use; }
        std::string ShortDescription() const {return shortDescription; }
        std::string LongDescription() const {return longDescription; }
        unsigned long CommandCount() const { return subCommands.size(); }

        /**
         * Adds a command as a sub command
         * @param command
         */
        void AddCommand(std::unique_ptr<Command> command);

    private:
        std::string use;
        std::string shortDescription;
        std::string longDescription;
        std::vector<std::unique_ptr<Command>> subCommands;
    };

    int Execute(int argc, char* argv[], Command* rootCmd);

    int add(int x, int y);

}

#endif //GM_GIT_COMMAND_H
