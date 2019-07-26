#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[5001][5001];
int main() {
	int tc;
	scanf("%d", &tc);
	memset(dp, 0, sizeof(dp));
	int before = 1;
	for (int i = 0; i < tc; i++) {
		int n;
		scanf("%d", &n);
		dp[1][1] = 1;
		for (int i = before + 1; i <= n; i++) {
			for (int j = 0; j <= i; j++) {
				if (j == 0)
					dp[i][j] = dp[i - 1][j + 1];
				else if (j == i)
					dp[i][j] = dp[i - 1][j - 1];
				else
					dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000007;
			}
		}
		printf("%d\n", dp[n][0]);
		if (n > before) {
			before = n;
		}
	}
}