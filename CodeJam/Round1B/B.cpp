#include <stdio.h>
#include <algorithm>
#define NUM 100010

using namespace std;

int main(void)
{
	int n, m, f[NUM], b[NUM], a[NUM], last, first, middle;

	bool amb = false, imposs = false;

	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &f[i]);
	}

	for (int i = 0; i < m; ++i)
	{
		scanf("%d", &b[i]);
		a[i] = 0;
	}

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(b[i] == f[j])
			{
				if (a[i] != 0)
				{
					amb = true;
					break;
					break;
				}

				a[i] = j + 1;
			}
		}

		if (a[i] == 0)
		{
			imposs = true;
			break;
		}
	}


	if(amb)
	{
		printf("Ambiguity\n");
	}

	else if (imposs)
	{
		printf("Impossible\n");
	}
	else
	{
		printf("Possible\n");
		for (int i = 0; i < m; ++i)
		{
			printf("%d ", a[i]);
		}
		printf("\n");
	}
	return 0;
}