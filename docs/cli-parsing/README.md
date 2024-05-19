### cli-parsing

For fun, build a CLI parser in the spirit of Cobra/Viper.  

Uses abseil for flags

examples:

```bash
gm-git -h #shows help and sub commands
gm-git --help same as ^

gm-git init -h [directory] #shows help for init including args

gm-git cat-file -t [blob, tree, tag, commit] [OBJECT]
```

