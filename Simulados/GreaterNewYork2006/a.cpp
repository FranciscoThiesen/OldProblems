#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <functional>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <string>
#include <set>
#include <string.h>

using namespace std;

int main(void)
{
	int test;
	cin >> test;
	for (int j = 1; j <= test; ++j)
	{
		int num;
		char str[100];
		cin >> num;
		scanf("%s", str);

		if(num == strlen(str))
			str[num - 1] = '\0';

		for(int i = num - 1; i < strlen(str); i++)
		{
			str[i] = str[i + 1];
		}

		printf("%d %s\n", j, str);
	}
}