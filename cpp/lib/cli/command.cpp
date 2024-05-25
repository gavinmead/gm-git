//
// Created by Gavin Mead on 5/19/24.
//

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

    while(NOT_DONE) {
        if (idx >= argc) {
            NOT_DONE = false;
            break;
        }

        const char* current_arg = argv[idx];

        //Determine what the arg is (a flag, an arg or subcommand)

        idx++;
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

