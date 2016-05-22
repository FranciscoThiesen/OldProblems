#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string ans;
    for(int i = 0; i < n; ++i)
    {
        string a;
        cin >> a;
        if(a.size() == 3)
        {
            if(a[0] == 'O' && a[1] == 'B')
            {
                if(i != n-1)
                    ans += "OBI ";
                else
                    ans += "OBI";
            }
            else if(a[0] == 'U' && a[1] == 'R')
            {
                if(i != n-1)
                    ans += "URI ";
                else
                    ans += "URI";
            }
            else
            {
                if(i != n-1)
                {
                    ans += a;
                    ans += " ";
                }
                else
                    ans += a;
            }
        }
        else
        {
            if(i != n-1)
            {
                ans += a;
                ans += " ";
            }
            else
                ans += a;
        }
    }
    cout << ans << endl;
    return 0;
}
