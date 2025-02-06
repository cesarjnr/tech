# Data Types

Every value in Rust is of a certain *data type*, which tells Rust what kind of data is being specified so it knows how to work with that data. We'll look at two data type subsets: *scalar* and *compound*.
Keep in mind that Rust is a *statically typed* language, which means that it must know the types of all variables at compile time. The compiler can usually infer what type we want to use based on the value and how we use it.

## Scalar Types

A *scalar type* represents a single value. Rust has four primary scalar types: **integers**, **floating-point numbers**, **Booleans**, and **characters**.

### Integer Types

An *integer* is a number without a fractional component. One example an integer type would be the `u32`. This type declaration indicates that the value it's associated with should be an unsigned integer (signed integer types start with `i` instead of `u`) that takes up 32 bits of space. The following table shows the built-in integer types in Rust. We can use any of these variants to declare the type of an integer value.

| Length  | Signed | Unsigned |
| ------- | ------ | -------- |
| 8-bit   | i8     | u8       |
| 16-bit  | i16    | u16      |
| 32-bit  | i32    | u32      |
| 64-bit  | i64    | u64      |
| 128-bit | i128   | u128     |
| arch    | isize  | usize    |

Each variant can be either signed or unsigned and has an explicit size. *Signed* and *unsigned* refer to whether it's possible for the number to be negative - in other words, whether the number needs to have a sign with it (signed) or whether it will only ever be positive and can therefore be represented without a sign (unsigned).
Each signed variant can store numbers from **-(2 ^ (n - 1))** to **2 ^ (n - 1) - 1** inclusive, where *n* is the number of bits that variant uses. So an `i8` can store numbers from **-(2 ^ 7)** to **2 ^ 7 - 1**, which equals **-128** to **127**.
Unsigned variants can store numbers from **0** to **2 ^ n - 1**, so a `u8` can store numbers from **0** to **2 ^ 8 -1**, which equals to **0** to **255**.
Additionally, the `isize` and `usize` types depend on the architecture of the computer your program is running on, which is denoted in the table as "arch": 64 bits if you're on a 64-bit architecture and 32 bits if you're on a 32-bit architecture.
So how do you know which type of integer to use? If you're unsure, Rust's defaults are generally good places to start: integer types default to `i32`. The primary situation in which you'd use `isize` or `usize` is when indexing some sort of collection.

### Floating-Point Types

Rust also has two primitive types for *floating-point numbers*, which are numbers with decimal points. Rust's floating-point types are `f32` and `f64`, which are 32 bits and 64 bits in size, respectively. The default type is `f64` because on modern CPUs, it's roughly the same speed as `f32` but is capable of more precision. All floating-point types are signed.
Floating-point numbers are represented according to the IEEE-754 standard. The `f32` type is a single-precision float, and `f64` has double precision.

### The Boolean Type

As in most other programming languages, a Boolean type in Rust has two possible values: `true` and `false`. Booleans are one byte in size. The Boolean type in Rust is specified using `bool`.

### The Character Type

Rust's `char` type is the language's most primitive alphabetic type. We need to specify `char` literals with single quotes, as opposed to string literals, which use double quotes.
Rust's `char` type is four bytes in size and represents a Unicode Scalar Value, which means it can represent a lot more than just ASCII. Accented-letters; Chinese, Japanese, and Korean characters; emoji; and zero-width spaces are all valid `char` values in Rust. Unicode Scalar Values range from `U+0000` to `U+D7FF` and `U+E000` to `U+10FFFF` inclusive.

## Compound Types

*Compound Types* can group multiple values into one type. Rust has two primitive compound types: **tuples** and **arrays**.

### The Tuple Type

A *tuple* is a general way of grouping together a number of values with a variety of types into one compound type. Tuples have a fixed length: once declared, they cannot grow or shrink in size.
We create a tuple by writing a comma-separated list of values inside parentheses. Each position in the tuple has a type, and the types of the different values in the tuple don't have to be the same.
We've added optional type annotations in this example:

```rust
fn main() {
  let tup: (i32, f64, u8) = (500, 6.4, 1);
}
```

To get the individual values out of a tuple, we can use pattern matching to destructure a tuple value, like this:

```rust
fn main() {
  let tup = (500, 6.4, 1);
  let (x, y, z) = tup;
}
```

We can also access a tuple element directly by using a period `.` followed by the index of the value we want to access:

```rust
fn main() {
  let tup = (500, 6.4, 1);
  let five_hundred = x.0;
  let six_point_four = x.1;
  let one = x.2;
}
```

The tuple without any values has a special name, *unit*. This value and its corresponding type are both written `()` and represent an empty value or an empty return type. Expressions implicitly return the unit value if they don't return any other value.

### The Array Type

Another way to have a collection of multiple values is with an *array*. Unlike a tuple, every element of an array must have the same type. Unlike arrays in some other languages, arrays in Rust have a fixed length.
We write the values in array as a comma-separated list inside square brackets:

```rust
fn main() {
  let arr = [1, 2, 3, 4, 5];
}
```

Arrays are useful when you want your data allocated on the stack, the same as the other types we have seen so far, rather than the heap or when you want to ensure you always have a fixed number of elements. An array isn't flexible as the vector type, though. A *vector* is a similar collection type provided by the standard library that is allowed to grow or shrink in size. If you're unsure whether to use an array or vector, chances are you should use a vector.
However, arrays are more useful when you know the number of elements will not need to change. For example, if you were using the names of the month in a program, you would probably use an array rather than a vector because you know it will always contain 12 elements.
You write an array's type using square brackets with the type of each element, a semicolon, and then the number of elements in the array:

```rust
fn main() {
  let arr: [i32, 5] = [1, 2, 3, 4, 5];
}
```

You can also initialize an array to contain the same value for each element by specifying the initial value, followed by a semicolon, and then the length of the array in square brackets:

```rust
let arr = [3; 5];
```

The array named `arr` will contain `5` elements that will all be set to the value `3` initially. This is the same as writing `let arr = [3, 3, 3, 3, 3];` but in a more concise way.
We can access elements of an array using indexing:

```rust
fn main() {
  let arr = [1, 2, 3, 4, 5];
  let first = a[0];
  let second = a[1];
}
```