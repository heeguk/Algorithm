#include <iostream>
#include <vector>

using namespace std;

int n;

int go(int num, int target) {
	if (num == target) {
		return 1;
	}

	if (num > target) {
		return 0;
	}
	
	return go(num + 1, target) + go(num + 2, target) + go(num + 3, target);
	
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int target;
		cin >> target;
		int ans = go(0, target);
		cout << ans << '\n';
	}
}