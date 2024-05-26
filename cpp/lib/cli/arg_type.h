//
// Created by Gavin Mead on 5/25/24.
//

#ifndef CLWB_ARG_TYPE_H
#define CLWB_ARG_TYPE_H

#include <list>

namespace cli {
    enum class ArgType {
        Command,
        Flag,
        Argument
    };

    ArgType resolveArgType(const char* arg, std::list<std::string> commandList);
}

#endif //CLWB_ARG_TYPE_H
