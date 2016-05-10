#include <cstdio>
#include <iostream>
#include <string>

using namespace std;	
int main(){
	int i = 0;
	string s;
	cin >> s;
	string results;
	for(int x = 0; x < s.length(); x++)
	{
		if(s[x] == 'h')
			results += "h";
		if(s[x] == 'e')
			results += "e";
		if(s[x] == 'l')
			results += "l";
		if(s[x] == 'o')
			results += "o";
	}
	for(int k = 0; k < results.length(); k++)
	{
		if(results[k] == 'h')
			if(results[k + 1] == 'e')
				if(results[k + 2] == 'l')
					if(results[k + 3] == 'l')
						if(results[k + 4] == 'o')
						{	
							printf("YES\n");
							return 0;
						}
	}
	cout << "NO" << "\n" << results << std::endl;
	return 1;
}