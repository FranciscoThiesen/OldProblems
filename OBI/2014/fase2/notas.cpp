#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <iostream>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    vector<int> t;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x; 
        t.push_back(x);
    }
    sort(t.begin(),t.end());
    int cur = 1;
    int max = 1;
    int num;
    int maxNum = t[0];
    num = t[0];
    for(int j = 1; j < n; ++j)
    {
        if(t[j] == num)
            cur++;
        if(t[j] != num)
        {
            cur = 1;
            num = t[j];
        }
        if(cur >= max)
        {
            max = cur;
            maxNum = t[j];
        }
     
    }
    printf("%d\n",maxNum);
    return 0;
}
