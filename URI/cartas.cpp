#include <cstdio>
int main()
{
    int arr[5];
    for(int i = 0; i < 5; ++i)
        scanf("%d", &arr[i]);
    bool crescente = true;
    bool decrescente = true;
    //vou checar se eh decrescente
    for(int j = 1; j < 5; j++)
    {
        if(arr[j] >= arr[j-1])
        {
            decrescente = false;
            break;
        }
    }
    //checando se eh crescente
    for(int l = 1; l < 5; ++l)
    {
        if(arr[l] <= arr[l-1])
        {
            crescente = false;
            break;
        }
    }
    if(crescente == true)
        printf("C\n");
    else if(decrescente == true)
        printf("D\n");
    else
        printf("N\n");
    return 0;
}
