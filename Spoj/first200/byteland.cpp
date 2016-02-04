#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <utility>
#include <cmath>
using namespace std;
unordered_map<unsigned int, unsigned int> maxAmount;
unsigned int calcMaxAmount(unsigned int x)
{
	if(x == 0 || x == 1)
		return maxAmount[x] = x;
	std::unordered_map<unsigned int,unsigned int>::iterator ii = maxAmount.find(x);
	if(ii != maxAmount.end())
		return maxAmount[x];
	else
	{
		maxAmount[x] = max(x, calcMaxAmount(x/4) + calcMaxAmount(x/3) + calcMaxAmount(x/2));
	}
	return maxAmount[x];
}
int main()
{
	int n;
	maxAmount[0] = 0;
	while(cin >> n)
	{
		cout << calcMaxAmount(n) << endl;
	}	
	return 0;
}
