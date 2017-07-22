#include <bits/stdc++.h>

using namespace std;

#define pb push_back

int s1[101];
int s2[101];
int s1Ini[101];
int s2Ini[101];
int s12[202];
int s12Fim[202];

#define TRACE(x...)
#define PRINT(x...)
#define WATCH(x) TRACE(cout << #x << " = " << x << endl )

bool verifica12(int n)
{
	for(int k = 0; k < n; k++)
	{
		if(s12[k] != s12Fim[k])
		{
			return false;
		}
	}
	return true;

}

bool verifica(int n)
{
	for(int k = 0; k < n; k++)
	{
		if(s1Ini[k] != s1[k] || s2Ini[k] != s2[k])
		{
			return false;
		}
	}
	return true;

}

int main()
{
	int t;
	scanf("%d", &t);

	for(int i = 0; i <  t; i++)
	{
		int n;
		scanf("%d", &n);

		char c;
		for(int j = 0; j < n; j++)
		{
			scanf(" %c", &c);
			s1[j] = c - 'A';
			s1Ini[j] = c - 'A';
		}
		for(int j = 0; j < n; j++)
		{
			scanf(" %c", &c);
			s2[j] = c - 'A';
			s2Ini[j] = c - 'A';
		}
		for(int j = 0; j < 2 * n; j++)
		{
			scanf(" %c", &c);
			s12Fim[j] = c - 'A';
		}

		int count = 0;
		for(int j = 0; j < n; j++)
		{
			s12[count] = s1[j];
			count++;
		}
		for(int j = 0; j < n; j++)
		{
			s12[count] = s2[j];
			count++;
		}

		bool ok = true;

		if(verifica12(2*n))
		{
			printf("%d 0\n", i + 1);
			ok = false;
		}

		int qnt = 0;
		while(ok)
		{
			count = 0;
			for(int j = 0; j < n; j++)
			{
				s12[count] = s2[j];
				count++;
				s12[count] = s1[j];
				count++;
			}

			qnt++;

			if(verifica12(2*n))
			{
				printf("%d %d\n", i + 1, qnt);
				ok = false;
			}


			count = 0;
			for(int j = 0; j < n; j++)
			{
				s1[j] = s12[count];
				count++;
			}
			for(int j = 0; j < n; j++)
			{
				s2[j] = s12[count];
				count++;
			}

			if(verifica(n))
			{
				printf("%d -1\n", i + 1);
				ok = false;
			}
		}
	}
}