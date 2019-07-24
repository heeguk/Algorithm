#include <iostream>
#include <cstring>
#include <queue>
#include <map>
#include <string>

using namespace std;

string target = "123456780";
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };


int zero_loc(string str) {
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '0')
			return i;
	}
}

int main() {
	string init = "";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int n;
			cin >> n;
			init += to_string(n);
		}
	}
	if (init == target) {
		cout << 0;
		return 0;
	}
	map<string, int> dp;
	dp[init] = 0;
	queue<string> q;
	q.push(init);

	while (!q.empty()) {
		string start = q.front();
		q.pop();
		int zero = zero_loc(start);
		int y = zero / 3, x = zero % 3;

		if (start == target) {
			cout << dp[target];
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			string to = start;
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 3 || ny < 0 || nx >= 3 || nx < 0)	continue;
			swap(to[y * 3 + x], to[ny * 3 + nx]);
			if (dp.count(to) == 0) {
				q.push(to);
				dp[to] = dp[start] + 1;
			}
		}
	}
	cout << -1;
	return 0;
}