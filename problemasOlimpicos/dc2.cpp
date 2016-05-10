#include <cstdio>
#include <cmath>

using namespace std;
int main()
{
    int x;
    scanf("%d", &x);
    if( x == 1)
    {
        printf("Sheldon\n");
        return 0;
    }
    if( x == 2)
    {
        printf("Leonard\n");
        return 0;
    }
    if( x == 3)
    {
        printf("Penny\n");
        return 0;
    }
    if( x == 4)
    {
        printf("Rajesh\n");
        return 0;
    }
    if( x == 5)
    {
        printf("Howard\n");
        return 0;
    }
    for(int i = 0; i < 10000; i++)
    {
        int comparer = 5*pow(2,i);
        if( x >= comparer + 1 && x <= comparer + 5*pow(2,i))
        {
            int amplitude = 5*pow(2,i);
            printf("amp%d", amplitude);
            if( x >= comparer + 1 && x <= comparer + amplitude/5 + i)
            {
                printf("Sheldon\n maior ou igual a = %d,  menor ou igual a = %d", comparer + 1, comparer + amplitude/5 + i);
                break;
            }
            if( x > comparer + amplitude/5 + i && x <= comparer + 2*(amplitude/5) + i)
            {
                printf("Leonard\n maior que = %d, menor ou igual a = %d", comparer + amplitude/5 + i, comparer + 2*(amplitude/5) + i);
                break;
            }
            if( x > comparer + 2*(amplitude/5) && x <= comparer + 3*(amplitude/5))
            {
                printf("Penny\n maior que = %d, menor ou igual a = %d",comparer + 2*(amplitude/5), comparer + 3*(amplitude/5));
                break;
            }
            if( x > comparer + 3*(amplitude/5) && x <= comparer + 4*(amplitude/5))
            {
                printf("Rajesh\n maior que= %d, menor ou igual a = %d", comparer + 3*(amplitude/5), comparer + 4*(amplitude/5));
                break;
            }
            if( x > (comparer + 4*(amplitude/5)) && x <= (comparer + amplitude))
            {
                printf("Howard\n maior que= %d, menor ou igual a = %d", comparer + 4*(amplitude/5), comparer + amplitude);
                break;
            }
        }
    }	
    return 0;
}