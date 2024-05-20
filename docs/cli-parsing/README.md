### cli-parsing

For fun, build a CLI parser in the spirit of Cobra/Viper.  
* APPNAME COMMAND ARG --FLAG

Uses abseil for flags

examples:

```bash
gm-git -h #shows help and sub commands
gm-git --help same as ^

gm-git init -h [directory] #shows help for init including cli

gm-git cat-file -t [blob, tree, tag, commit] [OBJECT]
```

```c++

//pseudocode for now...

#include "lib/cli/parser.h"
#include "lib/cli/command.h"
#include <expected>
#include <memory>

int main(int argc, char* argv[]) {
    
    //Define a root command
    auto rootCmd { cli::build(use="gm-git", run="//inline function"); };
    auto init = { cli::build(use="init", run="//inline function"); };
    rootCmd->AddCommand(init);
    
    result = cli::execute(argc, argv[], rootCmd);
    
    return result        
}

```