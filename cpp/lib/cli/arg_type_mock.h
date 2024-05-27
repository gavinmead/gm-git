//
// Created by Gavin Mead on 5/27/24.
//

#ifndef CLWB_ARG_TYPE_MOCK_H
#define CLWB_ARG_TYPE_MOCK_H

#include "arg_type.h"
#include "list"
#include "string"
#include "gmock/gmock.h"

using namespace cli;

namespace {
    class MockArgTypeResolver : public ArgTypeResolver {
    public:
        MOCK_METHOD(ArgType, resolveArgType, (const char* arg, std::list<std::string> commands), (override));
    };
}

#endif //CLWB_ARG_TYPE_MOCK_H
