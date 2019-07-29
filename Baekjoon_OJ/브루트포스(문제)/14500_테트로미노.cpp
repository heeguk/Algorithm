#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M;
int map[500][500];
bool check[500][500];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int solve(int y, int x, int cnt, int sum) {
	if (cnt == 4) {
		return sum;
	}
	int ret = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i], nx = x + dx[i];
		if (ny >= N || ny < 0 || nx >= M || nx < 0)	continue;
		if (!check[ny][nx]) {
			check[ny][nx] = 1;
			ret = max(ret, solve(ny, nx, cnt + 1, sum + map[ny][nx]));
			check[ny][nx] = 0;
		}
	}
	return ret;
}

int main() {
	memset(check, 0, sizeof(check));
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			check[i][j] = 1;
			ans = max(ans, solve(i, j, 1, map[i][j]));
			check[i][j] = 0;
			// ㅜ
			if (i + 1 < N && j + 2 < M) {
				ans = max(ans, map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 1]);
			}
			// ㅓ
			if (i + 2 < N && j - 1 >= 0) {
				ans = max(ans, map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 1][j - 1]);
			}
			// ㅗ
			if (i - 1 >= 0 && j + 2 < M) {
				ans = max(ans, map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i - 1][j + 1]);
			}
			// ㅏ
			if (i + 2 < N && j + 1 < M) {
				ans = max(ans, map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 1][j + 1]);
			}
		}
	}

	cout << ans;
}