#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define mt make_tuple

vector<tuple<char, int, int> > c;
int t, x, y;
string s;

vector<int> rep(int x){
	vector<int> ret;
	//cout << " x = " << x << "     ";

	while(x != 0){
		if(x%2)
			ret.pb(1);
		else ret.pb(0);
		x >>= 1;
	}

	int rem = 20 - (int)ret.size();
	for(int i = 0; i < rem; ++i) ret.pb(0);
	return ret;
}

bool aux(int n){
	vector<int> nums = rep(n);
	for(auto v : c){
		if(get<0>(v) == 's'){
			sort(nums.begin() + get<1>(v), nums.begin() + get<2>(v));
		}
		else{
			if(nums[get<1>(v)] > nums[get<2>(v)])
				swap(nums[get<1>(v)], nums[get<2>(v)]);
		}
	}
	return is_sorted(all(nums));
}


main(){
	cin >> t;
	bool brk = false;
	for(int i = 0; i < t; ++i){
		cin >> s >> x >> y;
		c.pb(mt(s[0], x, y));
	}
	for(int i = 0; i < 1048576; ++i){
		if(!aux(i))
		{
			cout << "incorrect" << endl;
			for(auto v : rep(i)) cout << v << " ";
			brk = true;
			break;
		}
	}
	if(!brk) cout << "correct" << endl;

}
