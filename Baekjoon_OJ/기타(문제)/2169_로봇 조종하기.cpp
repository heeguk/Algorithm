#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int ans = -100 * 1000 * 1000;

int dy[3] = { 1, 0, 0 };
int dx[3] = { 0, -1, 1 };

int N, M;
int map[1000][1000];
int dp[1000][1000][3];
bool check[1000][1000];
int go(int y, int x, int dir) {
	if (dp[y][x][dir] != -100 * 1000 * 1000)	return dp[y][x][dir];

	if (y == N - 1 && x == M - 1) {
		dp[y][x][dir] = map[y][x];
		return dp[y][x][dir];
	}
	//cout << y << " " << x << endl;

	for (int i = 0; i < 3; i++) {
		if (dir == 1 && i == 2)	continue;
		if (dir == 2 && i == 1)	continue;
		int ny = y + dy[dir], nx = x + dx[dir];
		if (ny >= N || ny < 0 || nx >= M || nx < 0)	continue;
		if (check[ny][nx])	continue;
		check[ny][nx] = 1;
		dp[y][x][dir] = max(dp[y][x][dir], go(ny, nx, i) + map[y][x]);
		check[ny][nx] = 0;
	}
	
	return dp[y][x][dir];
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			for (int k = 0; k < 3; k++) {
				dp[i][j][k] = -100 * 1000 * 1000;
			}
		}
	}

	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < 3; k++) {
				check[0][0] = 1;
				ans = max(ans, go(0, 0, k));
				check[0][0] = 0;
			}

		}
	}
	cout << ans;
}