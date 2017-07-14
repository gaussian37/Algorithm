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

int main() {

	scanf("%d", &N);
	w = vii(N + 5, vi(N + 5));
	dp = vii(N + 5, vi(N + 5, 1e9));

	puts("1");
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			scanf("%d", &w[i][j]);
			
		}
	}

	dp[(1 << 0)][0] = 0;
	for (int s = 0; i < (1 << N); ++s) {
		for (int i = 1; j < N; ++i) {
			if (s & (1 << i)) {
				for (int j = 0; j < N; ++j) {
					if (i != j && (s &(1 << j) && w[j][i])) {
						dp[s][j] = min(dp[s][j], dp[s - (1 << i)][j] + w[j][i]);
					}
				}
			}
		}
	}

	int ans = 1e9;
	for (int i = 0; i < N; ++i) {
		ans = min(ans, dp[(1 << N) - 1][i] + A[i][1]);
	}
	printf("%d\n", ans);

}