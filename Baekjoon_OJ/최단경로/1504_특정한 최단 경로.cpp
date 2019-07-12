#include <iostream>
#include <cstring>
#include <vector>
#include<queue>
using namespace std;

vector <pair<int, int>> vertex[801];
priority_queue <pair<int, int>> pq;
int dp[801];

void dik(int start) {

	dp[start] = 0;
	pq.push(make_pair(dp[start], start));

	while (!pq.empty()) {

		int node = pq.top().second;

		pq.pop();

		for (int i = 0; i < vertex[node].size(); i++) {
			int next = vertex[node][i].second;
			int weight = vertex[node][i].first;
			if (dp[next] > dp[node] + weight) {
				dp[next] = dp[node] + weight;
				pq.push(make_pair(-dp[next], next));
			}
		}

	}

}

int main() {

	int v, e;
	cin >> v >> e;

	int v1, v2, w;
	for (int i = 0; i < e; i++) {
		cin >> v1 >> v2 >> w;
		vertex[v1].push_back(make_pair(w, v2));
		vertex[v2].push_back(make_pair(w, v1));
	}

	int A, B;

	cin >> A >> B;

	for (int i = 1; i <= v; i++) {
		dp[i] = 99999999;
	}

	dik(1);

	int _1toA = dp[A];
	int _1toB = dp[B];


	for (int i = 1; i <= v; i++) {
		dp[i] = 99999999;
	}

	dik(A);

	int _AtoB = dp[B];
	int _AtoV = dp[v];


	for (int i = 1; i <= v; i++) {
		dp[i] = 99999999;
	}

	dik(B);

	int _BtoA = dp[A];
	int _BtoV = dp[v];

	int way1 = _1toA + _AtoB + _BtoV;
	int way2 = _1toB + _BtoA + _AtoV;

	if (way1 >= 99999999 && way2 >= 99999999)
		printf("%d\n", -1);
	else if (way1 < way2)
		printf("%d\n", way1);
	else
		printf("%d\n", way2);

	return 0;
}