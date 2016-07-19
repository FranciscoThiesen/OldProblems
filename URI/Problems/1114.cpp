#include <cstdio>
int main()
{
    int a = 1;
    while(a!= 2002)
    {
        scanf("%d", &a);
        if(a!= 2002)
            printf("Senha Invalida\n");
        else
            printf("Acesso Permitido\n");
    }
    return 0;
}
