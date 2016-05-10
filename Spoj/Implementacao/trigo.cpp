#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int mul;
        scanf("%d", &mul);
        unsigned long long int ans = (pow(2,mul)/12000);
        cout << ans << " kg" << endl;
    }
    return 0;
}
