#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int N;
char map[50][50];
bool check[50][50][4];

int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

class node {
public:
	int y;
	int x;
	int dir;
	int mirror;

	node(int a, int b, int c, int d) {
		y = a, x = b, dir = c, mirror = d;
	}
};

int main() {
	cin >> N;
	vector<pair<int, int>> door;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == '#') {
				door.emplace_back(i, j);
			}
		}
	}
	int sy = door[0].first, sx = door[0].second;
	int ty = door[1].first, tx = door[1].second;
	queue<node> q;
	for (int i = 0; i < 4; i++) {
		q.push(node(sy, sx, i, 0));
		check[sy][sx][i] = 1;
	}

	while (!q.empty()) {
		auto out = q.front();
		q.pop();
		int y = out.y, x = out.x, dir = out.dir, mirror = out.mirror;
		
		while (1) {
			y = y + dy[dir], x = x + dx[dir];
			if (y >= N || y < 0 || x >= N || x < 0)	break;
			if (map[y][x] == '*')	break;
			if (check[y][x][dir])	break;
			check[y][x][dir] = 1;
			if (map[y][x] == '!') {
				int ndir = (dir + 1) % 4;
				check[y][x][ndir] = 1;
				q.push(node(y, x, ndir, mirror + 1));
				ndir = (dir + 3) % 4;
				check[y][x][ndir] = 1;
				q.push(node(y, x, ndir, mirror + 1));
			}
			if (map[y][x] == '#') {
				cout << mirror;
				return 0;
			}
		}
	}
	

}