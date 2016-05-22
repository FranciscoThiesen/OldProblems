#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

unsigned long long pos[19] = {0};
int pot = 1;
unsigned long long pow(unsigned long long n, int pot)
{
    unsigned long long ans = n;
    for(int i = 2; i < pot; ++i)
        ans *= ans;
    return ans;
}
unsigned long long digits(int n)
{
    cout << "entrei" << endl;
    pos[n] = :(int) (36 * pow(10, n-2))  + (int) ((45 *pow(10,n-4))*9);
    cout << pos[n] << endl;
    return pos[n];
}
int main()
{
    pos[0] = 0;
    pos[1] = 0;
    pos[2] = 36;
    pos[3] = 360;
    for(int i = 4; i <= 18; ++i)
        cout << digits(i) << " " << i << endl;

    return 0;
}
