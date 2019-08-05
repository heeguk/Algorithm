#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int A, B, C;

long long calc(int a, int b) {
	if (b == 0)
		return 1;
	else if (b == 1)
		return a;
	else if (b % 2 == 0) {
		long long temp = calc(a, b / 2) % C;
		long long ret = (temp * temp) % C;
		return ret;
	}
	else{
		//long long ret = (a * calc(a, b - 1)) % C;
		return (a * calc(a, b - 1)) % C;
	}
}

int main() {
	cin >> A >> B >> C;
	A = A % C;
	long long ans = calc(A, B) % C;
	
	cout << ans;
}