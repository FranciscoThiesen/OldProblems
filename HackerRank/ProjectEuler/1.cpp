#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

vector<int> arr(1000000001,0);
int main()
{
    for(int i = 3; i < 1000000001; ++i)
    {
        if(i%3 == 0 || i%5 == 0)
            arr[i] = arr[i-1] + i;
    }
    int t;
    cin >> t;
    while(t--)
    {
        int a;
        cin >> a;
        cout << arr[a] << endl;
    }
    return 0;
}
