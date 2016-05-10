#include <cstdio>
#include <vector>

using namespace std;
int main()
{
	vector<int> v;
	while(true)
	{
		int a = 0;
		scanf("%d", &a);
		if(a == 42)
			break;
		else
			v.push_back(a);
	}
	for(int i = 0; i < v.size(); ++i)
		printf("%d\n", v[i]);
	return 0;
}