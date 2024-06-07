//
// Created by Gavin Mead on 6/6/24.
//

#include "flag.h"
#include <cstring>
#include <optional>

namespace cli {
    ParsedFlag parseFlag(int startIdx, const char* argv[]) {
        //Start reading
        auto pf = ParsedFlag{};
        bool hasMore = true;
        int i = 0;
        int currentIdx = startIdx;

        while(hasMore) {
            auto currentArg = argv[currentIdx];
            size_t len = std::strlen(currentArg);

            char current = argv[currentIdx][i];
            switch (current) {
                case '-':
                    //peek if the next is a -, we know it is a long flag
                    if (i < len) {
                        if(argv[currentIdx][i + 1] == '-') {
                            pf.isLongName = true;
                            i += 2;
                        }
                    }
                case '=':

            }
            hasMore = false;
        }

        return ParsedFlag{};
    }

    std::optional<int> divide(int num1, int num2) {
        if (num2 != 0) {
            return num1 / num2;
        }
        return std::nullopt; // Indicates no type-safe value
    }
}