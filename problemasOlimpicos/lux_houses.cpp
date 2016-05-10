#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int x;
	scanf("%d", &x);
	multiset<int> buildings;
	vector<int> predeos(x);
	vector<int> result(x);
	for(int i = 0; i < x; ++i)
	{
		int z;
		scanf("%d",&z);
		predeos[i] = z;
		buildings.insert(z);
	}
	//std::cout<<*std::max_element(buildings.begin(),buildings.end())<<std::endl;
	for(int j = 0; j < x - 1; ++j)
	{
		buildings.erase(buildings.find(predeos[j]));
		buildings.insert(0);
		//std::cout<<*std::max_element(buildings.begin(),buildings.end()) << endl;
		int y = *std::max_element(buildings.rbegin(),buildings.rbegin());
		int k = y - predeos[j] + 1;
		//printf("%d\n",k);
		result[j] = max(0,k);
	}
	result[x-1] = 0;
	for(int o = 0; o < x; ++o)
		cout << result[o] << endl;
	return 0;
}