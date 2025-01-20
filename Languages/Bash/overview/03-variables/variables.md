## Variables

We define variables using the following syntax:

```sh
VAR_NAME=var_value
```

See the following example:

```sh
ROLE="admin"
LEVEL=1
```

> To set a string we doesn't need to put the value in quotation marks although it's a good practice.

### Lists

We can create a variable that holds a list using the following syntax:

```sh
LIST=("one" "two" "three")
```

If we try to display the contents of this list like this:

```sh
echo $LIST
```

We can see that only the first value `one` will be printed. If we want to print the whole list, we need to use the following syntax:

```sh
echo ${LIST[@]}
```

If we want to access a value at some index, we can use the following syntax:

```sh
echo ${LIST[0]}
```

In the example above, we're accessing the first value of the list **(index 0)**.