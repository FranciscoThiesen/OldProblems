#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	string s;
	string ans;
	cin >> s;
	char chars[] = "aeiouyAEIOUY";
	for(unsigned int a = 0; a < strlen(chars); ++a)
	{
		s.erase (remove(s.begin(), s.end(), chars[a]), s.end());
	}
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] >= 'A' && s[i] <= 'Z')
		{
			ans += ".";
			ans += s[i] + 32;
		}
		else
		{
			ans += ".";
			ans += s[i];
		}
	}
	cout << ans << endl;
	return 0;
}