#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

typedef vector<int> vi;

struct Edge {
	int from, to, cost;
	Edge(int __to, int __cost) : to(__to), cost(__cost) {};
};

const int INF = 1e9;
vi dist, ck, cnt;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		vector<Edge> A[510];
		int N, M, W;
		scanf("%d%d%d", &N, &M, &W);
		dist = vi(N + 2, INF);
		cnt = ck = vi(N + 2);

		for (int i = 0; i< M; i++) {
			int from, to, cost;
			scanf("%d%d%d", &from, &to, &cost);
			A[from].push_back(Edge(to, cost));
			A[to].push_back(Edge(from, cost));
		}

		for (int i = 0; i< W; i++) {
			int from, to, cost;
			scanf("%d%d%d", &from, &to, &cost);
			A[from].push_back(Edge(to, -cost));
		}

		dist[1] = 0;
		queue<int> q;
		q.push(1);
		ck[1] = true;

		bool negative_cycle = false;
		while (!q.empty()) {
			int from = q.front();
			ck[from] = false;
			q.pop();

			for (int i = 0; i < A[from].size(); ++i) {
				Edge e = A[from][i];
				int to = e.to;
				int cost = e.cost;
				if (dist[to] > dist[from] + cost) {
					dist[to] = dist[from] + cost;
					if (ck[to] == false) {
						q.push(to);
						ck[to] = true;
						cnt[to]++;
						if (cnt[to] >= N) {
							printf("YES\n");
							negative_cycle = true;
							break;
						}
					}
				}
			}
			if (negative_cycle) break;
		}
		if (!negative_cycle) printf("NO\n");
		
	}
	
	return 0;
}