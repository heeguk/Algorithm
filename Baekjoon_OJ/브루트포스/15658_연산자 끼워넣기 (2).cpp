#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int arr[11];
int result_min = 1000000000;
int result_max = -1000000000;

void go(int index, int sum, int plus, int minus, int mul, int div) {
	if (index == n) {
		result_min = min(result_min, sum);
		result_max = max(result_max, sum);
		return;
	}

	if (plus > 0)
		go(index + 1, sum + arr[index], plus - 1, minus, mul, div);
	if (minus > 0)
		go(index + 1, sum - arr[index], plus, minus - 1, mul, div);
	if (mul > 0)
		go(index + 1, sum * arr[index], plus, minus, mul - 1, div);
	if (div > 0)
		go(index + 1, sum / arr[index], plus, minus, mul, div - 1);

}

int main() {
	cin >> n;
	int plus, minus, mul, div;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> plus >> minus >> mul >> div;

	go(1, arr[0], plus, minus, mul, div);
	
	cout << result_max << '\n' << result_min;
}