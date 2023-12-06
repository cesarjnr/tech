## Parameter Expansion

In bash, *parameter expansion* is a feature that allows you to manipulate the value of a variable. It's often used to modify the value of a variable or to extract information from it.

### Syntax

The basic syntax of a parameter expansion is the following:

```
${variable}
```

So, for example:

```sh
name="John"
echo Hello, ${name}!
```

### Default Value

We can use the operator `:-` to provide a default value for a variable that is unset or empty:

```sh
name=

echo Hello, ${name:-unknown}
```

In the example above, if the variable name is empty, the value `uknown` will be used in the expression.

### Arguments from Command Line

We can use the parameter expansion feature to get positional arguments passed on the command line:

```sh
  echo "Hello ${1}, welcome to the bash world!"
```

In the example above, we're getting the first argument passed to the script with `${1}`. If there was a second argument we would access it by using `${2}`.