#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
	string x;
	string ans;
	std::cin >> x;
	int y = 0;
	for(int j = 0; j < x.size(); j++)
	{
		if(x[j] >= 'A' && x[j] <= 'Z')
			y++;
	}
	if(y == x.size())
	{
		for(int b = 0; b < x.size(); ++b)
			ans += x[b] + 32;
		cout << ans << endl;
		return 0;
	}
	if(y == x.size() - 1)
	{
		if(x[0] >= 'A' && x[0] <= 'Z')
		{
			cout << x << endl;
			return 0;
		}
		ans += x[0] - 32;
		for(int i = 1; i < x.size(); ++i)
			ans += x[i] + 32;
		cout << ans << endl;
		return 0;
	}
	cout << x << endl;
	return 0;
}