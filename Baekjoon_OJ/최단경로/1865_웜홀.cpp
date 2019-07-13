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
	int tc;
	cin >> tc;

	for (int t = 0; t < tc; t++) {
		vector <edge> Edge;
		int N, M, W;
		cin >> N >> M >> W;
		
		for (int i = 0; i <= N; i++) {
			time[i] = INF;
		}

		int S, E, T;
		for (int i = 0; i < M; i++) {
			cin >> S >> E >> T;
			Edge.push_back(edge(S, E, T));
			Edge.push_back(edge(E, S, T));
		}

		for (int i = 0; i < W; i++) {
			cin >> S >> E >> T;
			Edge.push_back(edge(S, E, -T));
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
					if (i == N){
						negative = 1;
					}
				}
			}
		}
		if (negative)
			printf("YES\n");
		else
			printf("NO\n");
	}

}