#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
	int n, m; 
	scanf("%d %d", &n, &m);
	int position = 1;
	unsigned long long int minTime = 0;
	int task[m];
	for(int i = 0; i < m; i++)
	{
		scanf("%d", task[i]);
	}
	for(int j = 0; j < m;j++)
	{
		if(position < task[j])
		{
			minTime += task[j] - position;
			position = task[j];
		}
		if(position > task[j])
		{
			minTime += (n - position) + task[j];
			position = task[j];
		}
	}

	cout << minTime << endl;
	return 0;
}