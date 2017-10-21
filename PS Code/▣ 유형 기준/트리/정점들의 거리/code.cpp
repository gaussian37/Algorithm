#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pi;

const int MAX = 100100;
vector<pi> A[MAX];
vii p;
vi tin, tout;
int timer;
int l;
int N;

void dfs(int v, int parent) {
	tin[v] = ++timer;
	p[v][0] = parent;
	for (int i = 1; i <= l; i++) {
		p[v][i] = p[p[v][i - 1]][i - 1];
	}
	for (pi to : A[v]) {
		if (to.first != parent) {
			dfs(to.first, v);
		}
	}
	tout[v] = ++timer;
}

bool upper(int u, int v) {
	return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

int lca(int u, int v) {
	if (upper(u, v)) return u;
	if (upper(v, u)) return v;
	for (int i = l; i >= 0; i--) {
		if (!upper(p[u][i], v)) {
			u = p[u][i];
		}
	}
	return p[u][0];
}

int main() {
	scanf("%d", &N);
	tin = tout = vi(N + 2);
	p = vii(N + 2, vi(20));
	for (int i = 0; i<N - 1; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		A[u].push_back(pi(v,w));
		A[v].push_back(pi(u,w));
	}

	for (l = 1; (1 << l) <= N; l++);
	l -= 1;
	dfs(1, 1);

	vi visited(N + 2), dist(N + 2);
	queue<int> q;
	q.push(1);
	visited[1] = true;

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (pi e : A[x]) {
			int y = e.first;
			int cost = e.second;
			if (!visited[y]) {
				q.push(y);
				visited[y] = true;
				dist[y] = dist[x] + cost;
			}
		}
	}

	int M;
	scanf("%d", &M);
	while (M--) {
		int u, v;
		scanf("%d%d", &u, &v);
		int node = lca(u, v);
		printf("%d\n", dist[u] + dist[v] - 2 * dist[node]);
	}

	return 0;
}