#include <math.h>
#include <stdio.h>

int main()
{
    int a, b, c = 1;
    double fuga, captura;
    while(scanf("%d %d %d", &a, &b, &c) != EOF)
    {
        fuga = 12 - a;
        if(c != b)
            captura = 12-b;
        else
            captura = 12-b;
        if(fuga < captura || b > c)
            printf("N\n");
        else
            printf("S\n");
    }
    return 0;
}
