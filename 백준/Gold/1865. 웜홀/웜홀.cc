#include <iostream>
#include <string>
#include <vector>

#define INF 21700000

using namespace std;

struct edge {
	int s, e, t;
};

int main() {

	int TC;
	cin >> TC;

	for (int T = 0; T < TC; T++) {
		int N, M, W;

		int s, e, t;
		cin >> N >> M >> W;

		vector<edge>Edge;
		
		for (int i = 0; i < M; i++) {
			cin >> s >> e >> t;
			Edge.push_back({ s,e,t });
			Edge.push_back({ e,s,t });
		}

		for (int i = 0; i < W; i++) {
			cin >> s >> e >> t;
			Edge.push_back({ s,e,-t });
		}

		vector<int>dist(N + 1, INF);
		dist[1] = 0;

		for (int i = 1; i < N; i++) {
			for (int j = 0; j < Edge.size(); j++) {
				s = Edge[j].s;
				e = Edge[j].e;
				t = Edge[j].t;

				if (dist[e] > dist[s] + t) {
					dist[e] = dist[s] + t;
				}
			}
		}

		int flag = 1;
		for (int j = 0; j < Edge.size(); j++) {
			s = Edge[j].s;
			e = Edge[j].e;
			t = Edge[j].t;
			if (dist[e] > dist[s] + t) {
				cout << "YES\n";
				flag = 0;
				break;
			}
		}

		if (flag) {
			cout << "NO\n";
		}

	}

	return 0;
}