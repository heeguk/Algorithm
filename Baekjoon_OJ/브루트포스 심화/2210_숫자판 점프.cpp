/*
쉬운문제.
이 문제는 중복하는 경우를 없애기 위해 set을 사용해도 됨.
혹은 bool 배열을 만들어서 중복을 판단할 수 있음.
*/
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;

int map[5][5];

int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0, 0 };

set<int> ans;
bool make[1000000];

void solve(int step, int y, int x, int sum) {
	if (step == 6) {
		ans.insert(sum);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if(ny >= 0 && ny < 5 && nx >= 0 && nx < 5)
			solve(step + 1, ny, nx, sum * 10 + map[ny][nx]);
	}
}

int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> map[i][j];
		}
	}

	memset(make, 0, sizeof(make));

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			solve(1, i, j, map[i][j]);
		}
	}

	cout << ans.size() << '\n';
}