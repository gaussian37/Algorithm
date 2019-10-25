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

	scanf("%d", &N);
	vii dist(N + 2, vi(N + 2));
	vii use(N + 2, vi(N + 2, 1));

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			scanf("%d", &dist[i][j]);
		}
	}

	for (int k = 1; k <= N; ++k) {
		for (int i = 1; i <= N; ++i) {			
			for (int j = 1; j <= N; ++j) {
				if (i == k || i == j || k == j) continue;
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					printf("-1\n");
					return 0;
				}

				if (dist[i][j] == dist[i][k] + dist[k][j]) {
					use[i][j] = 0;
				}
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (use[i][j]) {
				ans += dist[i][j];
			}
		}
	}
	ans /= 2;

	printf("%d\n", ans);
}