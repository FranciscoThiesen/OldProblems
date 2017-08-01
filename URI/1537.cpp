#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    vector<unsigned long long> size(100001);
    size[0] = 0;
    size[1] = 0;
    size[2] = 0;
    size[3] = 1;
    for(int i = 4; i < 100001;++i)
    {
        size[i] = (size[i-1]*i)%1000000009; 
    }
    int x = 1;
    while(x != 0)
    {
        cin >> x;
        if(x == 0)
            break;
        cout << size[x] << endl;
    }
    return 0;
}
