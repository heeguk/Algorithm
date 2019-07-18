#include <iostream>

using namespace std;

// D[N] = min(D[N/3], D[N/2], D[N-1]) + 1

int dp[1000001];

int main() {
	int N;
	cin >> N;
	dp[1] = 0;
	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 3 == 0 && dp[i] > dp[i / 3] + 1)
			dp[i] = dp[i / 3] + 1;
		if (i % 2 == 0 && dp[i] > dp[i / 2] + 1)
			dp[i] = dp[i / 2] + 1;
	}
	cout << dp[N];
}