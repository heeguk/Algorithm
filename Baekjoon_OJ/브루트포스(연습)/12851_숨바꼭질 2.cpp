#include <iostream>
#include <cstring>
#include <queue>

using namespace std;


int d[100001];
int dp[100001];
int N, K;

int main() {
	memset(d, -1, sizeof(d));
	memset(dp, 0, sizeof(dp));
	cin >> N >> K;
	
	queue<int> q;
	q.push(N);
	d[N] = 0;
	dp[N] = 1;
	while (!q.empty()) {
		int start = q.front();
		q.pop();
		
		if (start == K) {
			cout << d[K] << "\n";
			cout << dp[K];
			break;
		}
		
		

		for (int i = 0; i < 3; i++) {
			int to;
			if (i == 0)	to = start - 1;
			else if (i == 1) to = start + 1;
			else if (i == 2) to = start * 2;
			
			if (to < 0 || to > 100000) continue;
			if (d[to] == -1) {
				d[to] = d[start] + 1;
				dp[to] = dp[start];
				q.push(to);
			}
			else if (d[to] == d[start] + 1) {
				dp[to] += dp[start];
			}
		}
	}
}