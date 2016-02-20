#include <cstdio>
#include <cmath>

int main()
{
    int j, p;
    scanf("%d%d", &j, &p);
    int total = 0;
    for(int i = 0; i < j;i++)
    {
        int a = true;
        for(int k = 0; k < p; k++)
        {
            int x;
            scanf("%d", &x);
            if(x <= 0)
            {
                a = false;
            }
        }
        if(a == true)
            total++;
    }
    printf("%d\n", total);
    return 0;
}
