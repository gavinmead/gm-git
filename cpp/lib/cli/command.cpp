//
// Created by Gavin Mead on 5/19/24.
//

#include "arg_type.h"
#include "command.h"
#include <vector>
#include <memory>
#include <iostream>

using namespace cli;

void Command::AddCommand(std::unique_ptr<Command> command) {
    if (command)
        subCommands.push_back(std::move(command));
    
}

CommandResult Command::Execute(int argc, const char* argv[]) {

    int idx = 1;
    bool NOT_DONE = true;

    Command* currentCommand = this;
    while(NOT_DONE) {
        if (idx >= argc) {
            NOT_DONE = false;
            break;
        }

        const char* current_arg = argv[idx];

        auto subCmdNames = GetSubCommandNames();
        auto argType = resolveArgType(current_arg, subCmdNames);

        switch (argType) {

            case ArgType::Command:
                // Find the subCommand, replace currentCommand and increment

                for (auto& i : currentCommand->subCommands) {
                    if (i->Name() == current_arg) {
                        currentCommand = i.get();
                    }
                }

                idx++;
                break;
            case ArgType::Flag:
                // Normalize the flag ->
                //  if flag is -d (Normalize(short, d, True)),
                //  if --debug (Normalize(long, debug, True)),
                //  if --debug=True (Normalize(long, debug, True)
                //  if --debug=False (Normalize(long, debug, False)
                // Get the Flags from the current command
                // Search for the Flags to see if they exist, if they are not present, then return invalid flag. (TODO fix this)
                // If flag is present, then set the flag value to the registered variable on the flag.

                idx++;
                break;
            case ArgType::Argument:
                idx++;
                break;
        }


    }

    return CommandResult::ok;
}

std::list<std::string> Command::GetSubCommandNames() {
    auto l = std::list<std::string>();

    for (auto&& c : subCommands) {
        l.push_back(c->Name());
    }

    return l;
}


