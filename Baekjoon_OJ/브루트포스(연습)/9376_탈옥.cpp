#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <cstring>
using namespace std;

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
int R, C;
void bfs(int y, int x, char map[102][102], int map_[102][102]) {
	deque<pair<int, int>> q;
	q.push_front(make_pair(y, x));

	map_[y][x] = 0;
	while (!q.empty()) {
		auto out = q.front();
		q.pop_front();
		for (int i = 0; i < 4; i++) {
			int ny = out.first + dy[i];
			int nx = out.second + dx[i];
			if (ny >= R + 2 || ny < 0 || nx >= C + 2 || nx < 0) continue;
			if (map[ny][nx] == '*')	continue;

			if (map[ny][nx] == '#') {
				if (map_[ny][nx] == -1) {
					map_[ny][nx] = map_[out.first][out.second] + 1;
					q.push_back(make_pair(ny, nx));
				}
			}
			else if (map_[ny][nx] == -1) {
				map_[ny][nx] = map_[out.first][out.second];
				q.push_front(make_pair(ny, nx));
			}
		}
	}
}

int main() {
	int tc;
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		
		cin >> R >> C;
		vector<pair<int, int>> people;
		char map[100 + 2][100 + 2];
		int map1[100 + 2][100 + 2], map2[100 + 2][100 + 2], map3[100 + 2][100 + 2];
		memset(map1, -1, sizeof(map1));
		memset(map2, -1, sizeof(map2));
		memset(map3, -1, sizeof(map3));
		for (int i = 0; i < R + 2; i++) {
			for (int j = 0; j < C + 2; j++) {
				map[i][j] = '.';
			}
		}

		for(int i = 1; i < R + 1; i++) {
			for (int j = 1; j < C + 1; j++) {
				cin >> map[i][j];
				if (map[i][j] == '$')
					people.push_back(make_pair(i, j));
			}
		}

		bfs(0, 0, map, map1);
		bfs(people[0].first, people[0].second, map, map2);
		bfs(people[1].first, people[1].second, map, map3);
		int ans = map1[0][0] + map2[0][0] + map3[0][0];
		for (int i = 0; i < R + 2; i++) {
			for (int j = 0; j < C + 2; j++) {
				if (map[i][j] == '*')	continue;
				if (map[i][j] == '#') {
					ans = min(ans, map1[i][j] + map2[i][j] + map3[i][j] - 2);
				}
				else {
					ans = min(ans, map1[i][j] + map2[i][j] + map3[i][j]);
				}
			}
		}
		cout << ans << "\n";
	}

}