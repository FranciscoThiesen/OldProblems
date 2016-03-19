#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    double vec[100];
    for(int i = 0; i < 100; ++i)
        scanf("%lf", &vec[i]);
    for(int j = 0; j < 100; j++)
        if(vec[j] <= 10)
            printf("A[%d] = %.1lf\n", j, vec[j]);
    return 0;
}
