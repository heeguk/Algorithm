#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

class node {
public:
	int y;
	int x;
	int c;

	node(int y_, int x_, int c_) {
		y = y_, x = x_, c = c_;
	}
};


int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0, 0 };
int hy[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int hx[8] = { -2, -1, 1, 2, -2, -1, 1, 2 };

int map[200][200];
int check[200][200][31];

int main() {
	memset(check, -1, sizeof(check));
	int K, W, H;
	cin >> K;
	cin >> W >> H;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> map[i][j];
		}
	}

	queue<node> q;
	q.push(node(0, 0, K));
	check[0][0][K] = 0;
	while (!q.empty()) {
		node out = q.front();
		q.pop();
		int y = out.y, x = out.x, c = out.c;

		if (y == H - 1 && x == W - 1) {
			cout << check[y][x][c];
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i], nx = x + dx[i];
			if (ny >= H || ny < 0 || nx >= W || nx < 0)	continue;
			if (map[ny][nx] == 1)	continue;
			if (check[ny][nx][c] == -1) {
				check[ny][nx][c] = check[y][x][c] + 1;
				q.push(node(ny, nx, c));
			}
		}

		if (c == 0)	continue;
		for (int i = 0; i < 8; i++) {
			int ny = y + hy[i], nx = x + hx[i];
			if (ny >= H || ny < 0 || nx >= W || nx < 0)	continue;
			if (map[ny][nx] == 1)	continue;
			if (check[ny][nx][c - 1] == -1) {
				check[ny][nx][c - 1] = check[y][x][c] + 1;
				q.push(node(ny, nx, c - 1));
			}
		}
	}
	cout << -1;
}