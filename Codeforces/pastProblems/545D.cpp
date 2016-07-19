#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <utility>
using namespace std;

int main()
{
    int a;
    scanf("%d", &a);
    vector<int> ppl;
    for(int i = 0; i < a; ++i)
    {
        int p;
        cin >> p;
        ppl.push_back(p);
    }
    sort(ppl.begin(), ppl.end());
    int et = 0;
    int ok = 0;
    for(auto& p : ppl)
    {
        if(et <= p)
        {
            et += p;
            ok++;
        }
    }
    cout << ok << endl;
}
