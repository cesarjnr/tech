## Script

To create a script we need to create a file with a **.sh** extension. Then, to run the script we need to use the `bash` command:

```
bash script.sh
```

But we can tell our command line which interpreter to use by adding a header to the top of the script file using the shebang symbol (!#):

```sh
  !#/usr/bin/zsh
```

We should append the path of the interpreter that should be used for the script.

> You can use the command `echo $SHELL` to display the value of the env $SHELL. This env holds the path of the current interpreter being used by your terminal to run bash commands.

This way, you can now pass only the path of the **.sh** file to run it:

```
./script.sh
```