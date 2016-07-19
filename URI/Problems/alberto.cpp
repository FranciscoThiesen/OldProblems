#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

long long int melhor(vector<int>& values, long long int total)
{
    if(values.size() == 0)
        return 0;
    else if(values.size() == 1)
        return total;
    else if(values.size() == 2)
        return total - min(values[1], values[0]);
    else
    {
        vector<int> aux = values;
        vector<int> aux2 = values;
        aux2.erase(aux2.begin(), aux2.begin()+1);
        aux.pop_back();
        return max(best(i-1, j), total + best(i, j+1));

    }
}

int main()
{
    int n;
    while(scanf("%d", &n) == 1)
    {
        vector<int> nums;
        long long int total = 0;
        for(int i = 0; i < n; ++i)
        {
            int x;
            cin >> x;
            total += x;
            nums.push_back(x);
        }
        cout << melhor(nums, total) << endl;

    }
    return 0;
}
