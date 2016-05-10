#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
	vector<int> x(4);
	int num = 0;
	for(int i = 0; i < 4; i++)
	{
		int d;
		cin >> d;
		x[i] = d;
	}
	sort(x.begin(), x.end());
	if(x[0] == x[1])
	{
		num++;
	}	
	if(x[1] == x[2])
	{
		num++;
	}	
	if(x[2] == x[3])
	{
		num++;
	}	
	printf("%d\n", num);
	return 0;
}