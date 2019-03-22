#include <iostream>
#include <algorithm>
using namespace std;



int main()
{
	int num;
	cin >> num;
	
	if (num <= 10) {
		cout << num << endl;
		return 0;
	}
	else if (num > 1022) {
		cout << -1 << endl;
		return 0;
	}
	else if (num == 1022) {
		cout << 9876543210 << endl;
		return 0;
	}
	else {
		long long int start = 11;
		int result = 10;

		while(1) {
			//jump++;
			//cout << start << endl;
			long long int temp = start;
			int before = start % 10;
			temp /= 10;
			int ok = 1;

			int jump = 1;
			while (temp != 0) {
				int remain = temp % 10;
				
				if (remain <= before) {
					jump *= 10;
					ok = 0;
				}

				before = remain;
				temp /= 10;
			}
		
			if (ok)	result++;

			if (result == num) {
				cout << start << endl;
				return 0;
				break;
			}
			if (jump >= 10)	start = (start / 10) * 10 + jump;
			else start++;
			
		}
		cout << -1 << endl;
	}

	
	
	return 0;

}