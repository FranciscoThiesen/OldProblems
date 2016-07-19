#include <cstdio>
int main()
{
    for(int i = 0; i < 10; ++i)
    {
        int a;
        scanf("%d", &a);
        if( a <= 0 )
            printf("X[%d] = 1\n", i);
        else
            printf("X[%d] = %d\n", i, a);
    }
    return 0;
}
