#include <cstdio>
#include <iostream>

using namespace std;
int main()
{
	int i, j;
	int moves = 0;
	int arr1[5][5];

	//This will allow you to input the numbers individually to fill the array.
	for (i = 0; i <= 4; i++)
    	for (j = 0; j <= 4; j++)
        {
        	cin >> arr1[i][j];
        	if(arr1[i][j] == 1)
        	{
        		moves = max(i-2,2-i) + max(j-2,2-j);
        	}
        }	

    printf("%d\n", moves);
    return 0;
}
