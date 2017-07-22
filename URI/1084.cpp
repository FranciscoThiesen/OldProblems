/*input
4 2
3759
6 3
123123
7 4
1000000
7 3
1001234
6 2
103759
0 0
*/
#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, d;
    cin >> n >> d;
    string s;

    while(n+d){

        cin >> s;
        stack<int> pilha;
        int to_rmv = d;
        for(const char& c : s)
        {
            if(!to_rmv)
                pilha.push(c - '0');
            else if(pilha.empty())
                pilha.push(c - '0');
            else{
                while(!pilha.empty()){
                    while(c - '0' > pilha.top() && to_rmv > 0){
                        pilha.pop();
                        to_rmv--;
                        if(pilha.empty()) break;
                    }
                    pilha.push(c-'0');
                    break;
                }
            }   
        }
        string word;
        while(!pilha.empty()){
            word += ('0' + pilha.top());
            pilha.pop();
        }
        int end = word.size();
        reverse(word.begin(), word.end());
        for(int i = 0; i < end-to_rmv; ++i){
            cout << word[i];   
        }
        cout << endl;
        cin >> n >> d;
    }
    return 0;   
}
