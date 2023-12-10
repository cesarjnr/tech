### Loops

### For

The foor loop syntax is:

```sh
for item in list
do
  # loop code
done
```

In the following example, we're iterating over a list of strings and printing each of its items:

```sh
LANGUAGES=("bash" "javascript" "python")

for item in ${LANGUAGES[@]}
do
  echo $item
done
```

> The `item` is a variable used to hold the current value being iteraded. It can be any name you want like `i` as we see as a pattern in a lot of other languages.