#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int total = 0;
    while(a > 1 && b > 1)
    {
        if(a > b)
        {
            b += 1;
            a -= 2;
        }
        else
        {
            b-= 2;
            a += 1;
        }
        total++;
    }
    cout << total << endl;
    return 0;
}
