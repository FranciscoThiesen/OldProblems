#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <utility>
using namespace std;
int main()
{
    int a, x;
    scanf("%d", &a);
    vector<int> b;
    for(int i = 0; i < a; ++i)
    {
        int y;
        cin >> y;
        b.push_back(y);
    }
    scanf("%d", &x);
    vector<int> g;
    for(int j = 0; j < x; ++j)
    {
        int x;
        cin >> x;
        g.push_back(x);
    }
    sort(b.begin(), b.end());
    sort(g.begin(), g.end());
    int total = 0;
    for(int alfa = 0; alfa < a; ++alfa)
    {
        for(int beta = 0; beta < x; ++beta)
        {
            if(abs(b[alfa] - g[beta]) <= 1)
            {
                total++;
                g[beta] = 100000000;
                break;
            }
        }
    }
    cout << total << endl;
    return 0;
}
