#include <cstdio>
#include <vector>
#include <algorithm>

int main()
{
	std::vector<int> wheel;
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++)
		wheel.push_back(i);
	for(int j = m; wheel.size() >= 1;j += m)
	{
		if(wheel.size() == 1)
			printf("%d",wheel[1]);
		wheel.erase(wheel.begin()+j-1);
	}

	return 0;
}