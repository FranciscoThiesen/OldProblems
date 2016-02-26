#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);
    vector<int> vec;
    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(c);
    sort(vec.begin(), vec.end());
    for(auto& p : vec)
        cout << p << endl;
    cout << endl;
    cout << a << endl << b << endl << c << endl;

    return 0;
}
