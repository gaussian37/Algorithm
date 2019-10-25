#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> vi;
const int MAX = 100010;
vi A[MAX];
vi parent, visited, depth, dist;

int main() {
	int N;
	scanf("%d", &N);
	parent = visited = depth = dist = vi(N + 2);
	for (int i = 0; i < N - 1; i++) {
		int u, v, w;
		scanf("%d %d", &u, &v);
		A[u].push_back(v);
		A[v].push_back(u);
	}

	depth[1] = 0;
	visited[1] = true;
	queue<int> q;
	q.push(1);
	parent[1] = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int y : A[x]) {
			if (!visited[y]) {
				depth[y] = depth[x] + 1;
				visited[y] = true;
				parent[y] = x;
				q.push(y);
			}
		}
	}

	for (int i = 2; i <= N; i++) {
		printf("%d\n", parent[i]);
	}
	return 0;
}