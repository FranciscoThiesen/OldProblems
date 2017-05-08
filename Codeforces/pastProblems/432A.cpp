#include <iostream>
#include <cstdio>
#include <vector>
#include <functional>
#include <algorithm>


using namespace std;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int ans = 0;
    int tot = 0;
    for(int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        if(x <= 5-k)
            tot++;
    }
    printf("%d\n", tot/3);
    return 0;
}
