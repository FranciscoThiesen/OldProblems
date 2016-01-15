#include <cstdio>
#include <cmath>

int main()
{
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; ++i)
    {
        int total = 0;
        int max, min;
        scanf("%d %d", &min, &max);
        for(float j = ceil(sqrt(min)); j < 100000000; ++j)
        {
            if(j*j >= min && j*j <= max)
                total++;
            else
                break;
        }
        printf("%d\n",total);
    }
    return 0;
}
