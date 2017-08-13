#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pi;
int INF = 1e9;

vector<pi> AdjList[1010];
vi dist, visited, parent;

int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	dist = vi(N + 2, INF);
	visited = vi(N + 2);
	parent = vi(N + 2, -1);

	for (int i = 0; i < M; ++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		AdjList[u].push_back(pi(v, w));
	}

	int start, end;
	scanf("%d%d", &start, &end);

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
				parent[v] = u;
				pq.push(pi(dist[v], v));
			}
		}
	}

	vi v;
	int x = end;
	while (x != -1) {
		v.push_back(x);
		x = parent[x];
	}

	printf("%d\n", dist[end]);
	printf("%d\n", v.size());
	for (int i = v.size() - 1; i >= 0; --i) {
		printf("%d ", v[i]);
	}
}