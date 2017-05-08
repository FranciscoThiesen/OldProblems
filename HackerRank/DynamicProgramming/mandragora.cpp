#include <cstdio>
#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int size;
		scanf("%d", &size);
		vector<int> mand;
		long long ans = size;
		long long total = 0;
		long long S = 1;
		for(int i = 0; i < size; ++i)
		{
			int n;
			scanf("%d", &n);
			mand.push_back(n);
			total += n;
		}
		sort(mand.begin(), mand.end());
		for(int j = 0; j < size;++j)
		{
			total -= mand[j];
			S++;
			if(S * total >= ans)
				ans = S*total;
			else if(total == 0)
				ans = max(ans, S);
			
		}
		cout << ans << endl;
	}
	return 0;
}