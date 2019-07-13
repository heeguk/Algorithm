#include <iostream>
#include <cstring>
#include <vector>
#define INF 999999999

using namespace std;

class edge {
public:
	int s;
	int e;
	int t;

	edge(int S, int E, int T) {
		s = S;
		e = E;
		t = T;
	}
};


int time[501];

int main() {

	vector <edge> Edge;
	int N, M;
	cin >> N >> M;

	for (int i = 0; i <= N; i++) {
		time[i] = INF;
	}

	int S, E, T;
	for (int i = 0; i < M; i++) {
		cin >> S >> E >> T;
		Edge.push_back(edge(S, E, T));
	}

	time[1] = 0;
	int negative = 0;
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j < Edge.size(); j++) {
			int start = Edge[j].s;
			int end = Edge[j].e;
			int Time = Edge[j].t;
			if (time[start] != INF && time[end] > time[start] + Time) {
				time[end] = time[start] + Time;
				if (i == N) {
					negative = 1;
				}
			}
		}
	}
	if (negative)
		printf("-1\n");
	else{
		for (int i = 2; i <= N; i++) {
			if (time[i] == INF)
				printf("-1\n");
			else
				printf("%d\n", time[i]);
		}
	}
}