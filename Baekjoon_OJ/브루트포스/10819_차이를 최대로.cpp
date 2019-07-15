#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int calculation(vector<int> vec) {
	int sum = 0;
	for (int i = 1; i < vec.size(); i++) sum += abs(vec[i] - vec[i - 1]);
	return sum;
}

int main() {
	vector<int> vec;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int in;
		cin >> in;
		vec.push_back(in);
	}
	sort(vec.begin(), vec.end());
	int sum = 0;
	do {
		sum = max(sum, calculation(vec));
	} while (next_permutation(vec.begin(), vec.end()));

	cout << sum;
}