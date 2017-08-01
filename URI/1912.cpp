#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    int n = 1;
    double a = 1;
    while(n + a != 0)
    {
    	cin >> n >> a;
    	if(n+a == 0)
    		return 0;
    	long long tot = 0;
    	int mx = -1;
    	int freq[10001] = {0};
    	for(int i = 0; i < n; ++i)
    	{
    		int x;
    		scanf("%d", &x);
    		freq[x]++;
    		if(x > mx)
    			mx = x;
    		tot+= x;
    	}
    	if(a == tot)
    		cout << ":D" << endl;
    	else if(a > tot)
    		cout << "-.-" << endl;
    	else
    	{
    		double cur = 0;
    		for(int k = mx; k >= 0; --k)
    		{
    			cur += freq[k];
    			cout << cur << endl;
    			cout << a << endl;
    			if((int)cur == (int)a)
    			{
    				printf("%.4lf\n",cur);
    				break;
    			}
    			if((int)cur > a)
    			{
    				cout << "-.-" << endl;
    				break;
    			}
    		}
    	}
    	cout << "creu creu" << endl;

    }
    return 0;

}
