#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int R, C;
char map[250][250];
bool check[250][250];
int A = 0;
int B = 0;

void bfs(int sy, int sx) {
	queue<pair<int, int>> q;
	q.push(make_pair(sy, sx));
	check[sy][sx] = 1;

	int a = 0, b = 0;

	while (!q.empty()) {
		auto out = q.front();
		q.pop();
		int y = out.first, x = out.second;
		if (map[y][x] == 'o') a++;
		else if (map[y][x] == 'v') b++;
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i], nx = x + dx[i];
			if (ny >= R || ny < 0 || nx >= C || nx < 0)	continue;
			if (map[ny][nx] == '#')	continue;
			if (check[ny][nx])	continue;
			check[ny][nx] = 1;
			q.push(make_pair(ny, nx));
		}
	}

	if (a > b)	b = 0;
	else a = 0;

	A += a;
	B += b;

}

int main() {
	memset(check, 0, sizeof(check));
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (!check[i][j])	bfs(i, j);
		}
	}
	cout << A << " " << B;
}