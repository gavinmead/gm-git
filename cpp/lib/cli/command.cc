//
// Created by Gavin Mead on 5/19/24.
//

#include "command.h"
#include <vector>
#include <memory>

using namespace cli;

void Command::AddCommand(std::unique_ptr<Command> command) {
    if (command)
        subCommands.push_back(std::move(command));
    
}
