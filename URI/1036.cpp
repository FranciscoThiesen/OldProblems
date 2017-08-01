#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double a,b,c;
    cin >> a >> b >> c;
    if(a == 0 || b*b - 4*a*c < 0)
        cout << "Impossivel calcular" << endl;
    else
    {
        double r1, r2;
        r1 = (-1*b + sqrt(b*b - 4*a*c))/(2*a);
        r2 = (-1*b - sqrt(b*b - 4*a*c))/(2*a); 
        printf("R1 = %.5lf\n",r1);
        printf("R2 = %.5lf\n", r2);
    }
    return 0;
    
}
