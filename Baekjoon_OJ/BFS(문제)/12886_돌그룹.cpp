#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

bool check[1501][1501];	// A, B, C는 최대 값이 500이므로, 세 원소가 하나로 합쳐졌을 때 최대 크기가 1500이다.
int A, B, C;
int SUM;

int main() {
	memset(check, 0, sizeof(check));
	cin >> A >> B >> C;
	SUM = A + B + C;
	
	if (SUM % 3 != 0) {	// 3으로 나누어 떨어져야 똑같은 크기로 나눌 수 있다.
		cout << 0;
		return 0;
	}

	queue<pair<int, int>> q;
	q.emplace(A, B);
	check[A][B] = 1;

	while (!q.empty()) {
		auto out = q.front();
		q.pop();
		int a = out.first, b = out.second, c = SUM - out.first - out.second;
		if (a == SUM / 3 && b == SUM / 3) {
			cout << 1;
			return 0;
		}
		if (a != b) {
			if (a < b) {
				int na = a + a;
				int nb = b - a;
				if (check[na][nb] == 0) {
					check[na][nb] = 1;
					q.emplace(na, nb);
				}
			}
			else {
				int na = a - b;
				int nb = b + b;
				if (check[na][nb] == 0) {
					check[na][nb] = 1;
					q.emplace(na, nb);
				}
			}
		}
		if (b != c) {
			if (b < c) {
				int nb = b + b;
				int nc = c - b;
				int na = SUM - nb - nc;
				if (check[na][nb] == 0) {
					check[na][nb] = 1;
					q.emplace(na, nb);
				}
			}
			else {
				int nb = b - c;
				int nc = c + c;
				int na = SUM - nb - nc;
				if (check[na][nb] == 0) {
					check[na][nb] = 1;
					q.emplace(na, nb);
				}
			}
		}
		if (c != a) {
			if (c < a) {
				int na = a - c;
				int nc = c + c;
				int nb = SUM - na - nc;
				if (check[na][nb] == 0) {
					check[na][nb] = 1;
					q.emplace(na, nb);
				}
			}
			else {
				int na = a + a;
				int nc = c - a;
				int nb = SUM - na - nc;
				if (check[na][nb] == 0) {
					check[na][nb] = 1;
					q.emplace(na, nb);
				}
			}
		}
	}
	cout << 0;
}