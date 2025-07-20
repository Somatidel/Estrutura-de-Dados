#include<stdio.h>

int fibonacci(int n)
{
    return n<3 ? 1 : fibonacci(n-1) + fibonacci(n-2);
}

int fibonacci2(int n) {
    if (n < 1) return 0;
    if (n == 1 || n == 2) return 1;

    int a = 1, b = 1, c;
    for (int i = 3; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    return b;
}

void main()
{
    printf("[%d]", fibonacci2(100));
}
