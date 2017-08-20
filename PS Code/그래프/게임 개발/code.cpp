#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;
typedef vector<int> vi;

int N;
vi AdjList[510];
vi ind, work, cost;

int main() {
	scanf("%d", &N);
	work = ind = cost =  vi(N + 2);

	for (int i = 1; i <= N; ++i) {
		int u, v = i, w;
		scanf("%d", &w);
		work[v] = w;
		while (1) {
			scanf("%d", &u);
			if (u == -1) break;
			AdjList[u].push_back(v);
			ind[v]++;
		}
	}

	queue<int> q;
	for (int i = 1; i <= N; ++i) {
		if (ind[i] == 0) {
			q.push(i);
			cost[i] = work[i];
		}
	}

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int v : AdjList[u]) {
			ind[v] -= 1;
			cost[v] = max(cost[v], cost[u] + work[v]);
			if (ind[v] == 0) {
				q.push(v);
			}
		}
	}

	for (int ans : cost) {
		printf("%d\n", ans);
	}

}