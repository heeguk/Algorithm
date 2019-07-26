#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int v[101];
bool dp[101][1001];
int main() {
	memset(dp, 0, sizeof(dp));
	int N, S, M;
	cin >> N >> S >> M;

	for (int i = 1; i <= N; i++) {
		cin >> v[i];
	}
	dp[0][S] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			if (j - v[i] >= 0) {
				if (dp[i - 1][j - v[i]])	dp[i][j] = 1;
			}
			if (j + v[i] <= M) {
				if (dp[i - 1][j + v[i]])	dp[i][j] = 1;
			}
		}
	}
	int ans = -1;
	for (int i = 0; i <= M; i++) {
		if (dp[N][i]) {
			ans = max(ans, i);
		}
	}
	cout << ans;
}