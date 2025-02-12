# Conditional Statements

## *if* Expresions

An `if` expression allows you to branch your code depending on conditions. You provide a condition then state, "If this condition is met, run this block of code. If the condition is not met, do not run this block of code."

```rust
fn main() {
  let number = 3;

  if number < 5 {
    println!("condition was true");
  } else {
    println!("condition was false");
  }
}
```

All `if` expressions start with the keyword `if`, followed by a condition. In this case, the condition checks whether or not the variable `number` has a value less than 5. We place the block of code to execute if the condition is `true` immediately after the condition inside curly brackets. Blocks of code associated with the condition in `if` expressions are sometimes called *arms*.  
Optionally, we can also include an `else` expression, which we chose to do here, to give the program an alternative block of code to execute should the condition evaluate to `false`. If you don't provide an `else` expression and the condition is `false`, the program will just skip the `if` block and move on to the next bit of code.  
It's also worth noting that the condition in this code *must* be a `bool`. If the condition isn't a `bool`, we'll get an error. For example, try running the following code:

```rust
fn main() {
  let number = 3;

  if number {
    println!("number was three");
  }
}
```

The `if` condition evaluates to a value of `3` this time, and Rust throws an error:

```
$ cargo run
    Compiling branches v0.1.0 (file:///your_file_path)
error[E0308]: mismatched types
  --> src/main.rs:4:8
   |
4  |     if number {
   |        ^^^^^^ expected `bool`, found integer
}
```

The error indicates that Rust expected a `bool`, but got an integer. Unlike languages such as Ruby and JavaScript, Rust will not automatically try to convert non-Boolean types to a Boolean. You must be explicit and always provide `if` with a Boolean as its condition.

## Handling Multiple Conditions with *else if*

You can use multiple conditions by combining `if` and `else` in an `else if` expression. For example:

```rust
fn main() {
  let number = 6;

  if number % 4 == 0 {
    println!("number is divisible by 4");
  } else if number % 3 == 0 {
    println!("number is divisible by 3");
  } else if number % 2 == 0 {
    println!("number is divisible by 2");
  } else {
    println!("number is not divisible by 4, 3, or 2");
  }
}
```

When this program executes, it checks each `if` expression in turn and executes the first body for which the condition evaluates to `true`. Note that even though 6 is divisible by 2, we don't see the output `number is divisible by 2`, nor do we see the `number is not divisible by 4, 3, or 2` text from the `else` block. That's because Rust only executes the block for the first `true` condition, and once it finds one, it doesn't even check the rest.  
Using too many `else if` expressions can clutter your code, so if you have more than one, you might want to refactor you code. You might want to use a branching construct called `match` we'll see later.

## Using *if* in a *let* Statement

Because `if` is an expression, we can use it on the right side of a `let` statement to assign the outcome to a variable.

```rust
fn main() {
  let condition = true;
  let number = if condition { 5 } else { 6 };

  println!("The value of number is: {number}");
}
```

The `number` variable will be bound to a value based on the outcome of the `if` expression.  
Remember that blocks of code evaluate to the last expression in them, and numbers by themselves are also expressions. In this case, the value of the whole `if` expression depends on which block of code executes. This means the values that have the potential to be results from each arm of the `if` must be the same type. In the example above, the results of both the `if` arm and the `else` arm were `i32` integers. If the types are mismatched, as in the following example, we'll get an error:

```rust
fn main() {
  let condition = true;
  let number = if condition { 5 } else { "six" };

  println!("The value of number is: {number}");
}
```

When we try to compile this code, we'll get an error. The `if` and `else` arms have value types that are incompatible, and Rust indicates exactly where to find the problem in the program:

```
error[E0308]: `if` and `else` have incompatible types
  --> src/main.rs:4:44
   |
4  |      let number = if condition { 5 } else { "six" };
   |                                  -          ^^^^^ expected integer, found `&str`
   |                                  |
   |                                  expected because of this
```

The expression in the `if` block evaluates to an integer, and the expression in the `else` block evaluates to a string. This won't work because variables must have a single type, and Rust needs to know at compile time what type the `number` variable is. Knowing the type of `number` lets the compiler verify the type is valid everywhere we use `number`.