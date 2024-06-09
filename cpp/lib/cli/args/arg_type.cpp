//
// Created by Gavin Mead on 5/25/24.
//

#include "cpp/lib/cli/args/arg_type.h"
#include <string>
#include <algorithm>

namespace cli {
    ArgType resolveArgType(const char* arg, std::list<std::string> commandList) {

        std::string as = std::string(arg);
        auto is_flag = as.find('-');
        if (is_flag == 0) {
            return ArgType::Flag;
        }

        auto it = std::find(commandList.begin(), commandList.end(), as);

        if (it != commandList.end()) {
            return ArgType::Command;
        } else {
            return ArgType::Argument;
        }

    }

    ArgType ArgTypeResolver::resolveArgType(const char *arg, std::list<std::string> commandList) {
        return cli::resolveArgType(arg, commandList);
    }
}

