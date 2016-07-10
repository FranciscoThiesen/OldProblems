#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main()
{
    int a = 1, b = 1, c = 1;
    while(a != 0)
    {
        cin >> a;
        if(a == 0)
            break;
        cin >> b >> c;
        int dif = (c-a);
        int tot = b*(c*a);
        if(tot/dif <= 1)
            cout << tot/dif << " pagina" << endl;
        else
            cout << tot/dif << " paginas" << endl;
    }
    return 0;
}
