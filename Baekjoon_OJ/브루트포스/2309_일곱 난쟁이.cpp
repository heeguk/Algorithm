#include <iostream>
#include <algorithm>
using namespace std;



int main()
{
	int height[9];
	int sum = 0;

	for (int i = 0; i < 9; i++) {
		cin >> height[i];
		sum += height[i];
	}
	int find = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (i == j)
				continue;
			if (sum - height[i] - height[j] == 100) {
				//cout << "found" << endl;
				height[i] = 0;
				height[j] = 0;
				find = 1;
				break;
			}
		}
		if (find)
			break;
	}
	
	sort(height, height + 9);
	for (int i = 2; i < 9; i++) cout << height[i] << endl;

}