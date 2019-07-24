#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int dp[20001];
int from[20001];
int how[20001];

void get_vec(int i, vector<int>& ans) {
	if (from[i] != i) {
		get_vec(from[i], ans);
	}
	ans.push_back(how[i]);
}

int main() {
	int tc;
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		memset(dp, -1, sizeof(dp));
		int n;
		cin >> n;
		queue<int> q;
		
		how[1 % n] = 1;
		from[1 % n] = 1 % n;
		dp[1 % n] = 1;
		q.push(1 % n);
		while (!q.empty()) {
			int out = q.front();
			q.pop();
			if (out == 0) {
				vector<int> ans;
				get_vec(0, ans);
				for (int i = 0; i < ans.size(); i++)	cout << ans[i];
				cout << endl;
				break;
			}
			int to1 = (out * 10 + 0) % n;
			int to2 = (out * 10 + 1) % n;
			
			if (dp[to1] == -1) {
				dp[to1] = to1;
				from[to1] = out;
				how[to1] = 0;
				q.push(to1);
			}
			if (dp[to2] == -1) {
				dp[to2] = to2;
				from[to2] = out;
				how[to2] = 1;
				q.push(to2);
			}
		}
		if (dp[0] == -1)	cout << "BRAK\n";
	}
}