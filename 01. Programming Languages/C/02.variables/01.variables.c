#include <stdio.h>

int main() {
    int var1;
    var1 = 1;

    int var2 = 2;
    int var3;
    var3 = var2;

    int var4, var5, var6;
    var4 = var5 = var6 = 456;

    printf("%d", var1);
    printf("%d", var2);
    printf("%d", var3);
    printf("%d", var4);
    printf("%d", var5);
    printf("%d", var6);

    return 0;
}