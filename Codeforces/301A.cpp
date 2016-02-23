#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    int a;
    scanf("%d", &a);
    string num;
    string num1;
    cin >> num >> num1;
    int total = 0;
    for(int i = 0; i < a; ++i)
    {
        int x = (int)num[i];
        int y = (int)num1[i];
        total += min(abs(x-y), (10-(abs(x-y))));
    }
    cout << total << endl;
    return 0;

}
