#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pi;

int N, M;
vector<pi> A[1001];
vi visited;

int main() {

	scanf("%d %d", &N, &M);
	visited = vi(N + 2);

	for (int i = 0; i<M; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		A[u].push_back(pi(v, w));
		A[v].push_back(pi(u, w));
	}

	priority_queue<pi, vector<pi>, greater<pi>> pq;
	
	visited[1] = true;
	for (int i = 0; i < A[1].size(); ++i) {
		int next = A[1][i].first;
		int cost = A[1][i].second;
		pq.push(pi(cost, next));
	}

	int ans = 0;
	while (!pq.empty()) {
		pi p = pq.top();
		int here = p.second;
		int cost = p.first;
		pq.pop();

		if (visited[here]) continue;
		visited[here] = true;

		ans += cost;
		for (int i = 0; i < A[here].size(); ++i) {
			int next = A[here][i].first;
			int next_cost = A[here][i].second;
			pq.push(pi(next_cost, next));
		}
	}

	printf("%d\n", ans);

	return 0;
}