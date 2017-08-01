#include <cstdio>
#include <vector>
#include <iostream>
#include <utility>
#include <cmath>
#include <functional>
#include <tuple>
using namespace std;
#define INF 100000000

vector<int> ing;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int d, i, b;
        scanf("%d %d %d", &d, &i, &b);
        for(int j = 0; j < i; ++j)
        {
            int x;
            scanf("%d", &x);
            ing.push_back(x);
        }
        int ans = 0;
        for(int i = 0; i < b; ++i)
        {
            int cost = 0;
            int n;
            scanf("%d", &n);
            for(int k = 0; k < n; ++k)
            {
                int y, z;
                scanf("%d %d", &y, &z);
                cost += (ing[y]*z);
            }
            ans = max(ans, d/cost);
        }
        cout << ans << endl;
        ing.clear();

    }
    return 0;
}
