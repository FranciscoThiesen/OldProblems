#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <utility>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<pair<int, int> > skill;
    for(int i = 0; i < n; ++i)
    {
        int x;
        scanf("%d", &x);
        skill.push_back(make_pair(x, i));
    }
    sort(skill.begin(), skill.end());
    if(n == 1)
        cout << 1 << endl;
    else if(skill[n-1].first != skill[n-2].first)
        cout << skill[n-1].second+1 << endl;
    else
        cout << -1 << endl;
    return 0;

}
