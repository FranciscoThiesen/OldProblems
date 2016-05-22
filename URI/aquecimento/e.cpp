#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

int main()
{
    int tot, n;
    cin >> tot >> n;
    for(int i = 0; i < n; ++i)
    {
        string a;
        cin >> a;
        if(a[0] == 'f')
            tot++;
        else
            tot--;
    }
    cout << tot << endl;
}
