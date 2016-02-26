#include <cstdio>
int main()
{
    int a;
    scanf("%d", &a);
    int total= 0;
    while(total < 6)
    {
        if(a%2 == 1)
        {
            total++;
            printf("%d\n", a);
        }
        a++;
    }
}
