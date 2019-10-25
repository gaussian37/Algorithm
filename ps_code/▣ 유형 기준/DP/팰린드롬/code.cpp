#include <iostream>
#include <algorithm>
#include <vector>
#include <time.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef pair<int, int> ii;

vi A;
vii dp;

int solve(int i, int j) {
	if (i == j) {
		return 1;
	}
	else if (i + 1 == j) {
		if (A[i] == A[j]) {
			return 1;
		}
		else return 0;
	}
	if (dp[i][j] >= 0) return dp[i][j];
	if (A[i] != A[j]) return dp[i][j] = 0;
	else return dp[i][j] = solve(i + 1, j - 1);

}

int main() {
	int N, M;
	int x, y;
	scanf("%d", &N);

#if 0
	A = vi(N + 5);
	dp = vii(N + 5, vi(N + 5, -1));

	for (int i = 1; i <= N; ++i) {
		scanf("%d", &A[i]);
	}

	scanf("%d", &M);
	for (int i = 0; i < M; ++i) {
		scanf("%d%d", &x, &y);
		printf("%d\n", solve(x, y));
	}

#else
	A = vi(N + 5);
	dp = vii(N + 5, vi(N + 5));

	for (int i = 1; i <= N; ++i) {
		scanf("%d", &A[i]);
	}

	for (int i = 1; i <= N; ++i) {
		dp[i][i] = 1;
	}
	for (int i = 1; i <= N; ++i) {
		if (A[i] == A[i + 1])
			dp[i][i + 1] = 1;
	}

	for (int k = 3; k <= N; ++k) {
		for (int i = 1; i <= N - k + 1; ++i) {
			int j = i + k - 1;
			if (A[i] == A[j] && dp[i+1][j-1]) {
				dp[i][j] = 1;
			}
		}
	}

	scanf("%d", &M);
	for (int i = 0; i < M; ++i) {
		scanf("%d%d", &x, &y);
		printf("%d\n", dp[x][y]);
	}

#endif
}