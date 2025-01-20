#include <stdio.h>

int main() {
    int two = 2, three = 3, six = 6;
    int result = (two + three) * six / three;
    printf("I am new to programming but I know how to write arithmetic expressions like this: (%d + %d) * %d / %d", two, three, six, three);
    printf("And the result of this expression is: %d", result);

    return 0;
}