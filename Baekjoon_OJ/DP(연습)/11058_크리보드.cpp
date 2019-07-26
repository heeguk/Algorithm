#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
long long dp[100];

int main() {
	cin >> N;
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;

	for (int i = 1; i < N; i++) {
		dp[i] = dp[i - 1] + 1;
		for (int j = 3; i - j >= 0; j++) {
			dp[i] = max(dp[i], dp[i - j] * (j - 1));
		}
	}
	cout << dp[N - 1];
}