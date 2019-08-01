#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int N;
char map[100][100];
bool check[100][100];

int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0, 0 };

bool color_check(int y, int x, char color, bool blind) {
	if (!blind) {
		if (color == map[y][x])	return true;
		else return false;
	}
	else {
		if (color == 'R' || color == 'G') {
			if (map[y][x] == 'R' || map[y][x] == 'G')	return true;
			else return false;
		}
		else {
			if (color == map[y][x])	return true;
			else return false;
		}
	}
}

void bfs(int sy, int sx, bool blind) {
	queue<pair<int, int>> q;
	q.emplace(sy, sx);
	check[sy][sx] = 1;
	char color = map[sy][sx];
	while (!q.empty()) {
		auto out = q.front();
		q.pop();
		int y = out.first, x = out.second;
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i], nx = x + dx[i];
			if (ny >= N || ny < 0 || nx >= N || nx < 0)	continue;
			if (check[ny][nx])	continue;
			bool ok = color_check(ny, nx, color, blind);
			if (ok) {
				
				q.push(make_pair(ny, nx));
				check[ny][nx] = 1;
			}
		}
	}
}


int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	
	memset(check, 0, sizeof(check));
	int A = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (check[i][j] == 0) {
				bfs(i, j, 0);
				A++;
			}
		}
	}

	memset(check, 0, sizeof(check));
	int B = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (check[i][j] == 0) {
				bfs(i, j, 1);
				B++;
			}
		}
	}

	cout << A << " " << B;
}