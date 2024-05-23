//
// Created by Gavin Mead on 5/22/24.
//

#ifndef CLWB_FLAG_H
#define CLWB_FLAG_H

#include <memory>
#include <string>

namespace cli {

    template <typename T>
    class Flag {
    public:

        explicit Flag(T* val,
                      T defaultValue,
                      std::string shortName,
                      std::string longName = "",
                      std::string helpText= "") :
                val(val),
                defaultVal(defaultValue),
                shortName(std::move(shortName)),
                longName(std::move(longName)),
                helpText(std::move(helpText)) {
        }
        ~Flag() = default;

        std::string ShortName() const { return shortName; }
        std::string LongName() const { return longName; }
        std::string HelpText() const { return helpText; }

        T* Value();


    private:
        T* val;
        T defaultVal;
        std::string shortName;
        std::string longName;
        std::string helpText;
    };


    template<typename T>
    T* Flag<T>::Value() {
        if (!val) {
            return &defaultVal;
        }
        return val;
    }
}

#endif //CLWB_FLAG_H
