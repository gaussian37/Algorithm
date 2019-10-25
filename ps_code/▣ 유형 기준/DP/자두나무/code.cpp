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

int N, M;
vi A;
vii dp;
int solve(int i, int j) {
	if (i == N+1 && j <= M) return 0;
	if (j > M) return 0;

	if (dp[i][j] != -1) return dp[i][j];

	dp[i][j] = 0;
	int pos = j % 2 + 1;
	dp[i][j] = max(solve(i + 1, j), solve(i + 1, j + 1)) + (pos == A[i] ? 1 : 0);
	return dp[i][j];
}

int main() {
	
	scanf("%d %d", &N, &M);
	A = vi(N + 2);
	dp = vii(N + 5, vi(M + 5, -1));

	for (int i = 1; i <= N; ++i) {
		scanf("%d", &A[i]);
	}

	printf("%d\n", max(solve(1, 0), solve(1, 1)));
	return 0;
}