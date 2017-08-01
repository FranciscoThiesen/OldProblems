#include <cstdio>
#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    double s = 0;
    double c = 0; 
    double r = 0;
    for(int i = 0; i < n; ++i)
    {
        int x;
        char q;
        scanf("%d %c", &x, &q);
        if(q == 'C')
            c+=x;
        if(q == 'R')
            r+=x;
        if(q == 'S')
            s+=x;
    }
    printf("Total: %.0lf cobaias\n", s+c+r);
    printf("Total de coelhos: %.0lf\n", c);
    printf("Total de ratos: %.0lf\n", r);
    printf("Total de sapos: %.0lf\n", s);
    double pc = (c/(c+r+s))*100.0;
    double ps = (s/(c+r+s))*100.0;
    double pr = (r/(r+c+s))*100.0;
    printf("Percentual de coelhos: %.2lf ", pc);
    cout << "%"<< endl;
    printf("Percentual de ratos: %.2lf ",pr);
    cout << "%"<< endl;
    printf("Percentual de sapos: %.2lf ", ps);
    cout << "%" << endl;
    return 0;
    
}
