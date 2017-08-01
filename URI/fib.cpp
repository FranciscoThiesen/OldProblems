#include <cstdio>
#include <iostream>
int main()
{
    int aux[40];
    int fib[40];
    aux[0] = 1;
    aux[1] = 1;
    aux[2] = 2;
    aux[3] = 4;
    fib[0] = 0;
    fib[1] = 1;
    fib[2] = 1;
    fib[3] = 2;
    for(int i = 4; i < 40; ++i)
    {
        aux[i] = aux[i-1] + aux[i-2] + 2;
        fib[i] = fib[i-1] + fib[i-2];
        printf("o aux[%d] eh %d\n",i, aux[i]);
        
    }
    int t;
    scanf("%d", &t);
    for(int test = 0; test < t; test++)
    {
        int a;
        scanf("%d", &a);
        printf("fib(%d) = %d calls = %d\n",a,aux[a],fib[a]);
    }
    return 0;
}
