# Repetition Statements

Rust has three kinds of loops: `loop`, `while`, and `for`. Let's try each one.

## Repeating Code with `loop`

The `loop` keyword tells Rust to execute a block of code over and over again forever or until you explicitly tell it to stop.

```rust
fn main() {
  loop {
    println!("again!");
  }
}
```

When we run this program, we'll see `again!` printed over continuously until we stop the program manually. Most terminals support the keyboard shortcut `ctrl + c` to interrupt a program that is stuck in a continual loop.  
Fortunately, Rust also provides a way to break out of a loop using code. You can place the `break` keyword within the loop to tell the program when to stop executing the loop.

```rust
fn main() {
  let mut counter = 0;

  loop {
    if counter == 10 {
      println!("finished!");
      break;
    }

    counter += 1;
  }
}
```

We can also use `continue`, which in a loop tells the program to skip over any remaining code in this iteration of the loop and go to the next iteration.

```rust
fn main() {
  let mut counter = 0;

  loop {
    counter += 1;

    if counter == 10 {
      println!("finished!");
      break;
    }

    if counter % 2 == 0 {
      println!("The counter {counter} is divided by 2");
      continue;
    }

    println!("The counter is: {counter}");
  }
} 
```

In the above examples, we're printing a different message for when the number is divided by 2. If the number is divided by 2 (`if counter % 2 == 0`), the associated block of code will run, print the specific string and immediately stops the current iteration preventing the second `println!` from running.

## Returning Values from Loops

One of the uses of a `loop` is to retry an operation you know might fail, such as checking whether a thread has completed its job. You might also need to pass the result of that operation out of the loop to the rest of your code. To do this, you can add the value you want returned after the `break` expression you use to stop the loop; that value will be returned out of the loop so you can use it, as shown here:

```rust
fn main() {
  let mut counter = 0;

  let result = loop {
    counter += 1;

    if counter == 10 {
      break counter * 2;
    }
  };

  println!("The result is {result}");
}
```

Before the loop, we declare a variable named `counter` and initialize it to `0`, Then we declare a variable named `result` to hold the value returned from the loop. On every iteration of the loop, we add `1` to the `counter` variable, and then check whether the `counter ` is equal to `10`. When it is, we use the `break` keyword with the value `counter * 2`. After the loop, we use a semicolon to end the statement that assigns the value to `result`. Finally, we print the value in `result`, which in this case is `20`.  
You can also `return` from inside a loop. While `break` only exits the current loop, `return` always exits the current function.

## Loop Labels to Disambiguate Between Multiple Loops

If you have loops within loops, `break` and `continue` apply to the innermost loop at that point. You can optionally specify a *loop label* on a loop that you can then use with `break` or `continue` to specify that those keywords apply to the labeled loop instead of the innermost loop. Loop labels must begin with a single quote. Here's an example with two nested loops:

```rust
fn main() {
  let mut count = 0;

  'counting_up: loop {
    println!("count = {count}");

    let mut remaining = 10;

    loop {
      println!("remaining = {remaining}");

      if remaining == 9 {
        break;
      }

      if count == 2 {
        break 'counting_up;
      }

      remaining -= 1;
    }

    count += 1;
  }

  println!("End count = {count}");
}
```

The outer loop has the label `'counting_up`, and it will count up from 0 to 2. The inner loop without a label counts down from 10 to 9. The first `break` that doesn't specify a label will exit the inner loop only. The `break 'counting_up;` statement will exit the outer loop. This code prints:

```
$ cargo run
    Compiling branches v0.1.0 (file:///your_file_path)
count = 0
remaining = 10
remaining = 9
count = 1
remaining = 10
remaining = 9
count = 2
remaining = 10
End count = 2
```

## Conditional Loops with `while`

A program will often need to evaluate a condition within a loop. While the condition is `true`, the loop runs. When the condition ceases to be `true`, the program calls `break`, stopping the loop. It's possible to implement behavior like this using a combination of `loop`, `if`, `else`, and `break`. However, this patter is so common that Rust has a built-in language construct for it, called a `while` loop.

```rust
fn main() {
  let mut number = 3;

  while number != 0 {
    println!("{number}");

    number -= 1;
  }

  println!("LIFTOFF!!!");
}
```

This construct eliminates a lot of nesting that would be necessary if you used `loop`, `if`, `else`, and `break`, and it's clearer. While a condition evaluates to `true`, the code runs; otherwise, it exits the loop.

## Looping Through a Collection with `for`

You can also use the `while` construct to loop over the elements of a collection, such as an array. For example, to print each element in an array:

```rust
fn main() {
  let a = [10, 20, 30, 40, 50];
  let mut index = 0;

  while index < 5 {
    println!("The value is: {}", a[index]);

    index += 1;
  }
}
```

Here, the code counts up through the elements in the array. It starts at index `0`, and then loops until it reaches the final index in the array (that is, when `index < 5` is no longer `true`). Running this code will print every element in the array:

```
$ cargo run
    Compiling branches v0.1.0 (file:///your_file_path)
The value is: 10
The value is: 20
The value is: 30
The value is: 40
The value is: 50
```

All five array values appear in the terminal, as expected. Even though `index` will reach a value of `5` at some point, the loop stops executing before trying to fetch a sixth value from the array.  
However, this approach is error prone; we could cause the program to panic if the index value or test condition is incorrect. For example, if you changed the definition of the `a` array to have four elements but forgot to update the condition to `while index < 4`, the code would panic. It's also slow, because the compiler adds runtime code to perform the conditional check of whether the index is within the bounds of the array on every iteration through the loop.  
As a more concise alternative, you can use a `for` loop and execute some code for each item in a collection. A `for` loop looks like this:

```rust
fn main() {
  let a = [10, 20, 30, 40, 50];

  for element in a {
    println!("The value is: {element}");
  }
}
```

When we run this code, we'll see the same output as above. More importantly, we've now increased the safety of the code and eliminated the chance of bugs that might result from going beyond the end of the array or not going far enough and missing some items.  
Using the `for` loop, you wouldn't need to remember to change any other code if you changed the number of values in the array, as you would with `while`.  
The safety and conciseness of `for` loops make them the most commonly used loop construct in Rust. Even in situations in which you want to run some code a certain number of times, as in the countdown example that used a `while` loop, most Rustaceans would use a `for` loop. The way to do that would be use `Range`, provided by the standard library, which generates all numbers in sequence starting from one number and ending before another number.  
Here's what the countdown would look like using a `for` loop and another method we've not yet talked about, `rev`, to reverse the range:

```rust
fn main() {
  for number in (1..4).rev() {
    println!("{number}");
  }

  println!("LIFTOFF!!!");
}
```