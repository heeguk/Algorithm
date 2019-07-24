#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

bool check[201];
bool check2[201][201];
vector<int> c;
queue<pair<int, int>> q;

int water[3];

int from[6] = { 0, 0, 1, 1, 2, 2 };
int to[6] = { 1, 2, 0, 2, 0, 1 };

int main() {
	memset(check, 0, sizeof(check));
	memset(check2, 0, sizeof(check2));
	cin >> water[0] >> water[1] >> water[2];
	
	q.push(make_pair(0, 0));
	check[water[2]] = 1;
	check2[0][0] = 1;
	c.push_back(water[2]);
	int TOTAL = water[2];

	while (!q.empty()) {
		auto out = q.front();
		q.pop();
		int w[3];
		for (int i = 0; i < 6; i++) {
			w[0] = out.first, w[1] = out.second;
			w[2] = TOTAL - w[0] - w[1];

			
			// 이동시킬 물이 없음
			if (w[from[i]] == 0) continue;
			
			// 물을 이동시킴
			w[to[i]] = w[from[i]] + w[to[i]];
			w[from[i]] = 0;

			// 물이 넘치는 경우
			if (w[to[i]] > water[to[i]]) {
				w[from[i]] = w[to[i]] - water[to[i]];
				w[to[i]] = water[to[i]];
			}

			if (check2[w[0]][w[1]] == 0) {
				check2[w[0]][w[1]] = 1;
				if (w[0] == 0 && check[TOTAL - w[0] - w[1]] == 0) {
					check[TOTAL - w[0] - w[1]] = 1;
					c.push_back(w[2]);
				}
				q.push(make_pair(w[0], w[1]));
			}
		}
	}

	sort(c.begin(), c.end());
	for (int i = 0; i < c.size(); i++)	cout << c[i] << " ";
}