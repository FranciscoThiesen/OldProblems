#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int vec[n];
    int par = 0;
    int impar = 0;
    int difP;
    int difI;
    for(int i = 0; i < n ; ++i)
    {
        int x;
        cin >> x;
        if(x%2 == 0)
        {
            par++;
            difP = i;
        }
        else
        {
            impar++;
            difI = i;
        }
    }
    if(par == 1)
        cout << difP + 1 << endl;
    else
        cout << difI + 1 << endl;
    return 0;
}
