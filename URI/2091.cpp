#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <utility>
#include <unordered_set>
#include <iterator>
#include <cmath>
#include <set>
using namespace std;


int main()
{
    int n = 1;
    while(scanf("%d", &n))
    {
        if(!n)break;
        unordered_set<unsigned long long> set;
        for(int i = 0; i < n; ++i)
        {
            unsigned long long x;
            cin >> x;
            auto it = set.find(x);
            if(it == set.end())
                set.insert(x);
            else
                set.erase(it);
        }
        cout << *(set.begin()) << endl;
    }
    return 0;
}
