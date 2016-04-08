#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <utility>
#include <cstring>
using namespace std;
const int INF = 0x3F3F3F3F;
int collatz[1000001];
memset(collatz, INF, sizeof collatz);
int calc(int n, int curSize)
{

    if(n%2 == 0)
    {
        if(n/2 == 1)
        {
            return collatz[n] = curSize+1;
        }
        else
            return calc(n/2, curSize+1);
    }
    else
        return calc(3*n+1, curSize+1);
}


