#include <stdio.h>

int main() {
    // Question 01. What is the output of the following fragment?

    printf("%d", printf("%s", "Hello World!"));

    // Explanation: printf, in addition to printing out the string, also returns the number of characters that were successfully printed on the screen

    printf("\n\n");

    // Question 02. What is the output of the following fragment?

    printf("%10s", "Hello");

    /* Explanation: We can use numbers in the string placeholder to specify how much characters we want to be printed on the screen. So, in the above example, the string 
    'Hello' has 5 characters but we asked the printf function to print a string with 10 characters, so it appends 5 characters to the beginning of the string to complete 
    10 characters */

    printf("\n\n");

    // Question 03. What is the output of the following fragment?

    char c = 255;
    c = c + 10;
    printf("%d", c);

    /* Explanation: As we know, variables of type char has a length of 8 bits which gives us a range from 0 to 255 of possible values. When we try to exceed this range the 
    value is "reset", so 255 + 10 results in 9. */

    /* Question 04. Which of the following statement/statements is/are correct corresponding to the definition of integer:
        I.   signed int i;      a) Only I and V are correct
        II.  signed i;          b) Only I is correct
        III. unsigned i;        c) All are correct
        IV.  long i;            d) Only IV, V, VI are correct
        V.   long int i;
        VI.  long long i;

        Explanation: Letter d is the correct answer because although we are not implicitly using the int keyword, the compiler automatically converts the variable to int 
        based on the keywords signed, unsigned and long.
    */

    printf("\n\n");

    // Question 05. What does the following fragment?
    unsigned i = 1;
    int j = -4;
    printf("%u", i+j);

    /* 1 - 4 is equal to -3 but we printed out the unsigned representation of that sum, so internally the computer will first make the process we already know, which 
    is to convert from complement of 2 to the default representation.
    An int variable can be 2 bytes or 4 bytes depending on the computer, so the answer will vary from machine to machine. -3 in a variable of 2 (16 bits) or 4 bytes 
    (32 bits) will have the same binary representation as some other unsigned value. */

    printf("\n\n");

    return 0;
}