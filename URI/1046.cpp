#include <cstdio>
int main()
{
    int a,b;
    scanf("%d %d" , &a, &b);
    int total = 0;
    if(a == b)
        total = 24;
    else if(a > b)
        total = (24-a) +b;
    else
        total = b-a;
    printf("O JOGO DUROU %d HORA(S)\n",total);
    return 0;
}
