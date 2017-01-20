#include <bits/stdc++.h>

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
    for(int i = 0; i < c; ++i)
    {
        if(!i)
        {
            if(aux[i] + (c - aux[c-1]) < (double)n/c || aux[i+1] - aux[i] < (double)n/c)
            {
                pos = false;
                break;
            }
        }
        else if(i == c-1)
        {
            if(c - aux[i] + aux[0] < (double)n/c || aux[i] - aux[i-1] < (double)n/c)
            {
                pos = false;
                break;
            }
        }
        else
        {
            if(aux[i] - aux[i-1] < (double)n/c || aux[i+1] - aux[i] < (double)n/c)
            {
                pos = false;
                break;
            }  
        }
    }
    if(pos)
        cout << "S" << endl;
    else
        cout << "N" << endl;
}
