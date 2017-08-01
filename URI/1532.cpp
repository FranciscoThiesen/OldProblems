#include <cstdio>
#include <iostream>
#include <cmath>
int solve(int N, int V)
{
    int n=0;
    for(int i=V; i>0; i--)
    {
        for(int j=0; j<i; j++)
        {
            n+=i;
            if(n==N)
                return 1;
        }
    }
    return 0;
}


int main()
{
    int N = 1,V= 1;
    while(scanf("%d %d", &N, &V), (N+V)!=0)
    {
        bool pos = false;
        for(int i = V; i>0; i--)
        {
            if(solve(N,i))
            {
                pos = true; 
                break;
            }
        }
        if(pos)
            printf("possivel\n");
        else
            printf("impossivel\n");
    }
    return 0;
}
