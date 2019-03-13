/*
반복문이 왜 이렇게 이루어져 있는지를 생각해보기!
세 반복문의 순서를 뒤바꾼다면 어떻게 될까?
*/
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;

int N, M;
int result = 0;
bool make[361];
vector<int> know;

void solve(int n, int sum) {
}

int main() {
	cin >> N >> M;
	int angle;
	for (int i = 0; i < N; i++) {
		cin >> angle;
		know.push_back(angle);
	}
	memset(make, 0, sizeof(make));
	make[0] = 1;

	

	for (int n = 0; n < N; n++) {
		for (int i = 0; i < 360; i++) {
			for (int a = 0; a < 360; a++) {
				if (make[a]) {
					int new_angle1 = (a + know[n]) % 360;
					int new_angle2 = (a - know[n] + 360) % 360;
					make[new_angle1] = true;
					make[new_angle2] = true;
				}
			}
		}
	}

	for (int i = 0; i < M; i++) {
		cin >> angle;
		if (make[angle])
			cout << "YES\n";
		else
			cout << "NO\n";
	}

}