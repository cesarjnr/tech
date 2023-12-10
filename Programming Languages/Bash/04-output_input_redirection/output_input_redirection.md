## Output/Input Redirection

### Output Redirection

Output redirection is a way to forward the output of some command.

#### Pipping

Pipping is a way to forward the output of some command to another command. To do that, we can use the pipe symbol `|`:

```
ls -l /usr/bin | grep bash
```

In the example above, we're using the `ls` command to list all content within the `bin` folder. Then we're using the pipe symbol `|` to forward the output to the grep command to filter only the results that contain the string *bash*.

#### Redirect to a File

To redirect the output to a file, we can use the symbol `>`:

```
echo Hello World! > hello.txt
```

In the example above, we are writing the string *Hello World!* into a file called **hello.txt**.

> If the file does not exist, then it is automatically created. If the file already exists, then its content is entirely replaced.

#### Appending to a File

In order to append a content to an existing file rather than replacing its content, we need to use the symbol `>>`:

```
echo Welcome to the bash world! >> hello.txt
```

> If the file does not exist, then it is automatically created. If the file already exists, then the output of the `echo` command is appended to the end of the file.

### Input Redirection

Input redirection is a way to forward an input to a command.

#### Redirect from a File

If we want to pass the content of a file as an input to a command, we can use the `<` symbol:

```
wc -w < hello.txt
```

In the command above, we are using the `wc` command with the `-w` parameter to read the number of words in a file. If we pass the filename to this command, it will print the number of words along with the filename. But if we pass the content of the file using the `<` symbol, it will print only the number of words since it doesn't know the file where the content is coming from.

#### Redirect Multiple Line Strings

If we want to redirect a multiple line string to a command, we can use the `<<` symbol along with some word (usually `EOF`):

```
cat << `EOF`
```

This tells the command line we'll get multiple lines from the user input until the word `EOF` is entered. This way, the command line will wait for user input and every time the **ENTER** key is used the it will add a line break and wait for another string until the word `EOF` is entered. Then, everything between the two `EOF` references will be redirected to the command.

#### Redirect a String

If we want to redirect a string (multiple words without line breaks) we can use the `<<<` symbol:

```
wc -w <<< "Hello World!"
```

> You can either provide the string with single or double quotes.