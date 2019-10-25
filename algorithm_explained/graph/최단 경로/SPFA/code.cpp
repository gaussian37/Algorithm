#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

typedef vector<int> vi;

struct Edge {
	int from, to, cost;
	Edge(int __to, int __cost) : to(__to), cost(__cost) {};
};

vector<Edge> A[510];
const int INF = 1e9;

vi dist, ck, cnt;

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	dist = vi(N + 2, INF);
	cnt = ck = vi(N + 2);

	for (int i = 0; i<M; i++) {
		int from, to, cost;
		scanf("%d%d%d", &from, &to, &cost);
		A[from].push_back(Edge(to, cost));
	}

	dist[1] = 0;
	queue<int> q;
	q.push(1);
	ck[1] = true;

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
						printf("-1\n");
						return 0;
					}
				}
			}
		}
	}

	for (int i = 2; i <= N; i++) {
		if (dist[i] == INF) {
			printf("-1\n");
		}
		else {
			printf("%d\n", dist[i]);
		}
	}
	return 0;
}