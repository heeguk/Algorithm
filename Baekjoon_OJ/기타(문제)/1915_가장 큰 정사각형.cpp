#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M;
int map[1001][1001];
int dp[1001][1001];
int main() {
	cin >> N >> M;
	memset(dp, 0, sizeof(dp));
	memset(map, 0, sizeof(map));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	
	int ans = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (map[i][j] == 0) {
				continue;
			}
			dp[i][j] = min({ dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1] }) + 1;
			if (ans < dp[i][j]) {
				ans = dp[i][j];
			}
		}
	}
	cout << ans * ans;
}