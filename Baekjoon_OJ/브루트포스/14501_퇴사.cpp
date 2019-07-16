#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int time[15];
int pay[15];
int ans = -1;

void go(int index, int sum) {
	if (index == n) {
		ans = max(ans, sum);
		return;
	}
	if (index > n)
		return;

	go(index + 1, sum);
	go(index + time[index], sum + pay[index]);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> time[i] >> pay[i];
	}
	go(0, 0);
	cout << ans;
}