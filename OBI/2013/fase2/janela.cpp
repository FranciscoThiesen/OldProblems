#include <cstdio>
int main()
{
    int livre[600] = {0};
    for(int i = 0; i < 3; i++)
    {
        int x;
        scanf("%d", &x);
        for(int j = x; j <= x  +  199;++j )
            livre[j] = 1;
    }
    int ans = 0;
    for(int i = 0; i < 601; i++)
        if(!livre[i])
            ans+= 100;
    printf("%d\n", ans);
    return 0;
}
