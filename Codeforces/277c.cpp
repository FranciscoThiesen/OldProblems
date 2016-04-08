#include <cstdio>
#include <string>
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int main()
{
    int m, s;
    scanf("%d %d", &m, &s);
    string big;
    string small;
    int missin2 = m;
    int missinDigits = m;
    int totalSum = 0;
    if( s > m*9 || ( s == 0 && m > 1))
    {
        cout << "-1 "  << "-1" << endl;
        return 0;
    }
    while(missinDigits > 0)
    {
        int a = min(9, s-totalSum);
        totalSum += a;
        big += to_string(a);
        missinDigits--;
    }
    totalSum = 0;
    while(missin2 > 0)
    {
        if(missin2 == m && m != 1)
        {
            int b = max(1, s-((missin2-1)*9));
            totalSum += b;
            small += to_string(b);
        }
        else
        {
            int c = max(0, s-totalSum-(missin2-1)*9);
            totalSum += c;
            small += to_string(c);
        }
        missin2--;
    }
    cout << small << " " << big << endl;
    return 0;
}
