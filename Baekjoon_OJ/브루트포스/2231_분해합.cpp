#include <iostream>
#include <algorithm>
using namespace std;



int main()
{
	int target;
	cin >> target;
	
	if (target == 0) {
		cout << 0 << endl;
		return 0;
	}

	int temp1 = target;
	int digit = 0;
	while (1) {
		if (temp1 == 0)
			break;
		digit++;
		temp1 /= 10;
	}

	int find = 0;

	for (int i = target - digit * 10; i < target; i++) {

		int sum = i;
		int temp = i;
		while (1) {
			sum += temp % 10;
			temp /= 10;
			if (temp == 0)
				break;
		}
		if (sum == target){
			cout << i << endl;
			find = 1;
			break;
		}
	}
	if (find == 0)	cout << 0 << endl;
	return 0;

}