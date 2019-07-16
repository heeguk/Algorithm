#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int L, C;
vector<char> vec;

bool check(string s) {
	int ja, mo;
	ja = mo = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
			mo++;
		else
			ja++;
	}
	return (mo >= 1 && ja >= 2);
}

void go(int cnt, int index, string s) {
	if (cnt >= L) {
		if (check(s))
			cout << s << '\n';
		return;
	}

	if (index >= C)
		return;
	
	
	go(cnt + 1, index + 1, s + vec[index]);
	go(cnt, index + 1, s);

}

int main() {
	
	cin >> L >> C;
	
	for (int i = 0; i < C; i++) {
		char in;
		cin >> in;
		vec.push_back(in);
	}
	sort(vec.begin(), vec.end());
	go(0, 0, "");
}