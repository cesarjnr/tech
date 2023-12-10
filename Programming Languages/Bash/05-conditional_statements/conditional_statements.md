## Conditional Statements

### If/Elif/Else

The if/else statement syntax in is:

```sh
if [ condition ]; then
  # if code
else
  # else code
fi
```

The if/elif/else state syntax is:

```sh
if [ condition ]; then
  # if code
elif [ condition ]; then
  # elif code
else
  # else code
fi
```

In the following example, we're collecting the first argument from the command line and checking its value:

```sh
if [ ${1,,} = "admin" ]; then
  echo "You're the boss here. Welcome!"
elif [ ${1,,} = "help" ]; then
  echo "Just enter your role!"
else
  echo "I don't know who you are. But you're not the boss here!"
fi
```

### Case

The case statement syntax is:

```sh
case param in
  first_condition)
    # first condition code
    ;;
  second_condition)
    # second condition code
    ;;
  *)
    # No condition code
esac
```

The following example is the same as the one above but using the case statement:

```sh
case ${1,,} in
  "admin")
    echo "You're the boss here. Welcome!"
    ;;
  "help")
    echo "Just enter your role!"
    ;;
  *)
    echo "I don't know who you are. But you're not the boss here!"
esac
```