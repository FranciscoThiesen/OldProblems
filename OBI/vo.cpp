#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a = 1;
    int t = 1;
    while(true)
    {
        scanf("%d", &a);
        if(a == 0)
            break;
        printf("Teste %d\n", t);
        t++;
        int dif = 0;
        for(int i = 0; i < a; ++i)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            dif += x-y;
            printf("%d\n", dif);
        }
        printf("\n");
    }
    return 0;
}
