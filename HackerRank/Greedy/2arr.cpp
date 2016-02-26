#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <utility>
#include <set>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i)
    {
        int size, sum;
        cin >> size >> sum;
        multiset<int> precisa;
        multiset<int> tem;
        bool ok = true;
        for(int i = 0; i < size;++i)
        {
            int x;
            cin >> x;
            precisa.insert(sum-x);
        }
        for(int j = 0; j < size; ++j)
        {
            int y;
            cin >> y;
            tem.insert(y);
        }
        for(auto& p: precisa)
        {
            if(precisa.count(p) > tem.count(p))
            {
                ok = false;
                break;
            }
        }
        if(ok)
            cout <<"YES" << endl;
        else
            cout << "NO" << endl;

    }
    return 0;
}
