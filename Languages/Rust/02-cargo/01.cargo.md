# Cargo

## Compiling with `cargo`

In theory, `rustc` is all we need to compile Rust files. In practice, Rust comes with some convenient things that will make development easier, and as you will see later, safer.
Rust comes with a tool called `cargo`. If you are used to the Javascript ecosystem, then `cargo` can be best described as Rust\`s equivalent to `npm`. It helps you manage your dependencies, compile the code and other things. With Rust being installed correctly, you can type the following command to invoke `cargo`:

```
cargo --version
````

In a directory where you'd like to initialize a `cargo` application, type the following:

```
cargo init myapp --vcs none
```

Using `--vcs none` part ensures that you init the application without `git` support. If you want to use `git` in the application, omit this flag.
`cargo` claims success by telling you the following:

```
Created binary (application) package
```

It created a new folder called `myapp`, populated with some files. We will go through most of them in a bit but the most interesting one is a file called `main.rs` in a folder called `src`.
To use `cargo` to compile this application, make sure you're in the `myapp` folder and then run:

```
cargo build
```

Running this command adds a few more files (which we'll look at in a second) and puts an executable called `hello_world` into the folder `target/debug`. Let's execute `./target/debug/hello_world` to convince ourselves that this program will actually run.

## `cargo`\'s Extra Files (and Features)

Our `hello_world` directory now contains a whole bunch of things (some of them hidden, the specifics might look different on your machine):

1. A folder called `src`, containing the `main.rs` file.
2. Two files named `Cargo.toml` and `Cargo.lock`.
3. A folder called `target` with some hidden files in it and a folder called `debug`. That folder contains more files and folders and our executable.

### The `src` Folder

The `src` folder is where all our source files will live. Right now, we only have one. As the application grows, there will be more.

### `Cargo.toml` and `Cargo.lock`

`Cargo.toml` follows a config format called `TOML` and is used to tell the compiler a few things about the code it's supposed to compile.
`cargo` also does dependency management for us, and the `Cargo.toml` file will hold these dependencies for us. The `Cargo.lock` file is part of that dependency management and ensures that dependencies stay consistent in different environments.

### The `target` Folder

`cargo` supports multiple so-called **build targets**. The one that is used as the default is `debug`, meaning that the final executable is mainly targeted at us, the developers, and not at actual, real end customers.
Another valid target would be `release`, which is the opposite: something to put into the hands of the customers, not only for developers.
To build a release version, run:

```
cargo build --release
```

Once you do, you will notice that another folder appeared in the `target` folder, aptly named `release`.
There are several types of programming errors where Rust assumes that you really did not do this on purpose. If a `debug` build encounters this kind of error, the program crashes, which is the most extreme thing Rust can do to tell you just how wrong you've been. But Rust does have a way to recover from these errors and can continue. With wrong results though, but it can continue, and assuming that for an end user a wrong result is bad, a crash is worse. So the same error would not crash the `release` build.
Also, the compiler can perform various optimizations under the hood to make the result faster. But these optimizations take time and make compliation slower. Who compiles all the time? Developers. Who compiles never? Users. Therefore, `debug` builds disable the optimizations to prioritize speed in development, and `release` builds enable them to prioritize speed in execution.
Finally, the executable does contain code other than just the code you wrote, and Rust adds information to the `debug` build which will help you debug any issues quicker. This information isn't needed for customers, therefore it can be excluded from the `release` build.
`cargo` also tells us as much during compilation. The final line for a `debug` release reads like this:

```
Finished `dev` profile [unoptimized + debuginfo] target(s) in 0.11s
```

This tells us that the build is not optimized and contains debug info.
The `release` build, on the other hand, ends its compilation with:

```
Finished `release` profile [optimized] target(s) in 0.67s
```

This tells us that no debug info is contained, and that it's an optimized build.

## Build Artefacts

So that explains the folders, but what about the stuff in there that is not related to our application? Let's investigate something to further our understanding.
Back in the terminal, run the following commands in order:

```
cargo clean
cargo build
cargo build
```

The first command deletes the `target` directory. The second command runs as before. During the third one, though, `cargo` does not output a line starting with `Compilling...`, as it did before. That is because `cargo` can tell that the current version of `main.rs` has already been compiled. If the `main.rs` was not modified since the last compilation, then `cargo` doesn't bother running the compilation again. If `main.rs` was changed, then `cargo` re-compiles `main.rs`. Once your codebase grows, this will become more useful, as most of the components shouldn't need to be recompiled over and over when you're only making changes to one component's source code.
Most of the extra files in the `target` directory are **build artefacts** which enable `cargo` to do subsequent compilations more quickly.

## Compiling and Running

Since it's very common that you want to compile and run your program, `cargo` combines both steps with the command `cargo run`.