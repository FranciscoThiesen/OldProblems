#include <cstdio>
int main()
{
    int a;
    int max = -10000000;
    int pos;
    for(int i = 0; i < 100; ++i)
    {
        scanf("%d", &a);
        if(a > max)
        {
            max = a;
            pos = i+1;
        }
    }
    printf("%d\n%d\n", max, pos);
    return 0;
}
