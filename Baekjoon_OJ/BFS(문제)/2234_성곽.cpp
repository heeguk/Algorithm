#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
int R, C;
int map[50][50];
int check[50][50];
vector<int> room_size;

int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { -1, 0, 1, 0 };

void bfs(int sy, int sx, int room) {
	queue<pair<int, int>> q;
	q.emplace(sy, sx);
	check[sy][sx] = room;
	int size = 0;
	while (!q.empty()) {
		auto out = q.front();
		q.pop();
		size++;
		int y = out.first, x = out.second;
		for (int i = 0; i < 4; i++) {
			if (map[y][x] & (1 << i)) continue;
			int ny = y + dy[i], nx = x + dx[i];
			if (ny >= R || ny < 0 || nx >= C || nx < 0)	continue;
			if (check[ny][nx] == -1) {
				check[ny][nx] = room;
				q.emplace(ny, nx);
			}
		}	
	}
	room_size.push_back(size);
}

int main() {
	memset(check, -1, sizeof(check));
	cin >> C >> R;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
		}
	}

	int room = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (check[i][j] == -1) {
				bfs(i, j, room);
				room++;
			}
		}
	}
	int max_size = 0;
	for (int i = 0; i < room_size.size(); i++) {
		max_size = max(max_size, room_size[i]);
	}

	int max_max = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			for (int d = 0; d < 4; d++) {
				if (map[i][j] & (1 << d)) {
					int ny = i + dy[d], nx = j + dx[d];
					if (ny >= R || ny < 0 || nx >= C || nx < 0)	continue;
					int room_no1 = check[i][j];
					int room_no2 = check[ny][nx];
					if (room_no1 != room_no2) {
						max_max = max(max_max, room_size[room_no1] + room_size[room_no2]);
					}
				}
				
			}
		}
	}


	cout << room << "\n" << max_size << "\n" << max_max;
}
