#include <cstdio>
#include <iostream>
#include <string>

using namespace std;
int main()
{
	std::string s;
	std::cin >> s;
	int seq = 1;
	int j = 1;
	for(int k = 1; k <= s.length(); k++)
	{
		if(s[k] == s[k - 1])
		{
			seq++;
			if(seq == 7)
				j++;
		}
		else
			seq = 1;
	}
	if(j > 1)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}