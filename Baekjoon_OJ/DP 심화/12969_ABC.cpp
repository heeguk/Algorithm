/*
DP 배열이 1, 2차원이 아님.
상당히 까다로운 문제.
점화식을 잘 생각하기.
*/

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N, K;
bool dp[31][31][31][436];
char arr[31];

bool solve(int n, int a, int b, int k) {
	if (dp[n][a][b][k])
		return false;

	dp[n][a][b][k] = 1;

	if (n == N) {
		if (k == K) // Answer
			return true;
		else
			return false;
	}

	arr[n] = 'A';
	if (solve(n + 1, a + 1, b, k))
		return true;

	arr[n] = 'B';
	if (solve(n + 1, a, b + 1, k + a))
		return true;

	arr[n] = 'C';
	if (solve(n + 1, a, b, k + a + b))
		return true;

	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	memset(dp, 0, sizeof(dp));

	cin >> N >> K;

	if (solve(0, 0, 0, 0))
		cout << arr << '\n';
	else
		cout << -1 << '\n';

}