#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int N, M;
int map[10][10];
int check[10][10][2];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

class node {
public:
	int y;
	int x;
	int c;
	int cross;
	node(int Y, int X, int C, int Cross) {
		y = Y, x = X, c = C, cross = Cross;
	}
};

int main() {
	memset(check, -1, sizeof(check));
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	queue<node> q;
	q.push(node(0, 0, 1, 0));
	check[0][0][1] = 0;

	while (!q.empty()) {
		auto out = q.front();
		q.pop();

		int y = out.y, x = out.x, c = out.c, cross = out.cross;
		//cout << y << ", " << x << " chance: " << c << "   time: " << check[y][x][c] << endl;
		int time = check[y][x][c];
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i], nx = x + dx[i];
			if (ny >= N || ny < 0 || nx >= N || nx < 0)	continue;
			if (map[ny][nx] == 1) {
				if (check[ny][nx][c] == -1) {
					check[ny][nx][c] = check[y][x][c] + 1;
					q.push(node(ny, nx, c, 0));
				}
				else if (check[ny][nx][c] > check[y][x][c] + 1) {
					check[ny][nx][c] = check[y][x][c] + 1;
					q.push(node(ny, nx, c, 0));
				}
			}
			if (!cross && c == 1 && map[ny][nx] == 0) {
				if (check[ny][nx][0] == -1) {
					check[ny][nx][0] = (time / M + 1) * M;
					q.push(node(ny, nx, 0, 1));
				}
				else if (check[ny][nx][0] > (time / M + 1) * M) {
					check[ny][nx][0] = (time / M + 1) * M;
					q.push(node(ny, nx, 0, 1));
				}
			}
			if (!cross && map[ny][nx] > 1) {
				if (check[ny][nx][c] == -1) {
					check[ny][nx][c] = (time / map[ny][nx] + 1) * map[ny][nx];
					q.push(node(ny, nx, c, 1));
				}
				else if (check[ny][nx][c] > (time / map[ny][nx] + 1) * map[ny][nx]) {
					check[ny][nx][c] = (time / map[ny][nx] + 1) * map[ny][nx];
					q.push(node(ny, nx, c, 1));
				}
			}
		}
	}

	if (check[N - 1][N - 1][1] != -1)	cout << min(check[N - 1][N - 1][0], check[N - 1][N - 1][1]);
	else cout << check[N - 1][N - 1][0];
}