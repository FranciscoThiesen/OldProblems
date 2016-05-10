#include <cstdio>
#include <iostream>
#include <string>

using namespace std;
int main()
{
	string x;
	//string luckify;
	std::cin >> x;
	int lucky = 0;
	for(int i = 0; i < x.size(); i++)
	{
		if(x[i] == '4' || x[i] == '7')
			lucky++;
	}
	string luckify = to_string(lucky);
	for(int j = 0; j < luckify.size(); j++)
	{
		if(luckify[j] == '4' || luckify[j] == '7')
			continue;
		else
		{	
			printf("NO\n", luckify.c_str());
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}