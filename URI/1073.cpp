#include <cstdio>
#include <cmath>
int main()
{
    int a;
    scanf("%d", &a);
    for(int i = 1; i <=a; ++i)
    {
        if(i%2 == 0)
            printf("%dˆ2 = %d\n", i, i*i);
    }
    return 0;
}
