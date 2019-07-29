#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int map[8][8];
int check[8][8];
int ans = 64;
vector<pair<int, int>> cctv;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

void go(int y, int x, int dir, int index) {
	while (1) {
		y = y + dy[dir];
		x = x + dx[dir];
		if (y >= N || y < 0 || x >= M || x < 0)
			return;
		if (map[y][x] == 6)
			return;
		if (map[y][x] >= 1 && map[y][x] <= 5)	continue;
		
		if (map[y][x] == 0){
			map[y][x] = -1;
			check[y][x] = index;
		}
	}
}

void go_back(int y, int x, int dir, int index) {
	while (1) {
		y = y + dy[dir];
		x = x + dx[dir];
		if (y >= N || y < 0 || x >= M || x < 0)
			break;
		if (map[y][x] == 6)
			break;
		
		if (map[y][x] == -1 && check[y][x] == index) {
			map[y][x] = 0;
			check[y][x] = 0;
		}
	}
}

void solve(int index) {
	
	if (index == cctv.size()) {
		int safe = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 0)
					safe++;
			}
		}
		if (safe < ans) {
			
		}
	
		/*
			cout << "------------------------" << endl;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				printf("%3d", map[i][j]);
				//cout << map[i][j] << " ";
			}
			cout << "\n";
		}
		cout << safe << endl;
		cout << "------------------------" << endl;
		*/
		ans = min(ans, safe);
		return;
	}

	auto out = cctv[index];
	int y = out.first, x = out.second;
	int type = map[y][x];
	
	if (type == 1) {
		for (int i = 0; i < 4; i++) {
			go(y, x, i, index);
			solve(index + 1);
			go_back(y, x, i, index);
		}
	}
	else if (type == 2) {
		for (int i = 0; i < 2; i++) {
			go(y, x, i, index);
			go(y, x, i + 2, index);
			solve(index + 1);
			go_back(y, x, i, index);
			go_back(y, x, i + 2, index);
		}
	}
	else if (type == 3) {
		for (int i = 0; i < 4; i++) {
			go(y, x, i % 4, index);
			go(y, x, (i + 1) % 4, index);
			solve(index + 1);
			go_back(y, x, i % 4, index);
			go_back(y, x, (i + 1) % 4, index);
		}
	}
	else if (type == 4) {
		for (int i = 0; i < 4; i++) {
			go(y, x, i % 4, index);
			go(y, x, (i + 1) % 4, index);
			go(y, x, (i + 2) % 4, index);
			solve(index + 1);
			go_back(y, x, i % 4, index);
			go_back(y, x, (i + 1) % 4, index);
			go_back(y, x, (i + 2) % 4, index);
		}
	}
	else if (type == 5) {
		go(y, x, 0, index);
		go(y, x, 1, index);
		go(y, x, 2, index);
		go(y, x, 3, index);
		solve(index + 1);
		go_back(y, x, 0, index);
		go_back(y, x, 1, index);
		go_back(y, x, 2, index);
		go_back(y, x, 3, index);
	}
	return;
}

int main() {
	memset(check, 0, sizeof(check));
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] >= 1 && map[i][j] <= 5) {
				cctv.push_back(make_pair(i, j));
			}
		}
	}
	solve(0);
	cout << ans;
}