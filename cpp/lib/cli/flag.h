//
// Created by Gavin Mead on 5/29/24.
//

#pragma once

#include <string>
#include <memory>
#include <utility>

#include <optional>

namespace cli {

    std::optional<int> divide(int num1, int num2) {
        if (num2 != 0) {
            return num1/num2;
        }
        return std::nullopt; // Indicates no type-safe value
    }

    template <typename T>
    class F {
    public:
        virtual T processFlag(std::string flag) = 0;
    };

    class StringF : public F<std::string> {
    public:
        StringF() : F() {

        }

        std::string processFlag(std::string flag) override {
            return "foo";
        }
    };

    class IntF : public F<int> {
    public:
        IntF() : F() {

        }

        int processFlag(std::string flag) override {
            return 1;
        }
    };

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
         * Converts the flag to the flag type.  Will throw an exception if string cannot be converted.
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
        StringFlag(std::weak_ptr<std::string> var,
                   std::string defaultValue,
                   std::string shortName,
                   std::string longName = "",
                   std::string helpText = "") : Flag(shortName, longName, helpText) {

            this->var = var;
            this->defaultValue = defaultValue;
        }

        void processString(std::string flag) override {

        }
    private:
        std::weak_ptr<std::string> var;
        std::string defaultValue;
    };

    class IntFlag : public Flag {
    public:
        IntFlag(std::weak_ptr<int> var,
                int defaultValue,
                std::string shortName,
                std::string longName = "",
                std::string helpText = "") : Flag(shortName, longName, helpText) {
            this->var = var;
            this->defaultValue = defaultValue;
        }

        void processString(std::string flag) override {

        }
    private:
        std::weak_ptr<int> var;
        int defaultValue;
    };
}