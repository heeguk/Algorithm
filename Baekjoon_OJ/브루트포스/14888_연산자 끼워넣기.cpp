#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {
	vector<int> vec;
	int arr[11];
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < 4; i++) {
		int op;
		cin >> op;
		for (int j = 0; j < op; j++) {
			vec.push_back(i);
		}
	}

	int result_max = -1000000000;
	int result_min = 1000000000;

	do {
		int sum = arr[0];
		for (int i = 0; i < vec.size(); i++) {
			switch (vec[i])
			{
			case 0:
				sum += arr[i + 1];
				break;
			case 1:
				sum -= arr[i + 1];
				break;
			case 2:
				sum *= arr[i + 1];
				break;
			case 3:
				sum /= arr[i + 1];
				break;
			}
		}
		result_max = max(result_max, sum);
		result_min = min(result_min, sum);
	} while (next_permutation(vec.begin(), vec.end()));
	cout << result_max << '\n' << result_min;
}
	