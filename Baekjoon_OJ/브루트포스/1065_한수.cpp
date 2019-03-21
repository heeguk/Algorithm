#include <iostream>
#include <algorithm>
using namespace std;



int main()
{
	int num;
	cin >> num;

	

	if (num < 100)
		cout << num << endl;
	else {
		int result = 99;
		for (int i = 100; i <= num; i++) {
			int ok = 1;
			int temp = i;
			int diffrence = temp % 10 - (temp/10) % 10;
			int before = (temp/10) % 10;
			temp /= 100;

			while (temp != 0) {
				int remain = temp % 10;
				if (diffrence != before - remain){
					ok = 0;
					break;
				}
				before = remain;
				temp /= 10;
			}
			if (ok) result++;
		}
		cout << result << endl;
	}
	
	return 0;

}