#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

typedef vector<int> vi;

struct BIT {
	// all indices are 0-indexed
	vi tree;
	int N;
	BIT(int _N){
		N = _N+1;
		tree = vi(N, 0);
	}	
	void update(int ind, int value){
		ind++;
		while(ind<N) {
			tree[ind] += value;
			ind += (ind & -ind);
		}	
	}
	int get(int ind) {
		int sum=0;
		while(ind > 0) {
			sum += tree[ind];
			ind -= (ind & -ind);
		}
		return sum;
	}
	int get(int ind1, int ind2) {
		if (ind1>=ind2) return 0;
		return get(ind2) - get(ind1);
	}
};

int main()
{
	vector<int> v{1,-1,2,3,4,-1};
	BIT arv(6);
	for(int i = 0; i < v.size(); ++i)
		arv.update(i, v[i]);

	cout << arv.get(3) << endl;
	return 0;
}