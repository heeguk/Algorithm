/*
회전을 고려한다면 테트로미노의 경우의 수가
상당히 많아짐.
배열에 모양을 하나하나 저장할 수 있지만
더 효율적으로 문제를 푸는 방법이 있음.
하지만 예외적인 경우는 직접 배열에 모양을 저장해서
해결해야함.
*/

#include <iostream>
#include <cstring>
using namespace std;

int map[500][500];
bool check[500][500];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int ndy[4][4] = { {0, 0, 0, 1}, {0, 0, 0, -1}, {0, 1, 2, 1}, {0, 1, 2, 1} };
int ndx[4][4] = { {0, 1, 2, 1}, {0, 1, 2, 1}, {0, 0, 0, 1}, {0, 0, 0, -1} };

int n, m;
int result = 0;

void go(int cnt, int y, int x, int sum) {
	
	if (cnt == 4) {
		if (result < sum)
			result = sum;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < n && ny >= 0 && nx < m && nx >= 0 && check[ny][nx] == 0) {
			check[ny][nx] = 1;
			go(cnt + 1, ny, nx, sum + map[ny][nx]);
			check[ny][nx] = 0;
		}
	}
}

void go2(int y, int x) {

	for (int i = 0; i < 4; i++) {
		int sum = 0;
		for (int j = 0; j < 4; j++) {
			int ny = y + ndy[i][j];
			int nx = x + ndx[i][j];
			if (ny < n && ny >= 0 && nx < m && nx >= 0) {
				sum += map[ny][nx];
			}
			else {
				break;
			}

			if (j == 3) {
				if (result < sum)
					result = sum;
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	memset(check, 0, sizeof(check));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			check[i][j] = 1;
			go(1, i, j, map[i][j]);
			check[i][j] = 0;
			go2(i, j);
		}
	}

	cout << result << '\n';
}