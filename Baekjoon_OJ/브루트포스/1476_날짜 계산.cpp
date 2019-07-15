#include <iostream>
#include <algorithm>
using namespace std;

// 브루트포스 문제 중 가장 기초
// 모든 경우를 다 테스트

int main() {
	int e, s, m;
	int E, S, M;
	cin >> E >> S >> M;

	e = s = m = 1;

	for (int i = 1; i <= 15 * 28 * 19; i++) {
		if (e == 16)	e = 1;
		if (s == 29)	s = 1;
		if (m == 20)	m = 1;

		if (e == E && s == S && m == M) {
			cout << i << endl;
			break;
		}

		e++;
		s++;
		m++;
	}
}