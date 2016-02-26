#include <cstdio>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    string a;
    cin >> a;
    int alf[27] = {0};
    memset(alf, 0, sizeof alf);
    for(int i = 0; i < a.size(); i++)
    {
        alf[a[i] - 'a']++;
    }
    int imp = 0;
    for(int j = 0; j < 26;++j)
    {
        if(alf[j]%2 == 1)
            imp++;
    }
    if(a.size()%2 == 0)
    {
        if(imp == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    else
    {
        if(imp == 1)
            cout <<"YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
