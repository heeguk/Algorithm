#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

// dp[길이][마지막 자리수]
int dp[100001][3];
int map[2][100001];

int main() {
	//cout<<max(max(1, 3), 2);
	int tc;
	cin >> tc;
	
	for (int t = 0; t < tc; t++) {
		memset(map, 0, sizeof(map));
		memset(dp, 0, sizeof(dp));
		int N;
		cin >> N;
		for (int h = 0; h < 2; h++) {
			for (int w = 1; w <= N; w++) {
				cin >> map[h][w];
			}
		}
		dp[0][0] = 0;
		dp[0][1] = 0;
		dp[0][2] = 0;
		for (int i = 1; i <= N; i++) {
			dp[i][0] = max(max(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]);
			dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + map[0][i];
			dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + map[1][i];
		}
		cout << max(max(dp[N][0], dp[N][1]), dp[N][2]) << "\n";
	}
}