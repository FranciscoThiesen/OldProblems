#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int n = 1;
    int t = 1;
    while(n != 0)
    {
        cin >> n;
        if(!n)
            break;
        printf("Teste %d\n",t);
    
        t++;
        int total = 0;
        for(int i = 0; i < n; ++i)
        {
            int x, y;
            cin >> x >> y;
            total += x-y;
            cout << total << endl;
        }
        cout << endl;
    }
    return 0;
}
