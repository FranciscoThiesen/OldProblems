#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    double n;
    scanf("%lf", &n);
    int n100, n50, n20, n10, n5, n2, m100, m50, m25, m10, m5, m1 = 0;
    while(n > 0.009)
    {
        n100 = n/100;
        n = fmod(n,100);
        n50 = n/50;
        n = fmod(n,50);
        n20 = n/20;
        n = fmod(n,20);
        n10 = n/10;
        n = fmod(n,10);
        n5 = n/5;
        n = fmod(n,5);
        n2 = n/2;
        n = fmod(n,2);
        m100 = n/1;
        n = fmod(n,1);
        m50 = n/0.5;
        n = fmod(n,0.5);
        m25 = n/25;
        n = fmod(n,0.25);
        m10 = n/0.1;
        n = fmod(n,0.1);
        m5 = n/0.05;
        n = fmod(n,0.05);
        m1 = n/0.01;
        n = fmod(n,0.01);
        break;
    }
    printf("NOTAS:\n%d nota(s) de R$ 100.00\n%d nota(s) de R$ 50.00\n%d nota(s) de R$ 20.00\n%d nota(s) de R$ 10.00\n%d nota(s) de R$ 5.00\n%d nota(s) de R$ 2.00\nMOEDAS:\n%d moeda(s) de R$ 1.00\n%d moeda(s) de R$ 0.50\n%d moeda(s) de R$ 0.25\n%d moeda(s) de R$ 0.10\n%d moeda(s) de R$ 0.05\n%d moeda(s) de R$ 0.01\n", n100, n50, n20, n10, n5, n2, m100, m50, m25, m10, m5, m1);
    return 0;

}

