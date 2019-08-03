#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

long long dp[31][31];

long long solve(int a, int b) {
	if (b < 0)	return 0;
	if (a == 0)	return 1;
	if (dp[a][b] != -1)	return dp[a][b];
	
	dp[a][b] = solve(a - 1, b + 1) + solve(a, b - 1);
	return dp[a][b];
	
}

int main() {
	for (int t = 0; ; t++) {
		memset(dp, -1, sizeof(dp));
		int N;
		scanf("%d", &N);
		if (N == 0)	break;
		solve(N, 0);
		printf("%lld\n", dp[N][0]);
	}
	return 0;
}