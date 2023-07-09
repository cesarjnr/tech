1. Install CUnit framework:

```sh
  sudo apt-get install libcunit1 libcunit1-doc libcunit1-dev
```

2. Compile the necessary files:

```sh
  gcc file_being_tested.c test_file.c -o test_file -lcunit
```

3. Run the test file:

```sh
  ./test_file
```