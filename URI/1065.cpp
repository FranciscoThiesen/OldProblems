#include <stdio.h>
int main()
{
    int a,b,c,d,e;
    int total = 0;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    if(a%2 == 0)
        total++;
    if(b%2 == 0)
        total++;
    if(c%2 == 0)
        total++;
    if(d%2 == 0)
        total++;
    if(e%2 == 0)
        total++;
    printf("%d valores pares\n", total);
    return 0;

}
