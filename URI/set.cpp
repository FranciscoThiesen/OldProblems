#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define mp make_pair
 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
 
int f(vvi& mat, int ind) {
    int ans = 0;
    // tipos iguais, nums iguais
    if (ind == 1) 
    { // ex: 1 tri, 1 tri, 1 tri ... 2quad, 2quad, 2quad... e assim por diante
        for (int i = 0; i < 3; ++i) 
        {
            for (int j = 0; j < 3; ++j) 
            {
                int sum = mat[i][j]/3;
                mat[i][j] -= 3*sum;
                ans += sum;
            }
        }
        return ans;    
    }
    // tipos iguais, nums diferentes
    if (ind == 2) 
    {
        for (int i = 0; i < 3; ++i) 
        {
            int formasIguais = min(mat[i][0], min(mat[i][1], mat[i][2]));
            mat[i][0] -= formasIguais;
            mat[i][1] -= formasIguais;
            mat[i][2] -= formasIguais;
            ans += formasIguais;
        }
        return ans;    
    }
    // tipos diferentes, nums iguais
    if (ind == 3)
    {
        for (int i = 0; i < 3; ++i) 
        {
            int numsIguais = min(mat[0][i], min(mat[1][i], mat[2][i]));
            mat[0][i] -= numsIguais;
            mat[1][i] -= numsIguais;
            mat[2][i] -= numsIguais;
            ans += numsIguais;
        }
        return ans;
    }
    // tipos diferentes, nums diferentes
    if (ind == 4) 
    {
        for (int i = 0; i < 3; ++i) 
        {
            for (int j = 0; j < 3; ++j) 
            {
                if (j == i) continue;
                for (int k = 0; k < 3; ++k) 
                {
                    if (k == i or k == j) continue;
                    int nadaIgual = min(mat[0][i], min(mat[1][j], mat[2][k]));
                    mat[0][i] -= nadaIgual;
                    mat[1][j] -= nadaIgual;
                    mat[2][k] -= nadaIgual;
                    ans += nadaIgual;
                }
            }
        }
        return ans;
    }
    return ans;
}
 
int brute(vvi& mat) 
{
    int ans = 0;
    vector<int> v(4);
    for (int i = 1; i <= 4; ++i)
        v[i-1] = i;
    do {
        vvi matatual = mat;
        int atual = 0;
        for (int i = 0; i < v.size(); ++i)
            atual += f(matatual, v[i]);
        ans = max(ans, atual);
    } while (next_permutation(v.begin(), v.end()));
    return ans;
}
 
int main() {
    int n;
    while (scanf("%d", &n), n) 
    {
        char num[10], forma[20];
        vector<vector<int> > mat(3, vector<int>(3, 0));
        for (int i = 0; i < n; ++i) {
            scanf("%s %s", num, forma);
            int a, b;
            if (forma[0] == 'c') a = 0;
            if (forma[0] == 'q') a = 1;
            if (forma[0] == 't') a = 2;
            if (num[0] == 'u') b = 0;
            if (num[0] == 'd') b = 1;
            if (num[0] == 't') b = 2;
            mat[a][b]++;
        }
        int ans = brute(mat);
        cout << ans << endl;
    }
    return 0;
}