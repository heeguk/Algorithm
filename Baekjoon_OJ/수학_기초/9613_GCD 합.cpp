#include <iostream>
#include <algorithm>
using namespace std;

long long int gcd(int a, int b){
	if (b == 0)
		return a;
	else
		return gcd(b, a%b);
}

int main() {
	int tc;
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		int n;
		cin >> n;
		long long int sum = 0;
		int arr[101];
		for (int j = 0; j < n; j++) {
			cin >> arr[j];
		}
		for (int j = 0; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				sum += gcd(max(arr[j], arr[k]), min(arr[j], arr[k]));
			}
		}
		cout << sum << endl;
	}
	
}