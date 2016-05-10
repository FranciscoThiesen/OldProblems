#include <cstdio>
#include <string>
#include <iostream>

using namespace std;
int main()
{
	string s;
	string revs;
	std::cin >> s;
	std::cin >> revs;
	for(int i = 0; i < s.length(); i++)
	{
		if(s[i] != revs[s.length() - i  - 1])
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}