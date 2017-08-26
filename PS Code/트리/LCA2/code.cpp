#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pi;

const int MAX = 100111;
vi A[MAX];
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
	for (int to : A[v]) {
		if (to != parent) {
			dfs(to, v);
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
	for (int i = 0; i<N - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		A[u].push_back(v);
		A[v].push_back(u);
	}
	for (l = 1; (1 << l) <= N; l++);
	l -= 1;
	dfs(1, 1);

	int M;
	scanf("%d", &M);
	while (M--) {
		int u, v;
		scanf("%d %d", &u, &v);
		printf("%d\n", lca(u, v));
	}
	return 0;
}