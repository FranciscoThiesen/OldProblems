#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
int main()
{
    int n, r;
    while(true)
    {
        scanf("%d %d", &n, &r);
        if(!(n+r))
            return 0;
        vector<int> balls;
        vector<int> pos(n+1, 0);
        for(int x = 0; x < r; ++x)
        {
            int a;
            cin >> a;
            balls.push_back(a);
        }
        sort(balls.rbegin(), balls.rend());
        for(int i = 0; i < r; ++i)
        {
            for(int j = i; j < r; ++j)
            {
                pos[balls[i]-balls[j]] = 1;
            }
        }
        bool ok = true;
        for(int i = 0; i < pos.size(); i++)
        {
            if(pos[i] == 0)
            {
                ok = false;
                break;
            }
        }
        if(ok)
            cout << "Y" << endl;
        else
            cout << "N" << endl;
    }
    return 0;
}
