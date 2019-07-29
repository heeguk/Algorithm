#include <iostream>
#include <cstring>
#include <deque>
#include <stack>
#include <vector>
using namespace std;

bool check[101][101];
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { 1, 0, -1, 0 };

void solve(int y, int x, int d, int g) {
	check[y][x] = 1;
	y = y + dy[d];
	x = x + dx[d];
	check[y][x] = 1;
	
	vector<int> dir;
	dir.push_back(d);

	for (int t = 0; t < g; t++) {
		int iter_size = dir.size();
		for (int i = 0; i < iter_size; i++) {
			int ndir = (dir[iter_size - 1 - i] + 1) % 4;
			y = y + dy[ndir];
			x = x + dx[ndir];
			check[y][x] = 1;
			dir.push_back(ndir);
		}
	}
}

int main() {
	memset(check, 0, sizeof(check));
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		solve(y, x, d, g);
	}

	int ans = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (check[i][j] && check[i + 1][j] && check[i][j + 1] && check[i + 1][j + 1])	ans++;
		}
	}
	cout << ans;
}