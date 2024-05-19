//
// Created by Gavin Mead on 5/19/24.
//

#ifndef GM_GIT_COMMAND_H
#define GM_GIT_COMMAND_H

namespace cli {

    class Command {

    };


    int Execute(int argc, char* argv[], Command* rootCmd);

    int add(int x, int y);

}

#endif //GM_GIT_COMMAND_H
