#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
int main()
{
	string x;
	string ans;
	vector<int> v;
	std::cin >> x;
	for(int i = 0; i < x.size(); ++i)
	{
		if(x[i] != '+')
			v.push_back(x[i]);
	}
	std::sort(v.begin(), v.end());
	for(int i = 0; i < v.size(); i++)
	{
		ans += v[i];
		ans += '+';
	}	
	ans.erase(ans.end() - 1, ans.end());
	std::cout << ans << endl;
	return 0;
}