#include "CUnit/Basic.h"
#include "cunit.h"

int init_suite() { return 0; } // Function that runs before all tests in the suite. It must return an integer
int clean_suite() { return 0; } // Function that runs after all tests in the suite. It must return an integer

void sum_test() { // The test function. It's good practice its name to finish with _test. In this case, we are testing a function called "sum"
  int result = sum(3, 2);

  CU_ASSERT_EQUAL(result, 5); // One of CUnit's assertion functions, which tests the equality of two values
}

int main() { // The main function is responsible for setting up the test suite
  /*
    Every test suite must be registered in the repository. In this case, if the result of initializing the repository is different than 0, which is the code for success, we return the result of the CU_get_error function, which will be the 
    description of the thrown error
  */
  if (CUE_SUCCESS != CU_initialize_registry()) {
    return CU_get_error();
  }

  CU_pSuite pSuite = NULL; // Declare the suite variable

  pSuite = CU_add_suite("sum", init_suite, clean_suite); // Create the suite. We must pass a suite name and the initialize and clean functions that we declared earlier

  if (pSuite == NULL) { // If the CU_add_suite call fails it will return NULL. So, if it's the case, we clean up the registry and return the description of the thrown error
    CU_cleanup_registry();

    return CU_get_error();
  }

  if (CU_add_test(pSuite, "Should sum 3 and 2", sum_test) == NULL) { // Here we're adding a test to the suite. If this fails, it will return NULL. So, if it's the case, we clean up the registry and return the description of the thrown error
    CU_cleanup_registry();

    return CU_get_error();
  }

  CU_basic_set_mode(CU_BRM_VERBOSE); // Set the types of log that will be printed. Here, we're using the verbose mode, which will give us much more detail
  CU_basic_run_tests(); // Runs all tests in all registered suites
  CU_cleanup_registry(); // Clean up the registry

  return CU_get_error();
}
