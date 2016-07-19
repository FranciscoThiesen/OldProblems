#include <vector>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>

using namespace std;

int main()
{
    vector<int> a;
    int x;
    cin >> x;
    for(int i = 0; i < x; ++i)
    {
        int b;
        cin >> b;
        a.push_back(b);
    }
    sort(a.begin(),a.end());
    for(int k = 0; k < x; ++k)
        cout << a[k] << " ";
    return 0;
}
