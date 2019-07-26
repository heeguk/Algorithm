#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int w[101];
int v[101];

int dp[101][100001];

int main() {
	int N, K;
	cin >> N >> K;
	memset(dp, 0, sizeof(dp));
	
	for (int i = 1; i <= N; i++) {
		cin >> w[i] >> v[i];
	}
	
	for (int i = 1; i <= N; i++) {	// i : i번째 아이템
		for (int j = 0; j <= K; j++) {	// j : 무게
			if (j - w[i] >= 0) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
			}
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	int ans = -1;
	for (int i = 0; i <= K; i++) {
		ans = max(ans, dp[N][i]);
	}
	cout << ans;
}