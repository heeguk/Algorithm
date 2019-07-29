#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
int map[8][8];
bool check[8][8];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
int safe = 0;

int bfs() {
	memset(check, 0, sizeof(check));
	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 2) {
				q.push(make_pair(i, j));
				check[i][j] = 1;
			}
		}
	}
	int spread = 0;

	while (!q.empty()) {
		auto out = q.front();
		q.pop();
		int y = out.first, x = out.second;
		
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i], nx = x + dx[i];
			if (ny >= N || ny < 0 || nx >= M || nx < 0)	continue;
			if (check[ny][nx] == 0 && map[ny][nx] == 0) {
				check[ny][nx] = 1;
				//cout << ny << ", " << nx << endl;
				q.push(make_pair(ny, nx));
				spread++;
			}
		}
	}

	return safe - spread - 3;	// 3을 빼주는 이유은 벽을 제거
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0)	safe++;
		}
	}
	int ans = 0;
	for (int y1 = 0; y1 < N; y1++) {
		for (int x1 = 0; x1 < M; x1++) {
			if (map[y1][x1] != 0)	continue;
			for (int y2 = 0; y2 < N; y2++) {
				for (int x2 = 0; x2 < M; x2++) {
					if (map[y2][x2] != 0)	continue;
					if (y1 == y2 && x1 == x2)	continue;
					for (int y3 = 0; y3 < N; y3++) {
						for (int x3 = 0; x3 < M; x3++) {
							if (map[y3][x3] != 0)	continue;
							if (y1 == y3 && x1 == x3)	continue;
							if (y3 == y2 && x3 == x2)	continue;
							map[y1][x1] = 1;
							map[y2][x2] = 1;
							map[y3][x3] = 1;
							ans = max(ans, bfs());
							map[y1][x1] = 0;
							map[y2][x2] = 0;
							map[y3][x3] = 0;
						}
					}
				}
			}
		}
	}
	cout << ans;
}