#include <bits/stdc++.h>

using namespace std;

int n, K;
int main()
{
	while (~scanf("%d%d", &n, &K)) {
		int d = (n - 1 + K - 1) / K;
		if ((n - 1) % K == 1) {
			printf("%d\n", d + d - 1);
			for (int i = 2; i <= 2 + K - 1; i++) printf("1 %d\n", i);
			for (int i = 2 + K; i <= n; i++) printf("%d %d\n", i - K, i);
			/*for (int i = 2; i <= 2 + d - 1; i++) printf("%d %d\n", i - 1, i);
			for (int i = 2 + d; i <= n; i++) {
				if (d - 1 == 1) printf("1 %d\n", i);
					else if ((i - d - 1) % (d - 1) == 1) printf("1 %d\n", i);
						else printf("%d %d\n", i - 1, i);
			}*/
		}
		else {
			printf("%d\n", d * 2);
			for (int i = 2; i <= 2 + K - 1; i++) printf("1 %d\n", i);
			for (int i = 2 + K; i <= n; i++) printf("%d %d\n", i - K, i);
		}
	}
	return 0;
}