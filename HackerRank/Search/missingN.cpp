#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
#include <utility>
using namespace std;

int main()
{
    multiset<int> a;
    multiset<int> b;
    set<int> nums;
    int f, g;
    cin >> f;
    vector<int> missing;
    for(int i = 0; i < f; ++i)
    {
        int x;
        cin >> x;
        a.insert(x);
    }
    cin >> g;
    for(int j = 0; j < g; ++j)
    {
        int y; 
        cin >> y;
        b.insert(y);
        nums.insert(y);
    }
    for(auto& p : nums)
    {
        if(a.count(p) < b.count(p))
            missing.push_back(p);
    }
    for(auto& q : missing)
        cout << q << " ";
    cout << endl;
    return 0;



}
