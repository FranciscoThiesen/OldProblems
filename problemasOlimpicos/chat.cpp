#include <string>
#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	string a;
	scanf("%s", &a);
	char c = a[0];
	int distinct = 0;
	for(int i = 1; i < a.size(); i++)
	{
		char v = a[i];
		if( v == c)
			distinct++;
		c = v;
	}
	if( distinct%2 == 0)
		printf("CHAT WITH HER!\n");
	else
		printf("IGNORE HIM!\n");

	return 0;
}