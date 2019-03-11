/*
상담을 진행하는 경우와, 진행하지 않는 경우로
나누어서 풀면 됨.
점화식 먼저 짜고 문제 풀기!!!!!!!!!!!1
*/

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int t[1500001], p[1500001];
int dp[1500001];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t[i] >> p[i];
	}
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < n; i++) {
		// 상담을 진행하는 경우
		dp[i + t[i]] = max(dp[i + t[i]], dp[i] + p[i]);
		// 상담을 진행하지 않는 경우
		dp[i + 1] = max(dp[i + 1], dp[i]);
	}
	
	cout << dp[n] << '\n';
}