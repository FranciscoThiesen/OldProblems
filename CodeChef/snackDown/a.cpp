#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <utility>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int tot, acc, numgrad, maxgrad;
        cin >> tot >> acc >> numgrad >> maxgrad;
        vector<int> studs;
        for(int i = 0; i < tot-1; ++i)
        {
            long long accumulator = 0;
            for(int j = 0; j < numgrad; ++j)
            {
                int g;
                scanf("%d", &g);
                accumulator += g;
            }
            studs.push_back(accumulator);
        }
        int myS = 0;
        for(int k = 0; k < numgrad-1;++k)
        {
            int x;
            scanf("%d", &x);
            myS += x;
        }
        sort(studs.rbegin(), studs.rend());
        if(studs[acc-1] < myS)
        {
            cout << 0 << endl;
        }
        else
        {
            if(studs[acc-1] - myS + 1 <= maxgrad)
                cout << studs[acc-1] - myS + 1 << endl;
            else
                cout << "Impossible" << endl;
        }
    }
    return 0;
}
