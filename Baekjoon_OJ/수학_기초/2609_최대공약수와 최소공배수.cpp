#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b){
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
	int a, b;
	cin >> a >> b;
	int a_ = max(a, b);
	int b_ = min(a, b);
	cout << gcd(a, b) << endl;
	cout << lcm(a, b) << endl;
}