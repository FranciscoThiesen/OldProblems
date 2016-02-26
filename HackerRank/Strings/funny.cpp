#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        string a;
        cin >> a;
        string b = a;
        reverse(b.begin(),b.end());
        bool funny = true;
        for(int i = a.size()-1; i > 0; --i)
        {
            if(abs(a[i] - a[i-1]) != abs(b[i]-b[i-1]) )
            {
                funny = false;
                break;
            }
        }
        if(funny)
            cout <<"Funny" << endl;
        else
            cout << "Not Funny" << endl;
    }
    return 0;
}
