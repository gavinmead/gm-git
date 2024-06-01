//
// Created by Gavin Mead on 5/18/24.
//

#include <iostream>
#include <string>
#include <vector>
#include <optional>
#include "absl/strings/str_join.h"

std::optional<int> divide(int num1, int num2) {
    if (num2 != 0) {
        return num1/num2;
    }
    return std::nullopt; // Indicates no type-safe value
}

int main(int argc, const char* argv[]) {

    for (int i = 0; i < argc; i++) {
        const char* v = argv[i];
        std::cout << "arg: " << v<< std::endl;
    }

    std::vector<std::string> v = {"foo", "bar", "baz"};
    std::string s = absl::StrJoin(v, "-");

    std::cout << "Joined string: " << s << "\n";

    auto result = divide(10, 2); // To infer into std::optional<int>, used to save time
    if (result.has_value()) {  // has_value checks if a type-value is returned
        std::cout << "Result: " << result.value() << std::endl; // value returns the value as function arguments are correct
    } else {
        std::cout << "Division by zero" << std::endl;
    }

    return 0;
}