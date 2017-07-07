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

int N, S, M;
vi A;
vii dp;
int solve(int i, int j) {
	if (i == 0 && j == S) return true;
	if (i == 0) return false;
	
	if (dp[i][j] != -1) return dp[i][j];
	dp[i][j] = 0;
	if (j - A[i] >= 0) dp[i][j] += solve(i - 1, j - A[i]);
	if (j + A[i] <= M) dp[i][j] += solve(i - 1, j + A[i]);

	return dp[i][j];
}

int main() {

	scanf("%d%d%d", &N, &S, &M);
	
#if 0
	A = vi(N + 5);
	dp = vii(N + 5, vi(M + 5, -1));
	for (int i = 1; i <= N; ++i) {
		scanf("%d", &A[i]);
	}

	int ans = -1;	
	for (int i = 0; i <= M; ++i) {
		
		if (solve(N, i)) ans = i;
	}
	printf("%d\n", ans);

#else

	A = vi(N + 5);
	dp = vii(N + 5, vi(M + 5));

	for (int i = 1; i <= N; ++i) {
		scanf("%d", &A[i]);
	}
	dp[0][S] = true;
	for (int i = 0; i <= N - 1; i++) {
		for (int j = 0; j <= M; j++) {
			if (dp[i][j] == false) {
				continue;
			}
			if (j - A[i + 1] >= 0) {
				dp[i + 1][j - A[i + 1]] = true;
			}
			if (j + A[i + 1] <= M) {
				dp[i + 1][j + A[i + 1]] = true;
			}
		}
	}
	int ans = -1;
	for (int i = 0; i <= M; i++) {
		if (dp[N][i]) ans = i;
	}
	printf("%d\n", ans);
	return 0;

#endif


	return 0;
}