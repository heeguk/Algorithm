#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
int R, C;
char map[1501][1501];
int check[1501][1501];
bool check2[1501][1501];
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
	cin >> R >> C;
	vector<pair<int, int>> L;
	queue<pair<int, int>> q;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'L') {
				L.emplace_back(i, j);
				map[i][j] = '.';
			}

			if (map[i][j] == '.') {
				check[i][j] = 0;
				q.emplace(i, j);
			}
		}
	}

	while (!q.empty()) {
		auto out = q.front();
		int y = out.first, x = out.second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i], nx = x + dx[i];
			if (ny >= R || ny < 0 || nx >= C || nx < 0)	continue;
			if (map[ny][nx] == 'X' && check[ny][nx] == -1) {
				map[ny][nx] = '.';
				check[ny][nx] = check[y][x] + 1;
				q.emplace(ny, nx);
			}
		}

	}

	int sy = L[0].first, sx = L[0].second;
	int ty = L[1].first, tx = L[1].second;

	int time = 0;
	bool find = 0;
	queue<pair<int, int>> nq;
	memset(check2, 0, sizeof(check2));
	check2[sy][sx] = 1;
	nq.emplace(sy, sx);
	queue<pair<int, int>> emp;
	while (1) {
		//cout << time << endl;
		q = nq;
		//cout << nq.size() << endl;
		if (time > 0) {
			nq = emp;
		}

		int n = 0;
		while (!q.empty()) {
			auto out = q.front();
			int y = out.first, x = out.second;
			q.pop();
			//cout << y << ", " << x << endl;
			if (y == ty && x == tx) {
				find = 1;
				break;
			}
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i], nx = x + dx[i];
				if (ny >= R || ny < 0 || nx >= C || nx < 0)	continue;
				if (check2[ny][nx] == 0 && check[ny][nx] <= time) {
					check2[ny][nx] = 1;
					q.emplace(ny, nx);
					if(check[ny][nx] == time)	nq.emplace(ny, nx);
				}
			}
			n++;
		}
		//cout << "iteration: " << n << endl;
		if (find) {
			cout << time;
			break;
		}
		time++;
	}
}