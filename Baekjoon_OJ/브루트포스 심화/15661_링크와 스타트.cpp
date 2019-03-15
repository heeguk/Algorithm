/*
브루트포스 문제
팀의 수가 최대 20이므로
시간복잡도가 2^20이므로 모든 경우를 고려해서 문제를 풀 수 있음.
하지만, 예외적인 케이스도 고려해야함. (팀에 아무도 속하지 않은 경우)
*/

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int map[500][500];
bool check[500][500];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int ndy[4][4] = { {0, 0, 0, 1}, {0, 0, 0, -1}, {0, 1, 2, 1}, {0, 1, 2, 1} };
int ndx[4][4] = { {0, 1, 2, 1}, {0, 1, 2, 1}, {0, 0, 0, 1}, {0, 0, 0, -1} };

int N;
int result = 999999999;

vector<int> start;
vector<int> link;

int calculatate(){
	int sum1 = 0;
	int sum2 = 0;
	int ret;

	for (int i = 0; i < start.size(); i++) {
		for (int j = 0; j < start.size(); j++) {
			if (i == j)
				continue;
			sum1 += map[start[i]][start[j]];
		}
	}

	for (int i = 0; i < link.size(); i++) {
		for (int j = 0; j < link.size(); j++) {
			if (i == j)
				continue;
			sum2 += map[link[i]][link[j]];
		}
	}
	if (sum1 > sum2)
		ret = sum1 - sum2;
	else
		ret = sum2 - sum1;

	return ret;
}

void go(int n) {
	if (n == N) {
		if (start.size() == 0 || link.size() == 0)
			return;

		int ret = calculatate();
		if (result > ret)
			result = ret;

		return;
	}

	// team start
	start.push_back(n);
	go(n + 1);
	start.pop_back();

	// team link
	link.push_back(n);
	go(n + 1);
	link.pop_back();
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	memset(check, 0, sizeof(check));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	go(0);

	cout << result << '\n';
}