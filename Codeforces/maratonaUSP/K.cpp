#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;
    string ans;
    s += ".";
    int rep = 1;
    char let = s[0];
    for(int i = 1; i < s.size(); ++i)
    {
        if(s[i] == let)
            rep++;
        else
        {
            ans += let;
            ans += to_string(rep);
            rep = 1;
            let = s[i];
        }
    }
    cout << ans << endl;
    return 0;
}
