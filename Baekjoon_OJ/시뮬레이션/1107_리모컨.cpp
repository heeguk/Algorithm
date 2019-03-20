#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

#define MOD 1000000000

bool button[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
int isok(int num) {
	if (num == 0) {
		if (button[0])
			return 1;
		else
			return 0;
	}

	int digit = 0;

	while (num != 0) {
		if (!button[num % 10])
			return 0;

		digit++;

		num /= 10;
	}

	return digit;
}

int main() {
	
	int N, target;
	cin >> target;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		button[n] = 0;
	}

	int result = abs(target - 100);

	for (int i = 0; i <= 1000000; i++) {
		int digit = isok(i);
		if (digit) {
			int result2 = abs(target - i) + digit;
			result = min(result, result2);
		}
	}

	cout << result << endl;

	return 0;
}