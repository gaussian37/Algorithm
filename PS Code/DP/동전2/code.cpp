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

	vi A(N + 5), dp(K + 5, 1e9);
	for (int i = 1; i <= N; ++i) {
		scanf("%d", &A[i]);
	}
	
	dp[0] = 0;
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j <= K; ++j) {
			if (j - A[i] >= 0 && dp[j - A[i]] < 1e9) {
				dp[j] = min(dp[j], dp[j - A[i]] + 1);
			}
		}
	}

	printf("%d\n", dp[K] == 1e9 ? -1 : dp[K]);

}
