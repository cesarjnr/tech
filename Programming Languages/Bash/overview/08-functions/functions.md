# Functions

Functions are defined using the following syntax:

```sh
foo() {
  # code
}
```

And they can be called using the following syntax:

```sh
foo
```

## Parameters

We can access positional arguments within the function without explicitly defining it:
```sh
foo() {
  echo Hello $1 $2
}

foo "Cesar" "Junior"
```

We can also use the arguments we receive from the command line:

```sh
foo() {
  echo Hello ${1:-unknown} ${2:-unknown}
}

foo $1 $2
```

Then we can just pass the arguments as we normally do when we call the script:

```
./functions.sh Cesar Junior
```

## Function Variables

By default, variables defined within the scope of a function are global. To make them local we can use the `local` keyword:

```sh
foo() {
  local bar="bar"
}
```

## Exit Codes

Bash uses a special variable `$?` which holds the exit code of the last command (or function) executed either through the terminal or vial script. If the function successfully runs this variable will hold `0` by default, which is the code used to indicate the function successfully ran. But we can also explicitly return a code within our functions:

```sh
foo() {
  if [ ${1,,} = "admin" ]; then
    return 0
  else
    return 1
  fi
}

foo $1

if [ $? = 0 ]; then
  echo "Welcome $1!"
else
  echo "Unknown user"
fi
```

In the above example, after the function `foo` ran, we checked whether the value of `$?` is `0` or not.