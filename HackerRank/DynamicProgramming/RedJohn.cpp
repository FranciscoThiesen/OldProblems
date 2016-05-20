#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
bool isPrime(int n)
{
    if( n == 2)
        return true;
    if(n == 1)
        return false;
    for(int i = 2; i <= floor(sqrt(n)); ++i)
        if(n%i == 0)
            return false;
    return true;
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        int ans = 0;
        scanf("%d", &n);
        int pos[n+1];
        if(n <= 3)
        {
            cout << 0 << endl;
        }
        else
        {
            pos[0] = 1;
            pos[1] = 1;
            pos[2] = 1;
            pos[3] = 1;
            for(int i = 4; i <= n; ++i)
                pos[i] = pos[i-1] + pos[i-4];
            for(int j = 1; j <= pos[n]; ++j)
            {
                if(isPrime(j))
                    ans++;
            }
            cout << ans << endl;
        }
    }
}
