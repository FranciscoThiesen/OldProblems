#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int a,b,c,d,e;
    cin >> a >> b >> c >> d >> e;
    int win;
    if(d+e == 0)
    {
        if(a == 1 && (b+c)%2 == 0)
            win = 1;
        else if(a == 0 && (c+b)%2 == 1)
            win = 1;
        else
            win = 2;
    }
    else if(d+e == 1)
    {
        win = 1;
    }
    else
        win = 2;
    if(win == 1)
        cout << "Jogador 1 ganha!" << endl;
    else
        cout << "Jogador 2 ganha!" << endl;
    return 0;
}
