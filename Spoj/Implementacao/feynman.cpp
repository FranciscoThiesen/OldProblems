#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
int main()
{
    unsigned long long vec[100];
    vec[0] = 0;
    int a = 1;
    for(int i = 1; i < 101; i++)
    {
        vec[i] = vec[i-1] + (a*a);
        a++;
    }
    int t = 1;
    while(t != 0)
    {
        cin >> t;
        if(t == 0)
            break;
        cout << vec[t] << endl;
    }
        return 0;

}
