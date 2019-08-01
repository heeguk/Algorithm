#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int R, C, K;
int map[1000][1000];
int check[1000][1000][11];

class node {
public:
	int y;
	int x;
	int chance;

	node(int a, int b, int c) {
		y = a, x = b, chance = c;
	}
};

void bfs(int sy, int sx) {
	queue<node> q;
	q.push(node(sy, sx, K));
	check[sy][sx][K] = 1;

	while (!q.empty()) {
		auto out = q.front();
		q.pop();
		int y = out.y, x = out.x, c = out.chance;
		//cout << y << " " << x << " " << c << endl;
		if (y == R - 1 && x == C - 1) {
			cout << check[y][x][c];
			exit(0);
		}

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i], nx = x + dx[i];
			if (ny >= R || ny < 0 || nx >= C || nx < 0)	continue;
			if (map[ny][nx] == 0 && check[ny][nx][c] == -1) {
				check[ny][nx][c] = check[y][x][c] + 1;
				q.push(node(ny, nx, c));
			}
			if (map[ny][nx] == 1 && c > 0 && check[ny][nx][c - 1] == -1) {
				check[ny][nx][c - 1] = check[y][x][c] + 1;
				q.push(node(ny, nx, c - 1));
			}
		}
	}
	cout << -1;
}

int main() {
	memset(check, -1, sizeof(check));
	cin >> R >> C >> K;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	bfs(0, 0);
}