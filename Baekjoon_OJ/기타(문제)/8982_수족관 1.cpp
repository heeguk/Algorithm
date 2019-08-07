#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class node {
public:
	int y1;
	int x1;
	int y2;
	int x2;

	int top;
	int bottom;

	node(int a, int b, int c, int d, int e) {
		x1 = a, y1 = b, x2 = c, y2 = d, top = 0, bottom = e;
	}

	int get_volume() {
		return (x2 - x1) * (bottom - top);
	}
};

int N, M;
vector<node> vec;
int hole[2500];

int main() {
	cin >> N;
	int x, y;
	cin >> x >> y;	// 항상 (0, 0)으로 고정됨
	for (int i = 0; i < (N - 2) / 2; i++) {
		int y1, y2, x1, x2;
		cin >> x1 >> y1;
		cin >> x2 >> y2;
		vec.push_back(node(x1, y1, x2, y2, y1));
	}
	cin >> x >> y; // 항상 (A, 0)으로 고정됨

	cin >> M;
	for (int i = 0; i < M; i++) {
		int y1, y2, x1, x2;
		cin >> x1 >> y1 >> x2 >> y2;
		// 구멍의 위치를 찾는다
		for (int j = 0; j < vec.size(); j++) {
			bool ok = vec[j].x1 == x1 && vec[j].y1 == y1 && vec[j].x2 == x2 && vec[j].y2 == y2;
			if (ok) {
				hole[i] = j;
				break;
			}
		}
	}

	for (int i = 0; i < M; i++) {
		int index = hole[i];
		vec[index].top = vec[index].bottom;

		int before = index;
		int j = index;
		while (--j >= 0) {
			if (vec[before].bottom < vec[j].bottom && vec[before].top >= vec[j].top) {
				vec[j].top = vec[before].top;
			}
			else if(vec[before].bottom > vec[j].bottom) {
				if (vec[j].bottom < vec[before].top)
					vec[j].top = vec[j].bottom;
				else
					vec[j].top = vec[before].top;
			}
			before = j;
		}
		before = index;
		j = index;

		while (++j < vec.size()) {
			if (vec[before].bottom < vec[j].bottom && vec[before].top > vec[j].top) {
				vec[j].top = vec[before].top;
			}
			else if (vec[before].bottom > vec[j].bottom) {
				if (vec[j].bottom < vec[before].top)
					vec[j].top = vec[j].bottom;
				else
					vec[j].top = vec[before].top;
			}

			before = j;
		}
		/*
		for (int m = 0; m < vec.size(); m++) {
			cout << m << " 번째 바닥" << endl;
			cout << "천장: " << vec[m].top << " 바닥: " << vec[m].bottom << endl;
		}
		*/
	}
	int ans = 0;
	for (int i = 0; i < vec.size(); i++) {
		auto out = vec[i];
		ans += out.get_volume();
	}
	cout << ans;
}