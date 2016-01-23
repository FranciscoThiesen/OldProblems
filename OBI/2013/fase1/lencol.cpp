#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int a,b,c,d,e,f;
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
    if(a*b + c*d >= e*f)
        printf("S\n");
    else
        printf("N\n");
    return 0;
}
