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
	vii dp(N + 2, vi(N + 2, INF));

	for (int i = 0; i < M; ++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		dp[u][v] = min(dp[u][v], w);
	}

	for (int i = 1; i <= N; ++i) {
		dp[i][i] = 0;
	}

	for (int k = 1; k <= N; ++k) {
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			printf("%d ", dp[i][j] == INF ? 0 : dp[i][j]);
		}puts("");
	}
	
}