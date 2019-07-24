#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0, 0 };

int bfs(pair<int, int> from, pair<int, int> to, int C, int R, char map[20][20]) {
	int d[20][20];
	memset(d, -1, sizeof(d));
	queue<pair<int, int>> q;

	q.push(from);
	d[from.first][from.second] = 0;
	while (!q.empty()) {
		auto out = q.front();
		q.pop();
		int y = out.first, x = out.second;

		if (y == to.first && x == to.second) {
			return d[y][x];
		}

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i], nx = x + dx[i];
			if (ny >= R || ny < 0 || nx >= C || nx < 0)	continue;
			if (map[ny][nx] == 'x')	continue;
			if (d[ny][nx] == -1) {
				d[ny][nx] = d[y][x] + 1;
				q.push(make_pair(ny, nx));
			}
		}
	}
	return -1;
}

int main() {

	while (1) {
		int C, R;
		char map[20][20];
		vector<pair<int, int>> trash;
		
		int X, Y;
		cin >> C >> R;

		if (C == 0 && R == 0)
			break;

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cin >> map[i][j];
				if (map[i][j] == '*')	trash.push_back(make_pair(i, j));
				else if (map[i][j] == 'o')	Y = i, X = j;
			}
		}
		int impossible = 0;
		trash.push_back(make_pair(Y, X));	// 마지막에 시작 위치를 삽입
		reverse(trash.begin(), trash.end()); // 뒤집어서 0번째 위치를 시작위치로 만듬
		int dp[10][10];
		for (int i = 0; i < trash.size(); i++) {
			dp[i][i] = 0;
			for (int j = i + 1; j < trash.size(); j++) {
				dp[i][j] = bfs(trash[i], trash[j], C, R, map);
				dp[j][i] = dp[i][j];
				if (dp[i][j] == -1) {
					impossible = 1;
					break;
				}
			}
			if (impossible)
				break;
		}
		if (impossible) {
			cout << -1 << "\n";
			continue;
		}
		vector<int> per;
		for (int i = 0; i < trash.size(); i++) {
			per.push_back(i);
		}

		int ans = 4000000;

		do {
			int sum = 0;
			for (int i = 1; i < trash.size(); i++) {
				sum += dp[per[i - 1]][per[i]];
			}
			ans = min(ans, sum);
		} while (next_permutation(per.begin() + 1, per.end()));
		cout << ans << "\n";
	}

}