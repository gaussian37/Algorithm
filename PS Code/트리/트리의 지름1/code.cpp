#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pi;

vector<pi> A[100010];
vi visited, dist;

int N;
void bfs(int start) {	
	dist = visited = vi(N + 2);
	queue<int> q;
	visited[start] = true;
	q.push(start);

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (pi e : A[x]) {			
			int y = e.first;
			int cost = e.second;
			if (visited[y] == false) {
				dist[y] = dist[x] + cost;
				q.push(y);
				visited[y] = true;
			}
		}
	}
}

int main() {	
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int x;
		scanf("%d", &x);
		while (true) {
			int y, z;
			scanf("%d", &y);
			if (y == -1) break;
			scanf("%d", &z);
			A[x].push_back(pi(y, z));
			A[y].push_back(pi(x, z));
		}
	}

	bfs(1);
	int start = 1;
	for (int i = 2; i <= N; i++) {
		if (dist[i] > dist[start]) {
			start = i;
		}
	}

	bfs(start);
	int ans = dist[1];
	for (int i = 2; i <= N; i++) {
		if (ans < dist[i]) {
			ans = dist[i];
		}
	}

	printf("%d\n", ans);
	return 0;
}