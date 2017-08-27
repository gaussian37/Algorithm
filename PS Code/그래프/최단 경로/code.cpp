#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pi;
int INF = 1e9;

vector<pi> AdjList[20010];
vi dist, visited;

int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	dist = vi(N + 2, INF);
	visited = vi(N + 2);

	int start;
	scanf("%d", &start);
	for (int i = 0; i < M; ++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		AdjList[u].push_back(pi(v, w));
	}

	dist[start] = 0;
	priority_queue<pi, vector<pi>, greater<pi>> pq;
	pq.push(pi(0, start));

	while (!pq.empty()) {
		pi here = pq.top();
		pq.pop();
		int u = here.second;

		if (visited[u]) {
			continue;
		}
		visited[u] = true;

		for (int i = 0; i < AdjList[u].size(); ++i) {
			pi next = AdjList[u][i];
			int v = next.first;
			int w = next.second;

			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				pq.push(pi(dist[v], v));
			}
		}
	}

	for (int i = 1; i <= N; ++i) {
		if (dist[i] >= INF) {
			printf("INF\n");
		}
		else {
			printf("%d\n", dist[i]);
		}
	}

}