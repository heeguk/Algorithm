#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
char map[20][20];
vector<pair<int, int>> coin;

int dy[4] = { 0 ,0, -1, 1 };
int dx[4] = { -1, 1, 0, 0, };
int ans = 11;


void solve(int cnt, int y1, int x1, int y2, int x2) {
	if (cnt == 11)	return;

	for (int i = 0; i < 4; i++) {
		int ny1 = y1 + dy[i], nx1 = x1 + dx[i];
		int ny2 = y2 + dy[i], nx2 = x2 + dx[i];
		bool out1 = ny1 >= N || ny1 < 0 || nx1 >= M || nx1 < 0;
		bool out2 = ny2 >= N || ny2 < 0 || nx2 >= M || nx2 < 0;

		if (out1 && out2)	continue;
		if (out1 || out2) {
			ans = min(ans, cnt);
			continue;
		}

		if (!out1 && map[ny1][nx1] == '#') {
			ny1 = y1, nx1 = x1;
		}
		if (!out2 && map[ny2][nx2] == '#') {
			ny2 = y2, nx2 = x2;
		}
		
		map[y1][x1] = '.', map[y2][x2] = '.';
		map[ny1][nx1] = 'o', map[ny2][nx2] = 'o';
		solve(cnt + 1, ny1, nx1, ny2, nx2);
		map[y1][x1] = 'o', map[y2][x2] = 'o';
		map[ny1][nx1] = '.', map[ny2][nx2] = '.';
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'o')	coin.push_back(make_pair(i, j));
		}
	}

	solve(1, coin[0].first, coin[0].second, coin[1].first, coin[1].second);
	if (ans == 11)	cout << -1;
	else cout << ans;
}