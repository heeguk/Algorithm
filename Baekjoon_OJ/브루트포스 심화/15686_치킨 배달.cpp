/*
final.push_back(out);
//go(n + 1, snum + 1);
final.pop_back();

치킨집을 고를 때 위와 같은 방법을 이용하면 편함.
치킨 거리의 정의를 잘 이해하기
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int map[50][50];

int N, M;
int result = 65000;
int Size;

vector<pair<int, int>> store;
vector<pair<int, int>> house;
vector<pair<int, int>> final;

int get_distance() {
	int ret = 0;

	for (int i = 0; i < house.size(); i++) {
		int hy = house[i].first;
		int hx = house[i].second;
		int dis = 101;
		for (int j = 0; j < final.size(); j++) {
			int cy = final[j].first;
			int cx = final[j].second;
			dis = min(dis, abs(cy - hy) + abs(cx - hx));
		}
		ret += dis;
	}

	return ret;
}

void go(int n, int snum) {
	if (snum > 0) {
		int ret = get_distance();
		result = min(result, ret);
		//return;
	}
	if (snum == M) {
		return;
	}
	if (n == Size) {
		return;
	}

	pair<int, int> out = store[n];

	// n 번째 치킨 집이 유지되는 경우
	final.push_back(out);
	go(n + 1, snum + 1);
	final.pop_back();

	// n 번째 치킨 집이 폐업되는 경우
	go(n + 1, snum);

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2){
				store.push_back(make_pair(i, j));
			}
			else if (map[i][j] == 1) {
				house.push_back(make_pair(i, j));
			}
		}
	}
	Size = store.size();

	go(0, 0);

	cout << result << '\n';
}