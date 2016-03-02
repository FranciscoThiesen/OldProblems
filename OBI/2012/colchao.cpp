#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);
    int h, l;
    scanf("%d %d", &h, &l);
    int tot = 0;
    if(a <= h && a <= l)
        tot++;
    else if(b <= h && b <= l)
        tot++;
    else if(c <= h && c <= l)
        tot++;
    if(a <= h || a <= l)
        tot++;
    else if(b <= h || b<= l )
        tot++;
    else if(c <= h || c <= l)
        tot++;
    if(tot == 2)
        printf("S\n");
    else
        printf("N\n");
    return 0;
}
