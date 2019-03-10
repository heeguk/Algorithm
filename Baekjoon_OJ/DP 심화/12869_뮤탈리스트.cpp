/*
다이나믹 프로그래밍.
DP 문제라고 1, 2차원 배열만 사용하는 것이 아님.
추가적으로, 공격을 구현할 때 순열을 사용하면 편함
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int N, K;
int dp[61][61][61];
char arr[31];

int scv[3] = { 0, 0, 0 };
int attack[3] = { 1, 3, 9 };

void solve(int a, int b, int c) {
	if (a <= 0 && b <= 0 && c <= 0) {
		if (dp[0][0][0] == -1)
			dp[0][0][0] = dp[a][b][c];
		else
			dp[0][0][0] = min(dp[0][0][0], dp[a][b][c]);
		return;
	}

	do {
		int new_a = a - attack[0];
		int new_b = b - attack[1];
		int new_c = c - attack[2];

		if (new_a < 0)
			new_a = 0;
		if (new_b < 0)
			new_b = 0;
		if (new_c < 0)
			new_c = 0;

		if (dp[new_a][new_b][new_c] == -1) {
			dp[new_a][new_b][new_c] = dp[a][b][c] + 1;
			solve(new_a, new_b, new_c);
		}
		else {
			if (dp[new_a][new_b][new_c] > dp[a][b][c] + 1) {
				dp[new_a][new_b][new_c] = dp[a][b][c] + 1;
				solve(new_a, new_b, new_c);
			}
		}
	} while (next_permutation(attack, attack + 3));		
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	memset(dp, -1, sizeof(dp));
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> scv[i];
	}

	dp[scv[0]][scv[1]][scv[2]] = 0;
	solve(scv[0], scv[1], scv[2]);
	
	cout << dp[0][0][0] << '\n';
}