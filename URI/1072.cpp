#include <cstdio>
int main()
{
    int in =0;
    int out = 0;
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    {
        int a;
        scanf("%d", &a);
        if(a >= 10 && a <= 20)
            in++;
        else
            out++;
    }
    printf("%d in\n%d out\n", in, out);
    return 0;
}
