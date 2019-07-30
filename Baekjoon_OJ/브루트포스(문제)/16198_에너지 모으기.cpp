#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ans = 0;

void solve(int len, int sum, vector<int>& vec) {
	if (len == 2) {	// 더이상 진행을 못한다.
		ans = max(ans, sum);
		return;
	}

	for (int i = 1; i < len - 1; i++) {
		int out = vec[i];
		int energy = vec[i - 1] * vec[i + 1];
		vec.erase(vec.begin() + i);
		solve(len - 1, sum + energy, vec);
		vec.insert(vec.begin() + i, out);
	}
}

int main() {
	int N;
	vector<int> vec;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		vec.push_back(n);
	}

	solve(vec.size(), 0, vec);
	cout << ans;
}