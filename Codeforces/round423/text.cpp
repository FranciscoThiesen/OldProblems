/*input
1
100100
*/
#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define mp make_pair

typedef pair<int, int> ii;
typedef long long ll;
typedef unsigned long long ull;

bool val(vector<int>& freq)
{
    for(auto v : freq) if(v > 2) return false;
    return true;
}

string returnBest(string& tmp)
{
    if(tmp.size() <= 2) return tmp;
    string resp;
    int sz = tmp.size();
    string alfa = "99887766554433221100";
    if(tmp.size() > 20)
    {
        return alfa;
    }
    bool valid = false; // achei uma configuracao valida para algum l 
    vector<int> fr(10, 0);
    for(int left = sz - 1; left >= 0; --left)
    {
        string cpy = tmp;
        bool ok = true;
        fill(all(fr), 0);
        for(int i = 0; i <= left; ++i)
        {
            fr[tmp[i]-'0']++;
        }
        if(left == sz-1 && val(fr)) return tmp;
        if(!val(fr)) continue;
        for(int right = left+1; right < sz; ++right){
            int ub = cpy[right] - '0';// numero na pos cpy[right]
            if(right == left+1){ // se ele eh o numero seguinte 
                for(int i = ub-1; i >= 0; --i){ // ele precisa necessariamente ser decrementado
                    if(fr[i] < 2){
                        cpy[right] = '0' + i;
                        fr[i]++;
                        break;
                    }
                }
                if(cpy[right] == '0' + ub){
                    ok = false;
                    continue;
                }
            }
            else{
                for(int i = 9; i >= 0; --i){
                    if(fr[i] < 2){
                        cpy[right] = '0' + i;
                        fr[i]++;
                        break;
                    }
                }
                if(cpy[right] == '0' + ub){
                    ok = false;
                    continue;
                }
            }
            
        }
        if(ok){
            valid = true;
            return cpy;
        }
    }
    sz--;
    string last;
    for(int i = 0; i < sz; ++i)
        last.pb(alfa[i]);
    return last;
}


int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        string s;
        cin >> s;
        cout << returnBest(s) << endl;
    }
}
