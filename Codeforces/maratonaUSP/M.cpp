#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    string s;
    for(int i = 0; i < n; ++i)
    {
        string a;
        cin >> a;
        if(i%2 == 1)
            reverse(a.begin(), a.end());
        s += a;
    }
    int mx = 0;
    int cur = 0;
    for(int i = 0; i< s.size(); ++i)
    {
        if(s[i] == '.')
            cur++;
        
        if(cur > mx)
            mx = cur;
        if(s[i] == 'L')
            cur = 0; 
    }
    cout << mx << endl;
    return 0;
}
