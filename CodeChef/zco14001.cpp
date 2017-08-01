// https://www.codechef.com/ZCOPRAC/problems/ZCO14001
#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
 
int main()
{
    int w, h;
    cin >> w >> h;
    vector<int> boxes(w);
    for(int i = 0; i < w; ++i)cin>>boxes[i];
    int cranePos = 0;
    int carry = 0;
    int cmd = -1;
    while(cmd != 0)
    {
        cin >> cmd;
        if(cmd == 1 && cranePos != 0)cranePos--;
        else if(cmd == 2 && cranePos != w-1)cranePos++;
        else if(cmd == 3 && carry == 0 && boxes[cranePos] > 0){carry++;boxes[cranePos]--;}
        else if(cmd == 4 && boxes[cranePos] < h && carry == 1){
            boxes[cranePos]++; carry--;
        }
        else if(cmd == 0)break;
    }
    for(int i = 0; i < w; ++i)
        cout << boxes[i] << " ";
    cout << endl;
    return 0;
}