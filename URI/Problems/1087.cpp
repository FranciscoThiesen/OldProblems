#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

int main()
{
    int a,b,c,d=1;
    while(a+b+c+d != 0)
    {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        if(a + b + c + d == 0)
            break;
        if(a == c && b == d)
            cout << "0" << endl;
        else if(abs(a-c) == abs(b-d) || a == c || b == d)
            cout << "1" << endl;
        else 
            cout << "2";
    }
    return 0;

}
