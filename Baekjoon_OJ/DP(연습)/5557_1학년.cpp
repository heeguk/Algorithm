#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int num[100];
long long dp[100][21];

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)	cin >> num[i];
	int target = num[N - 1];
	memset(dp, 0, sizeof(dp));
	dp[0][num[0]] = 1;
	for (int i = 1; i < N - 1; i++) {
		for (int j = 0; j <= 20; j++) {
			if (dp[i - 1][j]) {
				if (j - num[i] >= 0) dp[i][j - num[i]] += dp[i - 1][j];
				if (j + num[i] <= 20) dp[i][j + num[i]] += dp[i - 1][j];
			}
		}
	}
	cout << dp[N - 2][target];
}