#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    int size, n;
    cin >> size >> n;
    vector<int> nums;
    int mx;
    int mn;
    for(int i = 0; i < size;++i)
    {
        int x;
        cin >> x;
        if(i == 0)
        {
            mx = x;
            mn = x;
        }
        else
        {
            if(x < mn)
                mn = x;
            else if(x > mx)
                mx = x;
        }
        nums.push_back(x);
    }
    for(int j = 0; j < n; ++j)
    {
        int k;
        cin >> k;
        if(k >= mn && k <= mx)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
