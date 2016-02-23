#include <cstdio>
#include <cmath>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    unsigned long long maxx[100001];
    unsigned long long reps[100001];
    memset(maxx, 0, sizeof maxx);
    memset(reps, 0, sizeof reps);
    for(int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        reps[x]++;
    }
    unsigned long long maxP = 0;
    for(int j = 0; j < 100001; j++)
    {
        if(j == 0)
        {
            maxx[j] = reps[j]*j;
        }
        else if(j == 1)
        {
            maxx[j] = max(maxx[j-1], reps[j]*j);
        }
        else
            maxx[j] = max(maxx[j-2] + reps[j]*j, maxx[j-1]);
    }
    cout << maxx[100000] << endl;
    return 0;
}
