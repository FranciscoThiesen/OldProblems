#include <algorithm>
#include <cstdio>
using namespace std;

const int INF = 10000000;
int blocks[1000010];
int coins[30];

int main() {
  int T;
  scanf(" %d ", &T);
  while (T--) {
    int N, M;
    scanf(" %d %d ", &N, &M);
    for (int i = 0; i < N; i++) {
      scanf(" %d ", &coins[i]);
    }
    blocks[0] = 0;
    for (int i = 1; i <= M; i++) {
      blocks[i] = INF;
      for (int j = 0; j < N; j++) {
        if (i - coins[j] >= 0) {
          blocks[i] = min(blocks[i], blocks[i - coins[j]] + 1);
        }
      }
    }
    printf("%d\n", blocks[M]);
  }
  return 0;
}

