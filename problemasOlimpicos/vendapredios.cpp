#include <cstdio>
#include <vector>
#include <algorithm>


using namespace std;
int main()
{
    int k, n;
    scanf("%d %d", &k, &n);
    int x = k - n;
    int c;
    int smaller = 10000000;
    vector<int> buildings(k);
    for( int i = 0; i < k; i++)
    {
        scanf("%d", &buildings[i]);
    }
    sort (buildings.begin(), buildings.end());
    for( int j = 0; j <= k - x; j++)
    {
        if(buildings[j+x-1] - buildings[j] < smaller)
        {   
            smaller = buildings[j+x-1] - buildings[j];
            printf("%d\n", smaller);
        }
    }


    printf("%d\n",smaller);
    return 0;


}
