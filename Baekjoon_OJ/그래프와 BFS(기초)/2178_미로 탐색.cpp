#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

bool check[100][100];
int map[100][100];
int cell[100][100];
int H, W;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void bfs(int sy, int sx) {
	check[sy][sx] = true;
	cell[sy][sx] = 1;
	queue<pair<int, int>> q;
	q.push(make_pair(sy, sx));
	

	while (!q.empty()) {
		pair<int, int> out = q.front();
		q.pop();
		int y = out.first;
		int x = out.second;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < W && ny >= 0 && ny < H && !check[ny][nx] && map[ny][nx]) {
				check[ny][nx] = 1;
				cell[ny][nx] = cell[y][x] + 1;
				q.push(make_pair(ny, nx));
			}
		}
	}
}


int main() {
	cin >> H >> W;

	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			scanf("%1d", &map[y][x]);
		}
	}

	bfs(0, 0);
	cout << cell[H - 1][W - 1] << endl;
}