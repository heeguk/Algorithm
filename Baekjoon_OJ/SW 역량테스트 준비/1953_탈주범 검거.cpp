#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, M, R, C, L;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int map[50][50];
bool ok[50][50];
bool check[50][50];

void go(int y, int x, int move) {
	ok[y][x] = 1;

	if (move == 0)	return;
	
	int d = map[y][x];
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i], nx = x + dx[i];
		if (ny >= N || ny < 0 || nx >= M || nx < 0)	continue;
		if (map[ny][nx] == 0)	continue;
		if (check[ny][nx])	continue;

		if (i == 0 && (d == 1 || d == 2 || d == 4 || d == 7)) {
			if (map[ny][nx] != 3 && map[ny][nx] != 4 && map[ny][nx] != 7) {
				check[ny][nx] = 1;
				go(ny, nx, move - 1);
				check[ny][nx] = 0;
			}
		}
		else if (i == 1 && (d == 1 || d == 3 || d == 4 || d == 5)) {
			if (map[ny][nx] != 2 && map[ny][nx] != 4 && map[ny][nx] != 5) {
				check[ny][nx] = 1;
				go(ny, nx, move - 1);
				check[ny][nx] = 0;
			}
		}
		else if (i == 2 && (d == 1 || d == 2 || d == 5 || d == 6)) {
			if (map[ny][nx] != 3 && map[ny][nx] != 5 && map[ny][nx] != 6) {
				check[ny][nx] = 1;
				go(ny, nx, move - 1);
				check[ny][nx] = 0;
			}
		}
		else if (i == 3 && (d == 1 || d == 3 || d == 6 || d == 7)) {
			if (map[ny][nx] != 2 && map[ny][nx] != 6 && map[ny][nx] != 7) {
				check[ny][nx] = 1;
				go(ny, nx, move - 1);
				check[ny][nx] = 0;
			}
		}
	}

}

int main() {
	memset(check, 0, sizeof(check));
	
	int tc;
	scanf("%d", &tc);

	for (int t = 0; t < tc; t++) {
		memset(ok, 0, sizeof(ok));
		scanf("%d %d %d %d %d", &N, &M, &R, &C, &L);
				
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf("%d", &map[i][j]);
			}
		}
		check[R][C] = 1;
		go(R, C, L - 1);
		check[R][C] = 0;

		int ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (ok[i][j])	ans++;
			}
		}
		printf("#%d %d\n", t + 1, ans);
	}
}