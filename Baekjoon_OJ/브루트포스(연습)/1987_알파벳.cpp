#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int R, C;
int map[20][20];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int ans = 0;
bool check[26];

void solve(int y, int x, int cnt) {
	ans = max(ans, cnt);
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= R || ny < 0 || nx >= C || nx < 0) continue;

		if (!check[map[ny][nx]]) {
			check[map[ny][nx]] = true;
			solve(ny, nx, cnt + 1);
			check[map[ny][nx]] = false;
		}
	}
}

int main() {
	memset(check, 0, sizeof(check));
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			char c;
			cin >> c;
			map[i][j] = c - 'A';
		}
	}

	check[map[0][0]] = true;
	solve(0, 0, 1);
	cout << ans;
}