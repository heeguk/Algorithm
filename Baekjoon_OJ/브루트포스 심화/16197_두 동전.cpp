/*
쉬운문제.
중복하는 경우를 없애줘야함.
없애는 방법을 잘 생각해보기.
*/
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;

int N, M;

char map[20][20];

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int result = 11;

void solve(int step, int y1, int x1, int y2, int x2) {
	if (step == 11) {
		return;
	}

	bool out1, out2;
	out1 = out2 = false;
	if (y1 < 0 || y1 >= N || x1 < 0 || x1 >= M)
		out1 = true;
	if (y2 < 0 || y2 >= N || x2 < 0 || x2 >= M)
		out2 = true;

	if (out1 && out2)
		return;

	if (out1 || out2){
		result = min(result, step);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int ny1 = y1 + dy[i];
		int ny2 = y2 + dy[i];
		int nx1 = x1 + dx[i];
		int nx2 = x2 + dx[i];

		if (ny1 < N && ny1 >= 0 && nx1 < M && nx1 >= 0 && map[ny1][nx1] == '#') {
			ny1 = y1;
			nx1 = x1;
		}
		if (ny2 < N && ny2 >= 0 && nx2 < M && nx2 >= 0 && map[ny2][nx2] == '#') {
			ny2 = y2;
			nx2 = x2;
		}

		solve(step + 1, ny1, nx1, ny2, nx2);
	}
	return;
}

int main() {
	cin >> N >> M;
	
	int cy[2];
	int cx[2];

	int index = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'o') {
				cy[index] = i;
				cx[index] = j;
				index++;
			}
		}
	}

	solve(0, cy[0], cx[0], cy[1], cx[1]);
	if (result == 11)
		cout << -1 << '\n';
	else
		cout << result << '\n';
}