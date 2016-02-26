#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    int tot = 0;
    if(a >0)
        tot++;
    if(b >0)tot++;
    if(c>0)tot++;
    if(d>0)tot++;
    if(e>0)tot++;
    if(f>0)tot++;
    if(tot == 1 || tot == 0)
        printf("%d valor positivo\n", tot);
    else
        printf("%d valores positvos\n", tot);
    return 0;
}
