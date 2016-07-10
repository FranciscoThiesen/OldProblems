#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int t, k;
    scanf("%d %d", &t, &k);
    vector<unsigned long long int> pos(100001, 0);
    for(int i = 0; i <= 100001; ++i)
    {
        if(i < k)
            pos[i] = 1;
        else
            pos[i] = (pos[i-1] + pos[i-k])%1000000007;
    }
    vector<unsigned long long int> sum(100001, 0);
    sum[0] = 1;
    for(int k = 1; k <= 100001; ++k)
        sum[k] = (sum[k-1] + pos[k]);
    while(t--)
    {
        int x, y;
        cin >> x >> y;
        cout << (sum[y] - sum[x-1])%1000000007<< endl;
    }
    return 0;
}
