#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);
	int nums[n];
	int maior = 1;
	int atual = 1;
	for(int i = 0; i < n; ++i)scanf("%d", &nums[i]);
	for(int j = 1; j < n; ++j)
	{
		if(nums[j] >= nums[j-1])
			atual++;
		else
			atual = 1;
		if(atual >= maior)
			maior = atual;
	}
	printf("%d\n", maior);
	return 0;
}