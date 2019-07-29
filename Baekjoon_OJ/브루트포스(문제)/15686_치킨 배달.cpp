#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int map[50][50];
vector<pair<int, int>> ch;
vector<pair<int, int>> ch_ing;
int ans = 14000;


void solve(int index, int cnt) {
	if (cnt == M) {
		int ch_d = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == 1) {
					int d = 1000;
					for (int c = 0; c < ch_ing.size(); c++) {
						auto out = ch_ing[c];
						int y = out.first, x = out.second;
						d = min(d, abs(i - y) + abs(j - x));
					}
					ch_d += d;
				}
			}
		}
		ans = min(ans, ch_d);
		return;
	}
	if (index >= ch.size()) {
		return;
	}
	int y = ch[index].first, x = ch[index].second;


	// 해당 치킨집을 그대로 운영
	ch_ing.push_back(ch[index]);
	solve(index + 1, cnt + 1);
	ch_ing.pop_back();

	// 해당 치킨집을 폐업
	solve(index + 1, cnt);
}

int main() {
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2)	ch.push_back(make_pair(i, j));
		}
	}
	
	solve(0, 0);

	cout << ans;
}