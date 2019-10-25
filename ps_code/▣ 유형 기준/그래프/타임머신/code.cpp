#include <cstdio>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pi;

struct Edge {
	int from, to, cost;
};

vi dist;
int INF = 1e9;

int main() {
	int t;
	int N, M;
	scanf("%d %d", &N, &M);
	vector<Edge> A(M);
	dist = vi(N + 2, INF);

	for (int i = 0; i<M; i++) {
		scanf("%d %d %d", &A[i].from, &A[i].to, &A[i].cost);
	}

	dist[1] = 0;
	bool negative_cycle = false;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			int u = A[j].from;
			int v = A[j].to;
			int w = A[j].cost;
			if (dist[u] != INF && dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				if (i == N) {
					negative_cycle = true;
				}
			}
		}
	}

	if (negative_cycle) {
		printf("-1\n");
	}
	else {
		for (int i = 2; i <= N; i++) {
			if (dist[i] == INF) dist[i] = -1;
			printf("%d\n", dist[i]);
		}
	}
	return 0;
}