#include <cstdio>
#include <string>
#include <set>
#include <iostream>
using namespace std;
int main()
{
	int a = 0;
	set<char> chars;
	string x;
	std::cin >> x;
	for(int i = 0; i < x.size(); i++)
	{
		chars.insert(x[i]);
	}
	for(auto& p : chars)
	{
		a++;
	}
	if(a%2 == 0)
		printf("CHAT WITH HER!\n");
	else
		printf("IGNORE HIM!\n");
	return 0;

}