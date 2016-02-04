#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int size;
	scanf("%d", &size);
	vector<int> arr(size);
	for(int i = 0; i < size; i++)
		scanf("%d", &arr[i]);
	int total = 0;
	for(int j = 0; j < size;j++)
		for(int k = j+1; k < size; k++)
			if(arr[j] > arr[k])
				total++;

	cout << total << endl;
	return 0;
}