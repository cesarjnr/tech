# Functions

Functions are prevalent in Rust code. You've already seen one of the most important functions in the language: the `main` function, which is the entry point of many programs. You've also seen the `fn` keyword, which allows you to declare new functions. <br />
Rust code use *snake cae* as the convenient style for function and variable names, in which all letters are lowercase and underscore separate words. Here's a program that contains an example function definition:

```rust
fn main() {
  println!("Hello, world!");

  another_function();
}

fn another_function() {
  println!("Another function.");
}
```

We define a function in Rust by entering `fn` followed by a function name and a set of parentheses. The curly brackets tell the compiler where the function body begins and ends. <br />
We can call any function we've defined by entering its name followed by a set of parentheses. Because `another_function` is defined in the program, it can be called from inside the `main` function. Note that we defined `another_function` *after* the `main` function in the source code; we could have defined it before as well. Rust doesn't care where you define your functions, only that they're defined somewhere in a scope that can be seen by the caller.

## Parameters

We can define functions to have *parameters*, which are special variables that are part of a function's signature. When a function has parameters, you can provide it with concrete values for those parameters. Technically, the concrete values are called *arguments*, but in casual conversation, people tend to use the words *parameter* and *argument* interchangeably for either the variable in a function's definition or the concrete values passed in when you call a function.

```rust
fn main() {
  another_function(5);
}

fn another_function(x: i32) {
  println!("The value of x is {x}");
}
```

In function signatures, you *must* declare the type of each parameter. This is a deliberate decision in Rust's design: requiring type annotations in function definitions means the compiler almost never needs you to use them elsewhere in the code to figure out what type you mean. The compiler is also able to give more helpful error messages if it knows what types the function expects. <br />
When defining multiple parameters, separate the parameter declarations with commas, like this:

```rust
fn main() {
  print_labeled_measurement(5, 'h');
}

fn print_labeled_measurement(value: i32, unit_label: char) {
  println!("The measurement is: {value}{unit_label}");
}
```

## Statements and Expressions

Function bodies are made up of a series of statements optionally ending in an expression. So far, the functions we've covered haven't included an ending expression, but you have seen an expression as part of a statement. Because Rust is an expression-based language, this is an important distinction to understand. Other languages don't have the same distinctions, so let's look at what statements and expressions are and how their differences affect the bodies of functions.

- **Statements** are instructions that perform some action and do not return a value.
- **Expressions** evaluate to a resultant value.

We've actually already used statements and expressions. Creating a variable and assigning a value to it with the `let` keyword is a statement. `let y = 6;` is a statement.

```rust
fn main() {
  let y = 6;
}
```

Function definitions are also statements; the entire preceding example is a statement in itself. (As we will see below, *calling* a function is not a statement.)  
Statements do not return values. Therefore, you can't assign a `let` statement to another variable, as the followig code tries to do; you'll get an error:

```rust
fn main() {
  let x = (let y = 6);
}
```

The `let y = 6` statement does not return a value, so there isn't anything for `x` to bind to. This is different from what happens in other languages, such as C and Ruby, where the assignment returns the value of the assignment. In those languages, you can write `x = y = 6` and have both `x` and `y` have the value `6`; that is not the case in Rust.  
Expressions evaluate to a value and make up most of the rest of the code that you'll write in Rust. Consider a math operation, such as `5 * 6`, which is an expression that evaluates to the value `11`. Expressions can be part of statements: the `6` in the statement `let y = 6;` is an expression that evaluates to the value `6`. Calling a function is an expression. Calling a macro is an expression. A new scope block created with curly brackets is an expression, for example:

```rust
fn main() {
  let y  {
    let x = 3;

    x + 1
  }

  println!("The value of y is: {y}");
}
```

This expression:

```rust
{
  let x = 3;

  x + 1
}
```

is a block that, in this case, evaluates to `4`. That value gets bound to `y` as part of the `let` statement. Note that the `x + 1` line doesn't have a semicolon at the end, which is unlike most of the lines you've seen so far. Expressions do not include ending semicolons. If you add a semicolon to the end of an expression, you turn it into a statement, and it will then not return a value.

## Functions with Return Values

Functions can return values to the code that calls them. We don't name return values, but we must declare their type after an arrow (`->`). In Rust, the return value of the function is synonymous with the value of the final expression in the block of the body of a function. You can return early from a function by using the `return` keyword and specifying a value, but most functions return the last expression implicitly. Here's an example of a function that returns a value:

```rust
fn five() -> i32 {
  5
}

fn main() {
  let x = five();

  println!("The value of x is: {x}");
}
```

There are no function calls, macros, or even `let` statements in the `five` function - just the number `5` by itself. That's a perfectly valid function in Rust. Note that the function's return type is specified too, as `-> i32`.  
Let's look at another example:

```rust
fn main() {
  let x = plus_one(5);

  println!("The value of x is: {x}");
}

fn plus_one(x: i32) -> i32 {
  x + 1
}
```

Running this code will print `The value of x is: 6`. But if we place a semicolon at the end of the line containing `x + 1`, changing it from an expression to a statement, we'll get an error:

```rust
fn main() {
  let x = plus_one(5);

  println!("The value of x is: {x}");
}

fn plus_one(x: i32) -> i32 {
  x + 1;
}
```

Compiling this code produces an error, as follows:

```
$ cargo run
    Compiling functions v0.1.0 (file://your_file_path)
error[0308]: mismatched types
  --> src/main.rs:7:24
  |
7 | fn plus_one(x: i32) -> i32 {
  |    --------            ^^^ expected `i32`, found `()`
  |    |
  |    implicitly returns `()` as its body has no tail or `return` expression
8 |     x + 1;
  |          - help: remove this semicolon to return this value

For more information about this error, try `rust --explain E0308`.
error: could not compile `functions` (bin "functions") due to 1 previous error
```

The main error message, `mismatched types`, reveals the core issue with this code. The definition of the function `plus_one` says that it will return an `i32`, but statements don't evaluate to a value, which is express by `()`, the unit type. Therefore, nothing is returned, which contradicts the function definition and results in an error. In this output, Rust provides a message to possibly help rectify this issue: it suggests removing the semicolon, which would fix the error.