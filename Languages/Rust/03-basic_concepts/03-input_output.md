# Input and Output

In order to obtain user input and then print the result as output, we need to bring the `io` input/output library into scope. The `io` library comes from the standard library, known as `std`:

```rust
use std::io;
```

By default, Rust has a set of items defined in the standard library that it brings into the scope of every program. This set is called the *prelude*, and you can see everything in it [in the standard library documentation](https://doc.rust-lang.org/std/prelude/index.html). <br />
If a type you want to use isn't in the prelude, you have to bring that type into scope explicitly with a `use` statement. Using the `std::io` library provides you with a number of useful features, including the ability to accept user input.

## Input

In order to get the user input, we need to create a variable to store it, like this:

```rust
let mut guess = String::new();
```

The function `new` returns a new instance of `String` type. The `String` is a string type provided by the standard library that is a growable, UTF-8 encoded bit of text.
The `::` syntax in the `::new` line indicates that `new` is an associated function of the `String` type. An *associated function* is a function that's implemented on a type, in this case `String`. This `new` function creates a new, empty string. You'll find a `new function` on many types because it's a common name for a function that makes a new value of some kind. <br />
Now we'll call the `stdin` function from the `io` module, which will allow us to handle user input:

```rust
io::stdin()
  .read_line(&mut guess)
```

If we hadn't imported the `io` library with `use std::io;` at the beginning of the program, we could still use the function by writing this function call as `std::io::stdin`. The `stdin` function returns an instance of `std::io::Stdin`, which is a type that represents a handle to the standard input for your terminal.
Next, the line `.read_line(&mut guess)` calls the `read_line` method on the standard input handle to get input from the user. We're also passing `&mut guess` as the argument to `read_line` to tell it what string to store the user input in. The full job of `read_line` is to take whatever the user types into standard input and append that into a string (without overwriting its contents), so we therefore pass that string as an argument. The string arguments needs to be mutable so the method can change the string's content. <br />
The `&` indicates that this argument is a *reference*, which gives you a way to let multiple parts of your code access one piece of data without needing to copy that data into memory multiple times. References are a complex feature, and one of Rust's major advantages in how safe and easy it is to use references. For now, we just need to know is that, like variables, references are immutable by default. Hence, you need to write `&mut guess` rather than `&guess` to make it mutable.

### Handling Potential Failure with `Result`

```rust
io::stdin()
  .read_line(&mut guess)
  .expect("Failed to read line");
```

As mentioned earlier, `read_line` puts whatever the user enters into the string we pass to it, but it also returns a `Result` value. `Result` is an `enumeration`, ofer called *enum*, which is a type that can be in one of multiple possible states. We call each possible state a *variant*. The purpose of these `Result` types is to encode error-handling information. <br/>
`Result`'s variants are `Ok` and `Err`. The `Ok` variant indicate the operation was successful, and inside `Ok` is the successfully generated value. The `Err` variant means the operation failed, and `Err` contains information about how or why the operation failed. <br />
Values of the `Result` type, like values of any type, have methods defined on them. An instance of `Result` has an `expect` method that you can call. If this instance of `Result` is an `Err` value, `expect` will cause the program to crash and display the message that you passed as an argument to `expect`. If the `read_line` method returns an `Err`, it would likely be the result of an error coming from the underlying operating system. If this instance of `Result` is an `Ok` value, `expect` will take the return value of that `Ok` is holding and return just that value to you so you can use it. In this case, that value is the number of bytes in the user's input. <br />
If you don't call `expect`, the program will compile, but you'll get a warning.

## Output

```rust
println!("You guessed: {}", guess);
```

This line prints the string that now contains the user's input. The `{}` set of curly brackets is a placeholder. When printing the value of a variable, the variable name can go inside the curly brackets. When printing the resul of evaluating an expression, place empty curly brackets in the format string, then follow the format string with a comma-separated list of expressions to print in each empty curly bracket placeholder in the same order:

```rust
let x = 5;
let y = 10;

println!("x = {x} and y + 2 = {}", y + 2);
```

This code would print `x = 5 and y + 2 = 12`.