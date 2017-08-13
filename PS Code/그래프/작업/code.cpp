#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pi;

vi AdjList[10010];
vi ind, work, dist;

int INF = 1e9;

int main() {
	int N;
	scanf("%d", &N);
	work = vi(N + 2);
	ind = vi(N + 2);
	dist = vi(N + 2);

	for (int i = 1; i <= N; ++i) {
		scanf("%d", &work[i]);
		int cnt;
		scanf("%d", &cnt);

		for (int j = 0; j<cnt; ++j) {
			int x;
			scanf("%d", &x);
			AdjList[x].push_back(i);
			ind[i] += 1;
		}
	}

	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (ind[i] == 0) {
			q.push(i);
			dist[i] = work[i];
		}
	}

	for (int k = 0; k < N; ++k) {
		int u = q.front();
		q.pop();
		for (int i = 0; i<AdjList[u].size(); i++) {
			int v = AdjList[u][i];
			ind[v] -= 1;
			if (dist[v] < dist[u] + work[v]) {
				dist[v] = dist[u] + work[v];
			}
			if (ind[v] == 0) {
				q.push(v);
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		if (ans < dist[i]) {
			ans = dist[i];
		}
	}

	printf("%d\n", ans);
	return 0;
}