#include <iostream>
#include <algorithm>
using namespace std;

bool prime[1001];

// 복잡하지만 에라토스테네스의 체를 이용할 수 있음.

int main() {
	prime[1] = true;
	for (int i = 2; i < 1001; i++) {
		if (prime[i])
			continue;
		for (int j = i * i; j < 1001; j+=i) {
			prime[j] = true;
		}
	}
	int n;
	int ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		if (!prime[k])
			ans++;
	}
	cout << ans << endl;
}