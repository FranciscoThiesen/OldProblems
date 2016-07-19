#include <cstdio>
#include <unordered_set>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    unordered_set<int> badges;
    int total = 0;
    for(int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        while(badges.find(x) != badges.end())
        {
            total++;
            x++;
        }
        badges.insert(x);
    }
    cout << total << endl;
    return 0;
}
