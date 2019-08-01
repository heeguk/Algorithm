#include <iostream>
#include <cstring>
#include <queue>
#include <map>

using namespace std;
map<long long, long long> before;
map<long long, int> how;

void print(long long from, long long to) {
	if (from != to) {
		print(before[from], from);
		if (how[to] == 0) {
			cout << "*";
		}
		else if (how[to] == 1) {
			cout << "+";
		}
		else if (how[to] == 2) {
			cout << "-";
		}
		else if (how[to] == 3) {
			cout << "/";
		}
	}
	
}

int main() {
	queue<long long> q;
	long long s, t;
	cin >> s >> t;
	if (s == t) {
		cout << 0;
		return 0;
	}

	before[s] = s;
	q.push(s);

	while (!q.empty()) {
		long long out = q.front();
		q.pop();

		if (out == t) {
			print(before[out], out);
			return 0;
		}

		long long mul = out * out;
		if (mul <= 1000000000 && before.count(mul) == 0) {
			before[mul] = out;
			how[mul] = 0;
			q.push(mul);
		}
		long long add = out + out;
		if (add <= 1000000000 && before.count(add) == 0) {
			before[add] = out;
			how[add] = 1;
			q.push(add);
		}
		long long sub = 0;
		if (before.count(sub) == 0) {
			before[sub] = out;
			how[sub] = 2;
			q.push(sub);
		}
		long long div = 1;
		if(out != 0 && before.count(div) == 0) {
			before[div] = out;
			how[div] = 3;
			q.push(div);
		}
	}
	cout << -1;
	return 0;
}