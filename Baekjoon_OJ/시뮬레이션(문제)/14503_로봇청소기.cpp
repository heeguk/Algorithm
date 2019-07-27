#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int map[50][50];
bool clean[50][50];
bool check[50][50][4];
int N, M;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

class robot{
public:
	int y;
	int x;
	int dir;
	
	robot(int Y, int X, int Dir) {
		y = Y, x = X, dir = Dir;
	}
};

int main() {
	memset(clean, 0, sizeof(clean));
	memset(check, 0, sizeof(check));
	cin >> N >> M;

	int sy, sx, sdir;
	cin >> sy >> sx >> sdir;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	queue<robot> q;
	q.push(robot(sy, sx, sdir));
	check[sy][sx][sdir] = 1;
	while (!q.empty()) {
		auto out = q.front();
		q.pop();
		int y = out.y, x = out.x, dir = out.dir;
		//cout << y << " " << x << " dir: " << dir << endl;
		// step 1
		clean[y][x] = 1;

		// step 2 - 1
		int ndir = (dir + 3) % 4;
		int ny = y + dy[ndir], nx = x + dx[ndir];
		if (map[ny][nx] == 0 && clean[ny][nx] == 0 && check[ny][nx][ndir] == 0) {
			q.push(robot(ny, nx, ndir));
			check[ny][nx][ndir] = 1;
			continue;
		}

		// step 2 - 2, 2 - 3
		// 네 방향이 모두 막혔는지 검사
		bool dir_check[4];
		int block = 0;
		for (int i = 0; i < 4; i++) {
			dir_check[i] = (map[y + dy[i]][x + dx[i]] == 1 || clean[y + dy[i]][x + dx[i]] == 1);
			block += dir_check[i];
		}
		if (block == 4) {
			int rear = (dir + 2) % 4;
			if (map[y + dy[rear]][x + dx[rear]] == 0) {	// step 2 - 2
				q.push(robot(y + dy[rear], x + dx[rear], dir));
				continue;
			}
			else {	// step 2 - 3
				break;
			}
		}

		// 네 방향이 모두 막히진 않음
		if (check[y][x][ndir] == 0) {
			q.push(robot(y, x, ndir));
			check[y][x][ndir] = 1;
		}
		
		
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (clean[i][j] == 1)	ans++;
		}
	}
	cout << ans;
}