#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <utility>
#define INF 10010010
using namespace std;
int count(vector<int>& coins, vector<int>& mini,int total, int minC)
{
    if(total == 0)
        return 0;
    if(total < minC)
    {
        mini[total] = INF;
        return INF;
    }
    if(mini[total] != -1)
        return mini[total];
    mini[total] = INF;
    for(int i = 0; i < (int) coins.size(); ++i)
    {
        if(coins[i] > total)
            break;
        mini[total] = min(mini[total], mini[total - coins[i]] + 1); 
    }
    return mini[total];

}
    
int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        vector<int> coins;
        int num, size;
        scanf(" %d %d ", &num, &size);
        vector<int> mini(1000001, -1);
        //std::fill(mini.begin(),mini.end(),-1);
        mini[0] = 0;
        for(int j = 0; j < num; j++)
        {
            int a;
            cin >> a;            
            coins.push_back(a);
        }
        sort(coins.begin(),coins.end());
        for(int j = 1; j <= size; j++)
            count(coins, mini, j, coins[0]);
        printf("%d\n", mini[size]);
    }
    return 0;
}
