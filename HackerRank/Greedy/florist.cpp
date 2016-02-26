#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <utility>

using namespace std;

int main()
{
    int fl, p;
    cin >> fl >> p;
    vector<int> flowers;
    for(int i = 0; i < fl; i++)
    {
        int x;
        cin >> x;
        flowers.push_back(x);
    }
    sort(flowers.rbegin(),flowers.rend());
    int friendsAvailable = p;
    int penalty = 0;
    long long total = 0;
    for(int j = 0; j < fl; j++)
    {
        if(friendsAvailable == 0)
        {
            penalty++;
            friendsAvailable = p;
        }
        if(friendsAvailable > 0)
        {
            total += flowers[j] * (penalty+1);
            friendsAvailable--;
        }
    }
    cout << total << endl;

}
