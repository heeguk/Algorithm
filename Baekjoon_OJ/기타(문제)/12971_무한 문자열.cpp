#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

string s, t;

int main() {
	cin >> s >> t;
	
	string S, T;
	S = T = "";
	int m = max(s.size(), t.size()) * 2;
	while (S.size() < m) {
		S += s;
	}
	while (T.size() < m) {
		T += t;
	}
	
	for (int i = 0; i < m; i++) {
		if (S[i] != T[i]) {
			cout << 0;
			return 0;
		}
	}
	cout << 1;
	return 0;
}