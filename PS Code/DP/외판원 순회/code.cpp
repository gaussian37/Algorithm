#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef pair<int, int> ii;

int N;
vii w, dp;

int solve(int i, int j) {
	if (i == (1 << 0) && j == 0) return 0;

	if (dp[i][j] != -1) return dp[i][j];

	dp[i][j] = 1e9;
	for (int k = 0; k < N; ++k) {
		if (j != k && (i & (1 << j)) && (i & (1 << k)) && w[k][j]) {
			dp[i][j] = min(dp[i][j], solve(i&~(1 << j), k) + w[k][j]);
		}
	}
	return dp[i][j];
}
int main() {

	scanf("%d", &N);
	w = vii(N + 5, vi(N + 5));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			scanf("%d", &w[i][j]);
		}
	}

#if 0

	dp = vii((1 <<20), vi((20), 1e9));
	dp[(1 << 0)][0] = 0;
	for (int i = 0; i < (1 << N); ++i) {
		for (int j = 1; j < N; ++j) {
			for (int k = 0; k < N; ++k) {
				if (j != k && (i & (1 << j)) && (i &(1 << k) && w[k][j])) {
					dp[i][j] = min(dp[i][j], dp[i & ~(1 << j)][k] + w[k][j]);
				}
			}
		}
	}

	int ans = 1e9;
	for (int i = 0; i < N; ++i) {
		ans = min(ans, dp[(1 << N) - 1][i] + w[i][0]);
	}

#else
	dp = vii((1<<(N+2)), vi((N+2), -1));
	int ans = 1e9;
	for (int i = 0; i < N; ++i) {
		ans = min(ans, solve((1 << N) - 1, i) + w[i][0]);
	}

#endif
	
	printf("%d\n", ans);

}