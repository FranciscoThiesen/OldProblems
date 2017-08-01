#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int a,b,c,d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int w = 0;
    if(b>c && d>a)
        if(c+d > a+b)
            if(c > 0 && d > 0)
                if(a%2 == 0)
                    w++;
    if(!w)
        cout << "Valores nao aceitos" << endl;
    else
        cout << "Valores aceitos" << endl;
    return 0;
                
}
