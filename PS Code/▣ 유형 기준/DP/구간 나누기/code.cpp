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
vi A, psum;
vii dp, visited;
int solve(int i, int j) {
	if (j == 0) {
		return 0;
	}
	if (i <= 0) {
		return -1e9;
	}
	if (visited[i][j]) return dp[i][j];
	visited[i][j] = 1;

	dp[i][j] = solve(i - 1, j);
	for (int k = 1; k <= i; ++k) {
		dp[i][j] = max(dp[i][j], solve(k - 2, j - 1) + psum[i] - psum[k - 1]);
	}
	return dp[i][j];
}
int main() {

	scanf("%d %d", &N, &M);
	A = psum = vi(N + 2);
	visited = dp = vii(N + 5, vi(M + 5));
	for (int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
	}

	psum[1] = A[1];
	for (int i = 2; i <= N; ++i) {
		psum[i] = psum[i - 1] + A[i];
	}
	printf("%d\n", solve(N, M));
	return 0;
}