#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;


int main() {
	int dp[1001];
	int price[1001];
	for (int i = 1; i < 1001; i++)
		dp[i] = 10001;
	dp[0] = 0;
	//memset(dp, 10001, sizeof(dp));
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> price[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = min(dp[i], price[j] + dp[i - j]);
		}
	}

	cout << dp[N];
	
}