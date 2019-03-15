/*
문제 풀 때 범위를 벗어나는지 항상 체크하기!
문제 오류의 대부분의 이유는 벗어난 인덱스를 참조할 때임.
*/

#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int map[8][8];
bool check[8][8];

int N, M;
int result = 65;
int Size;

vector<int> direction;
vector<pair<int, int>> cctv;

void copy(int arr1[8][8], int arr2[8][8]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			arr1[i][j] = arr2[i][j];
		}
	}
}

void right(int y, int x){
	while (1) {
		x = x + 1;
		if (x >= M)
			break;
		if (map[y][x] == 6)
			break;
		if (map[y][x] == 0)
			map[y][x] = -1;
	}
}

void left(int y, int x) {
	while (1) {
		x = x - 1;
		if (x < 0)
			break;
		if (map[y][x] == 6)
			break;
		if (map[y][x] == 0)
			map[y][x] = -1;
	}
}

void down(int y, int x) {
	while (1) {
		y = y + 1;
		if (y >= N)
			break;
		if (map[y][x] == 6)
			break;
		if (map[y][x] == 0)
			map[y][x] = -1;
	}
}

void up(int y, int x) {
	while (1) {
		y = y - 1;
		if (y < 0)
			break;
		if (map[y][x] == 6)
			break;
		if (map[y][x] == 0)
			map[y][x] = -1;
	}
}

void go(int n) {
	if (n == Size) {
		int safe = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 0)
					safe++;
			}
		}
		result = min(result, safe);
		return;
	}

	pair<int, int> out = cctv[n];
	int y = out.first;
	int x = out.second;
	int temp[8][8];
	int type = map[y][x];

	copy(temp, map);

	for (int i = 0; i < 4; i++) {
		switch (type) {
		case 1:
			if (i == 0)
				right(y, x);
			else if (i == 1)
				down(y, x);
			else if (i == 2)
				left(y, x);
			else if (i == 3)
				up(y, x);
			break;
		case 2:
			if (i == 0 || i == 2) {
				left(y, x);
				right(y, x);
			}
			else {
				up(y, x);
				down(y, x);

			}
			break;
		case 3:
			if (i == 0) {
				up(y, x);
				right(y, x);
			}
			else if (i == 1) {
				right(y, x);
				down(y, x);
			}
			else if (i == 2) {
				left(y, x);
				down(y, x);
			}
			else if (i == 3) {
				left(y, x);
				up(y, x);
			}
			break;
		case 4:
			if (i == 0) {
				left(y, x);
				up(y, x);
				right(y, x);
			}
			else if (i == 1) {
				up(y, x);
				right(y, x);
				down(y, x);
			}
			else if (i == 2) {
				right(y, x);
				left(y, x);
				down(y, x);
			}
			else if (i == 3) {
				left(y, x);
				up(y, x);
				down(y, x);
			}
			break;
		case 5:
			right(y, x);
			left(y, x);
			up(y, x);
			down(y, x);
			break;
		}
		go(n + 1);
		copy(map, temp);
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	memset(check, 0, sizeof(check));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] > 0 && map[i][j] < 6){
				cctv.push_back(make_pair(i, j));
			}
		}
	}
	Size = cctv.size();

	go(0);

	cout << result << '\n';
}