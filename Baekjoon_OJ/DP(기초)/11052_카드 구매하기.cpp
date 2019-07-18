#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	int dp[1001];
	int price[1001];
	memset(dp, 0, sizeof(dp));
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> price[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], price[j] + dp[i - j]);
		}
	}

	cout << dp[N];
	
}