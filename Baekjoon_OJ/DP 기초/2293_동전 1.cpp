#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int coin[100];
int dp[10001];


int main() {
	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
		cin >> coin[i];

	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int c = coin[i]; c <= m; c++) {
			dp[c] += dp[c - coin[i]];
		}
	}

	cout << dp[m] << '\n';
}