#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;


int N;
int number[3] = { 1, 2, 3 };

int main() {
	int tc;
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		int n;
		cin >> n;
		int dp[10001];
		memset(dp, 0, sizeof(dp));
		
		dp[0] = 1;

		for (int i = 0; i < 3; i++) {
			int num = number[i];
			for (int j = 1; j <= n; j++) {
				if (j - num < 0)	continue;
				dp[j] += dp[j - num];
			}
		}
		cout<<dp[n]<<"\n";
	}
}