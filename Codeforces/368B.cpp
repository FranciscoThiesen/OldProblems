#include <unordered_set>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> nums;
    for(int i = 0; i < n; ++i)
    {
        int x;
        scanf("%d", &x);
        nums.push_back(x);
    }
    vector<int> qry(n, 0);
    qry[n-1] = 1;
    unordered_set<int> mapa;
    mapa.insert(nums[n-1]);
    for(int p = n-2; p >= 0; --p)
    {
        auto it = mapa.find(nums[p]);
        if(it == mapa.end())
        {
            qry[p] = qry[p+1] + 1;
            mapa.insert(nums[p]);
        }
        else
            qry[p] = qry[p+1];
    }
    for(int j = 0; j < m; ++j)
    {
        int q;
        scanf("%d", &q);
        cout << qry[q-1] << endl;
    }
    return 0;
}
