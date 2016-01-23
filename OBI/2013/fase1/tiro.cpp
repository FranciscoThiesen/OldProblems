#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;

int main()
{
    vector<double> r;
    int c, s;
    scanf("%d%d", &c, &s);
    for(int i = 0; i < c; ++i)
    {
        int x;
        scanf("%lf", &x);
        r.push_back(x);
    }
    unsigned long long int pts = 0;
    long f = 0;
    for(int j = 0; j < s; ++j)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        auto up = lower_bound(r.begin(),r.end(),sqrt(x*x + y*y));
        cout << c - (up - r.begin()) << endl;
        pts += max(f, c -  (up - r.begin()));
        cout << pts << endl;
    }
    cout << pts << endl;
    return 0;
}
