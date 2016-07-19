#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    int hpy = 0;
    for(int i = 0; i < t; ++i)
    {
        int x;
        scanf("%d", &x);
        if(x == 0)
            hpy++;
    }
    if(hpy > floor(t/2.0))
        cout << "Y" << endl;
    else
        cout << "N" << endl;
    return 0;
}
