#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	int f;
	cin >> f;
	cin >> s;
	vector<string> words;
	int mx = 0;
	vector<string> wordsIn;
	int inside = 0;
	string pal;
	for(int i = 0; i < s.size(); ++i)
	{
		if(s[i] == '(')
		{
			inside = 1;
			if(pal.size()!= 0)
				words.push_back(pal);
			pal.clear();
		}
		else if(s[i] == ')')
		{
			inside = 0;
			if(pal.size() != 0)
				wordsIn.push_back(pal);
			pal.clear();
		}
		else if(s[i] == '_')
		{
			if(pal.size() != 0)
			{
				if(inside)
					wordsIn.push_back(pal);
				else
					words.push_back(pal);
			}
			pal.clear();	
		}
		else
			pal += s[i];
		
	}
	if(pal.size() != 0)
		words.push_back(pal);
	for(auto& p : words)
		if(p.size() > mx)
			mx = p.size();
	cout << mx << " " << wordsIn.size() << endl;
	return 0;
}