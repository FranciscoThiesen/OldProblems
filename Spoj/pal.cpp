#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int n;
    int x;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d", &x);
        while(true)
        {
            x++;
            string s = to_string(x);
            string k = s;
            reverse(k.begin(), k.end());
            if(s == k)
            {
                cout << s << endl;
                break;
            }
        }
    }
    return 0;
}
