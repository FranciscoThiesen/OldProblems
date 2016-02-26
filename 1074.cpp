#include <cstdio>
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    {
        int x;
        scanf("%d", &x);
        if(x == 0)
            printf("NULL\n");
        else if(x%2 == 0)
        {
            if(x > 0)
                printf("EVEN POSITIVE\n");
            else
                printf("EVEN NEGATIVE\n");
        }
        else
        {
            if(x>0)
                printf("ODD POSITIVE\n");
            else
                printf("ODD NEGATIVE\n");
        }
    }
    return 0;
}
