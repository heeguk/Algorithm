#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a%b);
}

int lcm(int a, int b) {
	int gcd_ = gcd(a, b);
	return a * b / gcd_;
}

int main() {
	int tc;
	int a, b;
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		cin >> a >> b;
		cout << lcm(max(a, b), min(a, b)) << endl;
	}

}