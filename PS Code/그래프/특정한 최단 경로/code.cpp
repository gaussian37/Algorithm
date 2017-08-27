#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pi;

vector<pi> AdjList[810];
int INF = 1e8;
int N;

vector<int> dijkstra(int start) {
	vi dist = vi(N + 2, INF), visited = vi(N + 2);
	priority_queue<pi, vector<pi>, greater<pi>> pq;
	dist[start] = 0;
	pq.push(pi(0, start));

	while (!pq.empty()) {
		pi here = pq.top();
		pq.pop();

		int u = here.second;
		if (visited[u]) continue;
		visited[u] = true;

		for (pi next : AdjList[u]) {
			int v = next.first;
			int w = next.second;

			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				pq.push(pi(dist[v], v));
			}
		}
	}
	return dist;
}

int main() {
	scanf("%d", &N);
	
	int M;
	scanf("%d", &M);
	for (int i = 0; i<M; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		AdjList[x].push_back(pi(y, z));
		AdjList[y].push_back(pi(x, z));
	}

	int v1, v2;
	scanf("%d %d", &v1, &v2);
	vector<int> dstart = dijkstra(1);
	vector<int> d1 = dijkstra(v1);
	vector<int> d2 = dijkstra(v2);

	int ans = dstart[v1] + d1[v2] + d2[N];
	int ans2 = dstart[v2] + d2[v1] + d1[N];
	if (ans > ans2) {
		ans = ans2;
	}
	if (ans >= INF) {
		ans = -1;
	}
	printf("%d\n", ans);
	return 0;
}