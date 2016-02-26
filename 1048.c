#include <stdio.h>
int main()
{
    double a;
    scanf("%lf", &a);
    if(a <= 400.00)
    {
        printf("Novo salario: %.2lf\nReajuste ganho: %.2lf\nEm percentual: 15 %",a*1.15, a*1.15 - a);
        printf("\n");
    }
    else if(a <= 800.00)
    {
        printf("Novo salario: %.2lf\nReajuste ganho: %.2lf\nEm percentual: 12 %",a*1.12, a*1.12 - a);
        printf("\n");
    }
    else if(a <= 1200.00)
    {
        printf("Novo salario: %.2lf\nReajuste ganho: %.2lf\nEm percentual: 10 %",a*1.1, a*1.1 - a);
        printf("\n");
    }
    else if(a <= 2000.00)
    {
        printf("Novo salario: %.2lf\nReajuste ganho: %.2lf\nEm percentual: 7 %",a*1.07, a*1.07 - a);
        printf("\n");
    }
    else
    {
        printf("Novo salario: %.2lf\nReajuste ganho: %.2lf\nEm percentual: 4 %",a*1.04, a*1.04 - a);
        printf("\n");
    }
    return 0;
}
