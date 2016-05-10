#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    int n,a,b,c;
    scanf("%d %d %d %d",&n, &a, &b, &c);
    vector<int> maxPieces(n+1, 0);
    maxPieces[0] = 0;
    maxPieces[a] = 1;
    maxPieces[b] = 1;
    maxPieces[c] = 1;
    for(int i = 1; i <= n; i++)
    {
        if(i >= a && maxPieces[i-a] > 0)
            maxPieces[i] = max(maxPieces[i], maxPieces[i-a]+1);
        if(i >= b && maxPieces[i-b] > 0)
            maxPieces[i] = max(maxPieces[i], maxPieces[i-b]+1);
        if(i >= c && maxPieces[i-c] > 0)
            maxPieces[i] = max(maxPieces[i], maxPieces[i-c]+1);
    }
    cout << maxPieces[n] << endl;
    return 0;
}
