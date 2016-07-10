#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main()
{
    int n1, n2, k1, k2;
    scanf("%d %d %d %d", &n1, &n2, &k1, &k2);
    if(n1 > n2)
        cout << "First" << endl;
    else
        cout << "Second" << endl;
    return 0;
}
