#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        string a;
        cin >> a;
        int total = 0;
        for(int i = 1; i < (int)a.size(); ++i)
        {
            if(a[i] == a[i-1])
                total++;
        }
        cout << total << endl;
    }
    return 0;
}
