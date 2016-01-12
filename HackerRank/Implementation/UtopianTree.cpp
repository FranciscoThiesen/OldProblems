#include <cstdio>

int main()
{
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; ++i)
    {
        long long int size = 1;
        int cycles;
        scanf("%d", &cycles);
        for(int k = 1; k <= cycles; k++)
        {
            if(k%2 != 0)
                size *= 2;
            else
                size++;
        }
        printf("%lld\n", size);
    }
    return 0;
}
