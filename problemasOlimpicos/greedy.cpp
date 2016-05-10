#include <cstdio>
#include <iostream>
#include <string>

int main(){
	int i = 0;
	std::string s;
	std::cin >> s;
	for(int x = 0; x < s.length(); x++)
	{
		if(s[x] == 'h')
		{
			i++;
			while(x < s.length())
			{
				x++;
				if(s[x] == 'e')
				{
					i++;
					while(x < s.length())
					{
						x++;
						if(s[x] == 'l')
						{
						 	i++;
						 	while( x < s.length())
						 	{
						 		x++;
						 		if(s[x] == 'l')
						 		{
						 			i++;
						 			while( x < s.length())
						 			{
						 				x++;
						 				if(s[x] == 'o')
						 				{
						 					printf("YES\n");
						 					return 0;
						 				}
						 			}
						 		}
						 	}
						}
					}
				}
			}
		}
	}
	printf("NO\n");
	return 1;
}