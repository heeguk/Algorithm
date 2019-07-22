#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int N, K;
int learned = 0;
int words[50];
int a_ = 'a' - 'a';
int c_ = 'c' - 'a';
int t_ = 't' - 'a';
int n_ = 'n' - 'a';
int i_ = 'i' - 'a';
int start_bit = 0 | (1 << a_) | (1 << c_) | (1 << t_) | (1 << n_) | (1 << i_);
int ans = 0;

void solve(int index, int bit,  int learned) {

	if (learned == K - 5) {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			int compare = ((1 << 26) - 1 - bit);
			int result = words[i] & compare;
			if (result == 0)	cnt++;
		}
		ans = max(ans, cnt);
		return;
	}
	if (index == 26)
		return;

	if (index == a_ || index == c_ || index == t_ || index == n_ || index == i_) { // Alreay learned alphabets
		solve(index + 1, bit, learned);
	}
	else {
		solve(index + 1, bit | (1 << index), learned + 1); // 배우는 경우
		solve(index + 1, bit, learned ); // 안 배우는 경우
	}
	
	
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		words[i] = 0;
		for(char c: temp){
			words[i] = words[i] | (1 << (c - 'a'));
		}
	}
	
	solve(0, start_bit, 0);

	cout << ans;
}