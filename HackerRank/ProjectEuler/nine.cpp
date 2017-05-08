#include <vector>
#include <algorithm>
#include <cstdio>
#include <utility>
#include <iostream>
#include <unordered_set>
#include <set>
#include <string>
#include <unordered_map>
#include <map>
using namespace std;

unordered_map<int, int> triplets;

void solve()
{
    for(int i = 1; i <= 3000; ++i)
    {
        for(int j = i + 1; j <= 3000; ++j)
        {
            if(i * i + j*j > 3000*3000)
                break;
            for(int k = j + 1; k <= 3000; ++k)
            {
                if(k*k > i*i + j*j)
                    break;
                if(k*k == i*i + j*j)
                {
                    if(triplets.find(i+j+k) != triplets.end())
                        triplets[i+j+k] = max(triplets[i+j+k], i*j*k);
                    else
                        triplets[i+j+k] = i*j*k;
                    break;
                }
            }
        }
    }
}



int main()
{
    int t;
    scanf("%d", &t);
    solve();
    while(t--)
    {
        int n;
        scanf("%d", &n);
        if(triplets.find(n) != triplets.end())
            cout << triplets[n] << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}
