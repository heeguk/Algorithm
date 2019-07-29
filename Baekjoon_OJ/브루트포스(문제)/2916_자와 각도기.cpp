#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

bool angle[360];

vector<int> know;


int main() {
	memset(angle, 0, sizeof(angle));
	int N, K;
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		know.push_back(n);
		angle[n] = 1;
	}

	for (int i = 0; i < 360; i++) {
		for (int a = 0; a < 360; a++) {
			if (!angle[a])	continue;
			for (int b = 0; b < 360; b++) {
				if (!angle[b])	continue;
				angle[abs(a - b)] = 1;
				angle[(a + b) % 360] = 1;
			}
		}
	}

	for (int i = 0; i < K; i++) {
		int n;
		cin >> n;
		if (angle[n])	cout << "YES\n";
		else cout << "NO\n";
	}

}