//
// Created by Gavin Mead on 5/18/24.
//

#include <iostream>
#include <string>
#include <vector>

#include "absl/strings/str_join.h"

int main() {
    std::vector<std::string> v = {"foo", "bar", "baz"};
    std::string s = absl::StrJoin(v, "-");

    std::cout << "Joined string: " << s << "\n";

    return 0;
}