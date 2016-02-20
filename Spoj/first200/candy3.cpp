#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    for(int i = 0; i < T; i++)
    {
        long long num = 0;
        long long tot = 0;
        long long cur;
        while(cin >> cur != '\n')
        {
            num++;
            tot += cur;
        }
        if(tot%num == 0)
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;
    }
    return 0;
}
