#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
    int a;
    scanf("%d", &a);
    int total = a;
    int _42 = 0;
    while(total != 0)
    {
        if(total == 1)
        {
            _42++;
            break;
        }
        else if(total%2 == 1)
        {
            total = (int)(floor(total/2.0));
            _42++;
        }
        else
        {
            total /= 2;
            _42++;
        }
    }
    cout << _42 << endl;
    return 0;
}
