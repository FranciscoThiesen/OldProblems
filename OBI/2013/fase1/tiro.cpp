#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;

int main()
{
    vector<long long> r;
    vector<long long> shots;
    int c, s;
    scanf("%d%d", &c, &s);
    for(int i = 0; i < c; ++i)
    {
        long long x;
        scanf("%lld", &x);
        r.push_back(x*x);
    }
    unsigned long long int pts = 0;
    int f = 0;
    for(int j = 0; j < s; ++j)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        auto it = upper_bound(r.begin(), r.end(), x*x + y*y);
        //for(int i = 0; i < r.size();i++)
        //{
          //  if(x*x + y*y <= r[i]*r[i] )
           // {
             //   pts++;
            //}
        //}
        //
        
        int idx = distance(r.begin(), it);
        if(x*x + y*y == r[idx-1])
            pts++;
        if(x*x + y*y == r[idx])
            pts++;
        pts += max(0,c-(idx));
    }

    cout << pts << endl;
    return 0;
}
