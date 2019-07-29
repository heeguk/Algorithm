#include <iostream>
#include <cstring>

using namespace std;

int map[5][5];
bool num[1000000];
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0, 0 };

void solve(int cnt, int y, int x, int sum) {
	if (cnt == 6) {
		num[sum] = 1;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i], nx = x + dx[i];
		if (ny >= 5 || ny < 0 || nx >= 5 || nx < 0)	continue;
		solve(cnt + 1, ny, nx, sum * 10 + map[ny][nx]);
	}
}

int main() {
	memset(num, 0, sizeof(num));
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			solve(1, i, j, map[i][j]);
		}
	}

	int ans = 0;

	for (int i = 0; i < 1000000; i++) {
		if (num[i])	ans++;
	}
	cout << ans;
}