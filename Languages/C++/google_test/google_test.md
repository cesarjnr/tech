#### Installation

1. Install CMake (if you haven't already):

```sh
  sudo apt-get install cmake
```

2. Set up the CMake config for GoogleTest:

It's a good practice create a folder for the library CMake configs. So, create a directory called googletest and a file called CMakeLists.txt inside of it:

```cmake
  cmake_minimum_required(VERSION 3.14)
  project(googletest)

  # GoogleTest requires at least C++11
  set(CMAKE_CXX_STANDARD 11)

  include(FetchContent)
  FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
  )
```

After setting up CMakeLists.txt, generate the build files. For that, create a directory called build inside of googletest folder, go into it and run cmake:

```sh
  mkdir build
  cd build
  cmake ..
```

3. Write your tests:

On your project root directory, create a file called hello_test.cpp:

```cpp
  #include <gtest/gtest.h>

  TEST(HelloTest, BasicAssertions) {
    EXPECT_STRNE("hello", "world");
    EXPECT_EQ(7 * 6, 42);
  };
```

4. Set up the CMake config for your project:

Create a CMakeFiles.txt inside of the root directory of your project and add the following lines:

```cmake
  enable_testing()

  add_executable(
    hello_test
    hello_test.cpp
  )

  target_link_libraries(
    hello_test
    gtest_main
  )

  include(GoogleTest)
  gtest_discover_tests(hello_test)
```

After that, generate the build files for your project as well:

```sh
  mkdir build
  cd build
  cmake ..
```

5. Compile and run the tests:

Compile the build files of your project:

```sh
  cmake --buid .
```

And finally, run your tests executing the generated binary file:

```sh
  ./hello_test
```
