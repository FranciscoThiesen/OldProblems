#include <cstdio>
#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> nums;
    vector<long long> sum;
    long long total = 0;
    for(int i = 0; i < n; ++i)
    {
        int p = 0;
        cin >> p;
        total+=p;
        sum.push_back(total);
        nums.push_back(p);
    }
    long long ans = 0;
    vector<int> posI;
    vector<int> posJ;
    if(total%3 != 0)
    {
        cout << "0" << endl;
        return 0;
    }
    else
    {
        for(int i = 0; i < sum.size()-1; ++i)
        {
            if(sum[i] == total/3)
                posI.push_back(i);
            else if(sum[i] == 2*(total/3))
                posJ.push_back(i);
        }
    }
    if(total == 0)
    {
        if(posI.size()%2 == 0)
            ans = (posI.size()/2)*(posI.size()-1);
        else
            ans = (posI.size()*((posI.size()-1)/2));
    }
    else
        ans = posI.size() * posJ.size();

    cout << ans << endl;
    return 0;
}
