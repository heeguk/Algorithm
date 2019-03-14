/*
안전구역의 정의를 잘 생각해보기.
안전구역이란 바이러스가 퍼진 후에도 전염이 안되고 남아있는 곳.
*/

#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int map[8][8];
int temp[8][8];
bool check[8][8];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int N, M;
int result = 0;

vector<int> start;
vector<int> link;

void copy() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			temp[i][j] = map[i][j];
		}
	}
}

int virus() {
	memset(check, 0, sizeof(check));
	queue<pair<int, int>> q;

	int ret = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (temp[i][j] == 2){
				q.push(make_pair(i, j));
				check[i][j] = 1;
			}
		}
	}

	while (!q.empty()) {
		pair<int, int> out = q.front();
		q.pop();
		int y = out.first;
		int x = out.second;

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < N && ny >= 0 && nx < M && nx >= 0 && check[ny][nx] == 0 && temp[ny][nx] == 0) {
				check[ny][nx] = 1;
				temp[ny][nx] = 2;
				q.push(make_pair(ny, nx));
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (temp[i][j] == 0) {
				ret++;
			}
		}
	}

	return ret;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	memset(check, 0, sizeof(check));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	
	//int init = virus();

	for (int a = 0; a < N; a++) {
		for (int b = 0; b < M; b++) {
			if (map[a][b] != 0)
				continue;
			for (int c = 0; c < N; c++) {
				for (int d = 0; d < M; d++) {
					if (a == c && b == d)
						continue;
					if (map[c][d] != 0)
						continue;


					for (int e = 0; e < N; e++) {
						for (int f = 0; f < M; f++) {
							if (a == e && b == f)
								continue;
							if (c == e && d == f)
								continue;
							if (map[e][f] != 0)
								continue;

							copy();

							temp[a][b] = 1;
							temp[c][d] = 1;
							temp[e][f] = 1;
							int safe = virus();
							result = max(result, safe);
						}
					}

				}
			}
		}
	}

	cout << result << '\n';
}