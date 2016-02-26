#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> w;
    for(int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        w.push_back(a);
    }
    sort(w.begin(),w.end());
    int total = 1;
    int cur = w[0];
    for(int j = 1; j < n; ++j)
    {
        if(w[j] - cur > 4)
        {
            total++;
            cur = w[j];
        }
    }
    cout << total << endl;
    return 0;
}
