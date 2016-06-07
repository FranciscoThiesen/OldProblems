#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <utility>
using namespace std;

int main()
{
    vector<int> perf;
    int i = 0;
    int acc = 1;
    for(int j = 0; j < 1000; ++j)
    {
        i += acc;
        acc += 1;
        perf.push_back(i);
    }
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> seqSize;
        int cur = n;
        while(cur != 0)
        {
            for(int x = 0; x < perf.size(); ++x)
            {
                if(perf[x] > cur)
                {
                    cur -= perf[x-1];
                    seqSize.push_back(x-1);
                    cout << perf[x-1] << endl;
                    break;
                }
            }
        }
        string ans;
        char init = 'a';
        for(int c = 0; c < seqSize.size(); c++)
        {
            for(int k = 0; k <= seqSize[c]; ++k)
                ans += (init+c);
        }
        cout << ans << endl;
    }
    return 0;
}
