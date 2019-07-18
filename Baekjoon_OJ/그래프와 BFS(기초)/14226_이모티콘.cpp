#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int dp[1001][1001];
int	S;

int main() {
	memset(dp, -1, sizeof(dp));
	cin >> S;
	queue<pair<int, int>> q;
	dp[1][0] = 0;
	q.push(make_pair(1, 0));

	while (!q.empty()) {
		pair<int, int> out = q.front();
		q.pop();
		int num = out.first;
		int copy = out.second;
		if (num == S) {
			cout << dp[num][copy] << "\n";
			break;
		}
		
		// case 1: Copy
		if (dp[num][num] == -1) {
			dp[num][num] = dp[num][copy] + 1;
			q.push(make_pair(num, num));
		}
		// case 2: Paste
		if (num + copy <= 1000 && dp[num + copy][copy] == -1) {
			dp[num + copy][copy] = dp[num][copy] + 1;
			q.push(make_pair(num + copy, copy));
		}
		// case 3: Delete
		if (num - 1 >= 0 && dp[num - 1][copy] == -1) {
			dp[num - 1][copy] = dp[num][copy] + 1;
			q.push(make_pair(num - 1, copy));
		}
		
	}
}