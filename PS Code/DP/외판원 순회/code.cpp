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

int solve(int s, int i) {
	if (s == (1 << 0) && i == 0) return 0;
	
	if (dp[s][i] != -1) return dp[i][i];

	dp[s][i] = 1e9;
	for (int j = 0; j < N; ++j) {
		if (i != j && (s&(1 << i)) && (s&(1 << j)) && w[j][i]) {
			dp[s][i] = min(dp[s][i], dp[s - (1 << i)][j] + w[j][i]);
		}
	}
	return dp[s][i];
}
int main() {

	scanf("%d", &N);
	w = vii(N + 5, vi(N + 5));
	dp = vii(1<<20, vi(20, 1e9));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			scanf("%d", &w[i][j]);

		}
	}

#if 1
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

#else


#endif
	int ans = 1e9;
	for (int i = 0; i < N; ++i) {
		ans = min(ans, dp[(1 << N) - 1][i] + w[i][0]);
	}
	printf("%d\n", ans);

}