#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <utility>
using namespace std;
int main()
{
    int s, n;
    scanf("%d %d", &s, &n);
    vector<pair<int, int> > dragons;
    for(int i = 0; i < n; ++i)
    {
        int a,b;
        scanf("%d %d", &a, &b);
        dragons.push_back(make_pair(a,10000-b));
    }
    sort(dragons.begin(), dragons.end());
    int str = s;
    for(int j = 0; j < n; ++j)
    {
        if(str <= dragons[j].first)
        {
            cout << "NO" << endl;
            return 0;
        }
        else
            str +=10000 - dragons[j].second;
    }
    cout << "YES" << endl;
    return 0;
}
