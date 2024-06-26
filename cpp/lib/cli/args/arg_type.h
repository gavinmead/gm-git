//
// Created by Gavin Mead on 5/25/24.
//

#ifndef CLWB_ARG_TYPE_H
#define CLWB_ARG_TYPE_H

#include <list>
#include <string>

namespace cli {
    enum class ArgType {
        Command,
        Flag,
        Argument
    };

    ArgType resolveArgType(const char* arg, std::list<std::string> commandList);

    class ArgTypeResolver {
    public:
        ArgTypeResolver() = default;
        virtual ~ArgTypeResolver() = default;
        virtual ArgType resolveArgType(const char* arg, std::list<std::string> commandList);
    };
}

#endif //CLWB_ARG_TYPE_H
