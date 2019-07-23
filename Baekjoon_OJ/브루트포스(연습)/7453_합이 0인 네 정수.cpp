#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arrA[4000], arrB[4000], arrC[4000], arrD[4000];
vector<int> vecAB, vecCD;

long long get_same(long long index, vector<int>& vec) {
	long long same = 1;

	for (int i = index + 1; i < vec.size(); i++) {
		if (vec[index] == vec[i])	same++;
		else 
			break;
	}
	return same;
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arrA[i] >> arrB[i] >> arrC[i] >> arrD[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			vecAB.push_back(arrA[i] + arrB[j]);
			vecCD.push_back(arrC[i] + arrD[j]);
		}
	}
	sort(vecAB.begin(), vecAB.end());
	sort(vecCD.begin(), vecCD.end());
	reverse(vecCD.begin(), vecCD.end());
	long long left_AB = 0;
	long long left_CD = 0;
	long long ans = 0;
	long long sum;
	while (left_AB < vecAB.size() && left_CD < vecCD.size()) {
		sum = vecAB[left_AB] + vecCD[left_CD];
		if (sum == 0) {
			long long same_AB = get_same(left_AB, vecAB);
			long long same_CD = get_same(left_CD, vecCD);
			ans += same_AB * same_CD;
			left_AB += same_AB;
			left_CD += same_CD;
		}
		else if (sum > 0) {
			left_CD++;
		}
		else if (sum < 0) {
			left_AB++;
		}
	
	}
	cout << ans;
}