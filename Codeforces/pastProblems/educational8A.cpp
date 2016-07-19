#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

int main()
{
    int n, b, p;
    scanf("%d%d%d", &n, &b, &p);
    int current = n;
    int bottles = 0;
    int towels = 0;
    for(int j = 0; j < n;++j)
    {
        if(pow(2,j) > current)
        {
            bottles += (pow(2,j-1)*b) + (pow(2,j-2));
            current -= pow(2, j-1)/2;
            j = -1;
            if(current == 1)
                break;
        }
    }
    printf("%d %d\n", bottles, p*n);
    return 0;
}
