#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

long long dp[500][500];
int cost[500];

long long solve(int from, int to) {
	if (dp[from][to] != -1)
		return dp[from][to];

	if (from == to)
		return 0;

	int sum = 0;
	for (int i = from; i <= to; i++) {
		sum += cost[i];
	}
	
	for (int j = from; j < to; j++) {
		if (dp[from][to] == -1)
			dp[from][to] = solve(from, j) + solve(j + 1, to) + sum;
		else
			dp[from][to] = min(dp[from][to], solve(from, j) + solve(j + 1, to) + sum);
	}
	return dp[from][to];
}

int main() {
	int tc;
	scanf("%d", &tc);
	
	for (int t = 0; t < tc; t++) {
		memset(dp, -1, sizeof(dp));
		memset(cost, 0, sizeof(cost));
		int N;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &cost[i]);
		}
		long long result = solve(0, N - 1);
		printf("%lld\n", result);
	}
}