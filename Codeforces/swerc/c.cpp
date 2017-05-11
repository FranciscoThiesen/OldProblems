#include <bits/stdc++.h>

using namespace std;

#define pb push_back
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int d, r, t;
    cin >> d >> r >> t;
    int ritaAge = 4;
    int ritaCand = r - 4;
    int theoAge = 0;
    int theoCand = t;
    int sobraRita = 0;
    vector<int> idadeRita(200, 0);
    for(int i = 4;i < 200; ++i)
        idadeRita[i] = (idadeRita[i-1] + i);
    vector<int> idadeTheo(200, 0);
    for(int i = 3; i < 200; ++i)
        idadeTheo[i] = (idadeTheo[i-1] + i);
    int ritaInicial = 0;
    for(int i = 4; i < 200; ++i)
    {
        if(r < idadeRita[i])
        {
            ritaInicial = i-1;
            sobraRita = r - idadeRita[i-1];
            break;
        }
    }
    int ans = 0;
    ans += sobraRita;
    t += sobraRita;
    int theoInicial = 0;
    int sobraTheo = 0;
    for(int i = 3; i < 200; ++i)
    {
        if(t < idadeTheo[i])
        {
            theoInicial = i-1;
            sobraTheo = t - idadeTheo[i-1];
            break;
        }
    }
    if(abs(ritaInicial - theoInicial) == d)
    {
        cout << sobraRita << endl;
        return 0;
    }
    for(int i = ritaInicial; i >= 4; --i)
    {
        ans += i;
        t += i;
        for(int j = theoInicial; j < 200; ++j)
        {
            if(t == idadeTheo[j])
            {
                if(abs((i-1) - j) == d)
                {
                    cout << ans << endl;
                    return 0;
                }
            }
            else if(t < idadeTheo[j])
                break;
        }
    }
    return 0;
}
