#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
char map[30][30];
int check[30][30];
int blank;
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0, 0 };
int ans = -1;


bool is_ok(int y, int x) {
	return (y < N && y >= 0 && x < M && x >= 0);
}

void go(int y, int x, int move, int cnt) {
	if (cnt - 1 == 0) {
		if (ans == -1) {
			ans = move;
		}
		else {
			ans = min(ans, move);
		}
	}
	for (int i = 0; i < 4; i++) {
		check[y][x] = i;
		int ncnt = cnt;
		int ny = y + dy[i], nx = x + dx[i];
		int nmove = 0;
		int m = 1;
		while (is_ok(ny, nx) && map[ny][nx] == '.' && check[ny][nx] == -1) {
			check[ny][nx] = i;
			ny = ny + dy[i], nx = nx + dx[i];
			ncnt--;
			m++;
			nmove = 1;
		}
		if (nmove) {
			ny = ny - dy[i], nx = nx - dx[i];
			go(ny, nx, move + nmove, ncnt);
		}
		for (int k = 0; k < m; k++) {
			check[y + dy[i] * k][x + dx[i] * k] = -1;
		}
	}
}

int main() {
	int n = 1;
	while (cin >> N >> M) {
		memset(check, -1, sizeof(check));
		ans = -1;
		blank = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> map[i][j];
				if (map[i][j] == '.')	blank++;
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == '.') {
					go(i, j, 0, blank);
				}
			}
		}
		printf("Case %d: %d\n", n, ans);
		n++;
	}
}