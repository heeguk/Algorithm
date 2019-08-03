#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

class node {
public:
	int n[2];

	node(int a, int b) {
		n[0] = a, n[1] = b;
	}
	node() {

	}
};

int N;
node map[500][500];
int before[500 * 500 + 1];
int check[500][500];

int from[6] = { 0, 1 , 1, 1, 0, 0 };
int to[6] = { 1, 0, 0, 0, 1, 1 };

int dy1[6] = { -1, -1, 0, 1, 1, 0 };
int dx1[6] = { -1, 0, 1, 0, -1, -1 };
int dy2[6] = { -1, -1, 0, 1, 1, 0 };
int dx2[6] = { 0, 1, 1, 1, 0, -1 };
int cnt = 0;

void print(int a, int b) {
	cnt++;
	if (a != b) {
		print(before[a], a);
	}
	else {
		cout << cnt << endl;
	}
	cout << b << " ";
}

int get_index(int y, int x) {
	int index = 0;
	for (int i = 0; i < y; i++) {
		if (i % 2 == 0)
			index += N;
		else
			index += N - 1;
	}
	index += x + 1;
	return index;
}
int main() {
	cin >> N;
	memset(check, -1, sizeof(check));
	memset(before, 0, sizeof(before));
	for (int i = 0; i < N; i++) {
		int C = N;
		if (i % 2 == 1)
			C = N - 1;
		for (int j = 0; j < C; j++) {
			int a, b;
			cin >> a >> b;
			map[i][j] = node(a, b);
		}
	}
	before[get_index(0, 0)] = get_index(0, 0);
	queue<pair<int, int>> q;
	q.emplace(0, 0);
	check[0][0] = 1;
	int ty, tx;
	if (N % 2 == 1) {
		ty = N - 1, tx = N - 1;
	}
	else {
		ty = N - 1, tx = N - 2;
	}

	while (!q.empty()) {
		auto out = q.front();
		q.pop();
		int y = out.first, x = out.second;
		// cout << "out "<< y << " " << x << endl;
		/*
		if (y == ty && x == tx) {
			//cout << check[ty][tx] << endl;
			print(before[get_index(ty, tx)], get_index(ty, tx));
			return 0;
		}
		*/
		if (y % 2 == 0) {
			for (int i = 0; i < 6; i++) {
				int f = from[i], t = to[i];
				int ny = y + dy1[i], nx = x + dx1[i];
				if (ny % 2 == 1 && (ny >= N || ny < 0 || nx >= N - 1 || nx < 0))	continue;
				if (ny % 2 == 0 && (ny >= N || ny < 0 || nx >= N || nx < 0))	continue;
				// cout << "compare " << ny << ", " << nx << endl;
				if (map[y][x].n[f] != map[ny][nx].n[t] || before[get_index(ny, nx)] != 0)	continue;
				before[get_index(ny, nx)] = get_index(y, x);
				q.emplace(ny, nx);
				check[ny][nx] = check[y][x] + 1;
				// cout << "get: " << ny << ", " << nx << endl;
			}
		}
		else {
			for (int i = 0; i < 6; i++) {
				int f = from[i], t = to[i];
				int ny = y + dy2[i], nx = x + dx2[i];
				if (ny % 2 == 1 && (ny >= N || ny < 0 || nx >= N - 1 || nx < 0))	continue;
				if (ny % 2 == 0 && (ny >= N || ny < 0 || nx >= N || nx < 0))	continue;
				// cout << "compare " << ny << ", " << nx << endl;
				if (map[y][x].n[f] != map[ny][nx].n[t] || before[get_index(ny, nx)] != 0)	continue;
				before[get_index(ny, nx)] = get_index(y, x);
				q.emplace(ny, nx);
				check[ny][nx] = check[y][x] + 1;
				// cout << "get: " << ny << ", " << nx << endl;
			}
		}
	}
	
	int index = get_index(ty, tx);
	for (int i = index;; i--) {
		if (before[i] == 0)	continue;
		print(before[i], i);
		return 0;
	}
}