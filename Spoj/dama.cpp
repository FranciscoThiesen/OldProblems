#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a, b, c, d;
    while(scanf("%d %d %d %d", &a, &b, &c, &d) != 0)
    {
        if(a + b + c + d == 0)
            break;
        if(a == c && b == d)
            cout << "0" << endl;
        else if(abs(a-c) == abs(b-d))
            cout << "1" << endl;
        else if(a == c && b != d)
            cout << "1" << endl;
        else if(b == d && a != c)
            cout << "1" << endl;
        else
            cout << "2" << endl;
    }
    return 0;
}
