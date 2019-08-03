#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

bool dp[51][51][51][4][4];
string str;
vector<char> ans;
int A, B, C;
void solve(int a, int b, int c, int before, int before2) {
	if (dp[a][b][c][before][before2])	return;
	if (a > A || b > B || c > C)	return;
	if (a == A && b == B && c == C) {
		for (int i = 0; i < ans.size(); i++)	cout << ans[i];
		exit(0);
	}
	dp[a][b][c][before][before2] = 1;
	
	// A 를 추가, 모든 경우에 추가 가능
	ans.push_back('A');
	solve(a + 1, b, c, 1, before);
	ans.pop_back();

	// B 를 추가
	if (before != 2) {
		ans.push_back('B');
		solve(a, b + 1, c, 2, before);
		ans.pop_back();
	}

	// C 를 추가
	if (before != 3 && before2 != 3) {
		ans.push_back('C');
		solve(a, b, c + 1, 3, before);
		ans.pop_back();
	}
	
}

int main() {
	memset(dp, 0, sizeof(dp));
	cin >> str;
	A = B = C = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'A')	A++;
		else if (str[i] == 'B')	B++;
		else if (str[i] == 'C')	C++;
	}
	solve(0, 0, 0, 0, 0);
	cout << -1;
}