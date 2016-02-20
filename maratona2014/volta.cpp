#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
    float f, s;
    scanf("%f%f", &f, &s);
    printf("%.0f\n",ceil(s/(s-f)));
    return 0;
}
