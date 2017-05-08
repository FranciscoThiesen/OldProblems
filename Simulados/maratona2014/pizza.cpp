#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <iterator>
#include <string>

using namespace std;

#define gcd __gcd
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define ull unsigned long long

typedef vector<int> vi;

int main()
{
    int n, c;
    cin >> n >> c;
    vi azeitonas;
    bool pos = true;
    for(int i = 0; i < c; ++i)
    {
        int x;
        cin >> x;
        azeitonas.pb(x);
    }
    vi aux;
    aux.pb(azeitonas[c-1]);
    for(int i = 0; i < c; ++i)
        aux.pb(azeitonas[i]);
    aux.pb(azeitonas[0]);
    for(int i = 1; i < c-1; ++i)
        if(azeitonas[i+1] - azeitonas[i-1] <= n/c)
        {
            pos = false;
            break;
        }

    if(n - azeitonas[c-1] + azeitonas[1] <= n/c && c >= 4)
        pos = false;
    if(n - azeitonas[c-2] + azeitonas[0] <= n/c && c >= 4)
        pos = false;
    if(pos)
        cout << "S" << endl;
    else
        cout << "N" << endl;
}
