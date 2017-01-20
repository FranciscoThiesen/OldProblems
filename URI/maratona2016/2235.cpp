#include <bits/stdc++.h>

using namespace std;

int main()
{
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        bool pos = false;
        if(a == b || a == c || c==b)
                pos = true;
        if(a+b == c || a+c == b)
                pos = true;
        if(b+c == a)
                pos = true;
        if(pos)
                printf("S\n");
        else
                printf("N\n");
        return 0;
}
