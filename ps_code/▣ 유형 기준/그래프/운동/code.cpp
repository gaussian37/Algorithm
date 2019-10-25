#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef pair<int, int> ii;

int N, M;
int INF = 1e9;

int main() {

	scanf("%d%d", &N, &M);
	vii dist(N + 2, vi(N + 2, INF));

	for (int i = 0; i < M; ++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		dist[u][v] = min(dist[u][v], w);
	}

	for (int k = 1; k <= N; ++k) {
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				if (dist[i][k] == INF || dist[k][j] == INF) continue;
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	int ans = INF;
	for (int i = 1; i <= N; ++i) {
		ans = min(ans, dist[i][i]);
	}

	printf("%d\n", ans == INF ? -1 : ans);
	
}