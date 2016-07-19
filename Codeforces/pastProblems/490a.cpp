#include <cstdio>
#include <vector>
#include <iostream>
#include <utility>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        if(x == 1)
            v1.push_back(i+1);
        else if(x == 2)
            v2.push_back(i+1);
        else if(x == 3)
            v3.push_back(i+1);
    }
    cout <<  min(v1.size(), min(v2.size(), v3.size())) << endl;
    for(int a = 0; a < min(v1.size(), min(v2.size(), v3.size())); ++a)
    {
        cout << v1[a] << " " << v2[a] << " " << v3[a] << endl;
    }
    return 0;
}
