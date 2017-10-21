

#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef pair<int, int> ii;

int main() {


	int N, K;
	scanf("%d%d", &N, &K);

#if 0
	vi A(N + 5);
	vii dp(N + 5, vi(K + 5));
	for (int i = 1; i <= N; ++i) {
		scanf("%d", &A[i]);
	}

	dp[0][0] = 1;
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j <= K; ++j) {
			dp[i][j] = dp[i - 1][j];
			if (j - A[i] >= 0) {
				dp[i][j] += dp[i][j - A[i]];
			}
		}
	}
	
	printf("%d\n", dp[N][K]);

#else

	vi A(N + 5);
	vi dp(K + 5);
	for (int i = 1; i <= N; ++i) {
		scanf("%d", &A[i]);
	}

	dp[0] = 1;
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j <= K; ++j) {
			if (j - A[i] >= 0) {
				dp[j] += dp[j - A[i]];
			}
		}
	}

	printf("%d\n", dp[K]);

#endif

}

	
