## Basic Commands

### echo

`echo` displays the text we pass as an argument:

```
echo Hello
```

### cat

`cat` displays the content of a file which we pass the path as an argument:

```
cat file.txt
```

### file

`file` displays the file type of the file/directory which we pass the path as an argument:

```
file some_file
```

We can also use glob patterns as the argument. For example, if we want to display the file type of all files inside the current folder we can use:

```
file ./*
```

### useradd

`useradd` creates a new user with the specified username passed as an argument:

```
useradd username
```

Without the -D parameter, the user is created using default values from the system. When invoked with the -D parameter plus other options, `useradd` will replace the default values for the specified options.

```
useradd -D username
```

The -d parameter allows us to specify the user's login directory:

```
useradd -d /some/path username
```

The -s parameter sets the path to the user's login shell. Without this option, the system will use the `$SHELL` value specified in `/etc/default/useradd`. If you want to now allow the user to log into the system, like a user created to be used by a program for example, you can specify the path /sbin/nologin:

```
useradd -s /sbin/nologin username
```

The -m parameter creates the user's home directory if it doesn't exist:

```
useradd -m username
```

> If you want to list all the users you can check the content of the file `/etc/passwd`.

### passwd

`passwd` changes user password of the specified username passed as an argument:

```
passwd username
```

### groupadd

`groupadd` creates a new group using the speficied name passed as an argument:

```
groupadd groupname
```

> If you want to list all groups you can check the content of the file `/etc/group`.

### usermod

`usermod` modify a user account. This command requires at least 2 arguments: 1 option and the username. For example:

```
usermod -aG groupnameone,groupnametwo username
```

This adds the user `username` to the groups `groupnameone` and `groupnametwo`. The parameter `-G` sets the specified groups to the specified user. If the user is member of other groups that are not specified, the user will be removed from those groups. That's why we used the `-a` parameter which slightly changes the behavior of `-G` by appending the user to the specified groups instead of replacing the user groups.

> If you want to check the users that are members of a specified group you can use the grep command:

```
grep '^<groupname>:' /etc/group
```

> Where \<groupname\> is the group you want to check.

### chmod

`chmod` changes file and directories permissions of the specified filename:

```
chmod 750 filename
```

In this example, we are giving the following permissions to the file `filename`:

* 7: read, write and execute (rwx) to the onwer of the file;
* 5: read and execute (rx) to the members of the file group;
* 0: no permissions to the other users of the system.

> In this example, we are using octal numbers. The octal numbers are interpreted from right to left. So, in the following example:

```
chmod 50 filename
```

> Since we're setting only two numbers, only the permissions for the members of the file group (5) and for the other users of the system (0) are set. And the permissions for the owner of the file are set to 0 by default since it hasn't been specified in the command.

### chown

`chown` changes the user owner and the group owner of the specified filename:

```
chown username:groupname filename
```

In this example, we're setting `username` and `groupname` as the new owners of the `filename`.

> If you want to check the user owner of a file you can use the stat command:

```
stat -c '%G' filename
```

> You can also use the stat command to check group owner:

```
stat -c '%U' filename
```

### grep

`grep` searches for patterns in the specified `filename` or command output:

```
grep test filename
```

```
ps aux | grep 'command'
```

When we need to search for an expression with more than one word we need to use single quotes:

```
grep 'word1 word2' filename
```

### awk

`awk` filters out the content of a file or a command output:

```sh
awk '{print $1}' filename
```

We pass a string as the first argument representing what we want to display in the command output and the `filename` to filter out the contents. Within the string, we use the keyword `print` followed by whatever we want to print. `awk` will basically look into all lines of the specified `filename` or command output and separate their content in columns, storing these columns within variables in the format `$[number]`. Using the previous example, let's say we have a file text like this:

```
Hello, Cesar!
<br/>
Welcome to the bash world!*
```

If we use the same command as the example above:

```sh
awk '{print $1}' hello
```

We would have the following output:

```
Hello,
Welcome
```

If we use the variable `$2` we would have:

```
Cesar!
to
```

By default, `awk` uses a space as the pattern to separate the columns. We can use the param `-F` to set the separator:

```sh
awk -F : '{print $1} /etc/passwd
```

We know that the `passwd` file has the pattern *root:x:0:0:root:/root:/bin/bash* so the above command would return all line words placed before the first `:`.
We can also use `awk` in a pipping:

```sh
ps aux | grep 'command' | awk '{print $2}'
```

The command above uses `px` to list the processes, then pipe them to grep to filter the ones started by `command` and finally pipe them to `awk` to get the `PID` of the process (that we know is the *second column* of the `ps aux` result).

> It's worth mentioning that we can pass whatever we want to the print command. If we want to use some string to improve the result we achieve this by putting the content between double quotes:

```sh
awk -F : '{print $1 "=>" $7} /etc/passwd
```
