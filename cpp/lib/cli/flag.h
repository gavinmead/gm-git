//
// Created by Gavin Mead on 5/29/24.
//

#pragma once

#include <string>
#include <memory>
#include <utility>
#include <stdexcept>
#include <optional>

#define FLAG_TYPE(flag_type)                                                                                \
    std::weak_ptr<flag_type> var;                                                                           \
    flag_type defaultValue;

#define FLAG_CTOR(flag_type, class_name)                                                                    \
    class_name(                                                                                             \
         std::weak_ptr<flag_type> var,                                                                      \
         flag_type defaultValue,                                                                            \
         std::string shortName,                                                                             \
         std::string longName = "",                                                                         \
         std::string helpText = "") : Flag(std::move(shortName), std::move(longName), std::move(helpText)) {\
            this->var = var;                                                                                \
            this->defaultValue = defaultValue;                                                              \
         }                                                                                                  \

#define PROCESS_FLAG(flag_type, statement)                                                                  \
    if (std::shared_ptr<flag_type> tmp = var.lock()) {                                                      \
        flag_type result = statement;                                                                       \
        *tmp = result;                                                                                      \
    }                                                                                                       \

namespace cli {

    std::optional<int> divide(int num1, int num2) {
        if (num2 != 0) {
            return num1 / num2;
        }
        return std::nullopt; // Indicates no type-safe value
    }

    class Flag {
    public:
        explicit Flag(
                std::string shortName,
                std::string longName = "",
                std::string helpText = "") :
                shortName(std::move(shortName)),
                longName(std::move(longName)),
                helpText(std::move(helpText)) {

        }

        ~Flag() = default;

        std::string ShortName() const { return shortName; }

        std::string LongName() const { return longName; }

        std::string HelpText() const { return helpText; }

        /**
         * Converts the flag to the flag type.
         * @param flag
         * @return
         *
         */
        virtual void processString(std::string flag) = 0;

    private:
        std::string shortName;
        std::string longName;
        std::string helpText;
    };

    class StringFlag : public Flag {
    public:
        FLAG_CTOR(std::string, StringFlag)

        void processString(std::string flag) override {
            PROCESS_FLAG(std::string, flag)
        }

    private:
        FLAG_TYPE(std::string)

    };

    class IntFlag : public Flag {
    public:
        FLAG_CTOR(int, IntFlag)

        void processString(std::string flag) override {
            PROCESS_FLAG(int, std::stoi(flag))
        }

    private:
        FLAG_TYPE(int)
    };
}