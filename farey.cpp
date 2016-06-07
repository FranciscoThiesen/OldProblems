#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>
using namespace std;

int eulerPhi(int n)
{
    int ans = n;

    for(int p = 2; p*p <= n; ++p)
    {
        if(n%p == 0)
        {
            while(n%p == 0)
                n /= p;
            ans -= ans/p;
        }
    }
    if(n > 1)
        ans -= ans/n;
    return ans;
}

int main()
{
    int t;
    scanf("%d",&t);
    int arr[10001];
    arr[0] = 0;
    for(int i = 1; i < 10001; ++i)
        arr[i] = arr[i-1] + eulerPhi(i);
    while(t--)
    {
        int k, n;
        scanf("%d %d", &k, &n);
        cout << k << " " << arr[n]+1 << endl;
    }
    return 0;
}
