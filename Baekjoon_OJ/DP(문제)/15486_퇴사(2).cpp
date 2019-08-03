#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
int dp[1500001];
int T[1500001];
int P[1500001];
int main() {
	cin >> N;
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < N; i++) {
		cin >> T[i] >> P[i];
	}

	for (int i = 0; i < N; i++) {
		// 상담을 안하는 경우
		dp[i + 1] = max(dp[i + 1], dp[i]);

		// 상담을 하는 경우, 상담을 했을 때 N + 1일을 초과하는 경우는 제외한다.
		if (i + T[i] > N)	continue;
		dp[i + T[i]] = max(dp[i + T[i]], dp[i] + P[i]);
	}
	cout << dp[N];
}