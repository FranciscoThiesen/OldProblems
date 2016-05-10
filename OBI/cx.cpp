#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int total,m;
    scanf("%d %d", &total, &m);
    long long tot = 0;
    int ma = m;
    for(int i = m; i >= 1; --i)
    {
        if(total == 3*i)
            tot++;
        else if( total - i < 2 )
            continue;
        else if( total - i == 2)
            tot += 3;
        else
            tot += max(i - (total -i-i) + 1, 0);
        cout << i << " " << total << endl;
    }
    cout << tot << endl;
    return 0;
}
