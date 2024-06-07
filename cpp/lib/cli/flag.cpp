//
// Created by Gavin Mead on 6/6/24.
//

#include "flag.h"
#include <cctype>
#include <string>
#include <string_view>
#include <optional>

namespace cli {

    void FlagName::parseFlagName(const char *flagArg) {
        valid = true;
        auto sv = std::string_view(flagArg);
        //See if it is a long name
        auto n = sv.find("--", 0);
        if (n != std::string::npos) {
            isLongName = true;
        }

        if (isLongName) {
            name = sv.substr(2);
        } else {
            name = sv.substr(1);
        }

        if (std::isdigit(name[0])) {
            valid = false;
        }
    }

    std::optional<int> divide(int num1, int num2) {
        if (num2 != 0) {
            return num1 / num2;
        }
        return std::nullopt; // Indicates no type-safe value
    }
}