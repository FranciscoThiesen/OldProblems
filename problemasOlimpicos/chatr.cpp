#include <cstdio>
#include <string>
#include <iostream>

int main()
{
	std::string x;
	std::cin >> x;
	int posh, pose, posl, posll, poso;
	int p = 0;
	for(int i = 0; i < x.size(); i++)
	{
		if(x[i] == 'h')
		{
			posh = i;
			p++;
			break;
		}
	}
	for(int j = posh + 1; j < x.size(); j++)
	{
		if(x[j] == 'e')
		{
			pose = j;
			p++;
			break;
		}
	}
	for(int k = pose + 1; k < x.size(); k++)
	{
		if(x[k] == 'l')
		{
			posl = k;
			p++;
			break;
		}
	}
	for(int j = posl + 1; j < x.size(); j++)
	{
		if(x[j] == 'l')
		{
			posll = j;
			p++;
			break;
		}
	}
	for(int j = posll + 1; j < x.size(); j++)
	{
		if(x[j] == 'o')
		{
			poso = j;
			p++;
			break;
		}
	}
	if(p == 5)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}