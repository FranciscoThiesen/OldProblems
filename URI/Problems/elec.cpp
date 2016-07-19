#include <unordered_map>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int maxx = 0;
    int votos[100001] = {0};
    int win;
    for(int i = 0; i < n; ++i)
    {
        int x;
        scanf("%d", &x );
        votos[x]++;
        if(votos[x] > maxx)
        {
            maxx = votos[x];
            win = x;

        }
    }
    cout << win << endl;
    return 0;
}
