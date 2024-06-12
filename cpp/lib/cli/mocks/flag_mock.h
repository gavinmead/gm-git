//
// Created by Gavin Mead on 6/12/24.
//

#ifndef CLWB_FLAG_MOCK_H
#define CLWB_FLAG_MOCK_H

#include "cpp/lib/cli/flags/flag.h"
#include "gmock/gmock.h"

namespace cli {
    class MockFlagNameParser : public FlagNameParser {
    public:
        MockFlagNameParser() = default;
        ~MockFlagNameParser() override = default;
        MOCK_METHOD(FlagName, parse, (const char* arg), (override));
    };
}

#endif //CLWB_FLAG_MOCK_H
