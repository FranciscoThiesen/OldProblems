#include <stdio.h>
int main()
{
    int x;
    int aldo;
    int beto;
    int a,b;
    int i;
    int t = 1;
    while(scanf("%d", &x) != 0)
    {
        if(x == 0)
            break;
        aldo = 0;
        beto = 0;
        for(i = 0; i < x; ++i)
        {
            scanf("%d %d", &a, &b);
            aldo += a;
            beto += b;
        }
        if(aldo > beto)
            printf("Teste %d\nAldo\n\n", t);
        else
            printf("Teste %d\nBeto\n\n", t);
        t++;
    }
    return 0;
}
