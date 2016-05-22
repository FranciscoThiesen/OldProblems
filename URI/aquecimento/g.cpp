#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <functional>
#include <utility>
using namespace std;

int gcd(int x, int y) { return y ? gcd(y, x % y) : abs(x); }

int lcm(int a, int b)
{
    return a * (b/ gcd(a,b));
}
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i =0; i < n; ++i)
    {
        int a;
        scanf("%d", &a);
        arr[i] = a-1;
    }
    vector<int> times;
    for(int j = 0; j < n; ++j)
    {
        int t = 1;
        int cur = j;
        while(arr[cur] != j)
        {
            cur = arr[cur];
            t++;
        }
        times.push_back(t);
    }
    int result = times[0];
    for(int i = 1; i < times.size(); ++i)
        result = lcm(result, times[i]);
    cout << result <<  endl;
    return 0;
}
