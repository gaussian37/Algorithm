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
vii A, dp;
const int inf = 1e9;

//dp[i][j] = i번째 행부터 j번째 행 까지 곱했을 때, 곱셈 연산의 최솟값
int solve(int i, int j) {
	
	if (i == j) return 0;
	if (i + 1 == j) return A[i][0] * A[i][1] * A[j][1];

	if (dp[i][j] != -1) return dp[i][j];

	dp[i][j] = inf;
	for (int k = i; k < j; ++k) {
		dp[i][j] = min(dp[i][j], solve(i, k) + solve(k + 1, j) + A[i][0] * A[k][1] * A[j][1]);
	}
	return dp[i][j];

}

int main() {

	scanf("%d", &N);
	A = vii(N + 2, vi(2));
	dp = vii(N + 2, vi(N + 2, -1));

	for (int i = 1; i <= N; ++i) {
		scanf("%d%d", &A[i][0], &A[i][1]);
	}
	
	printf("%d\n", solve(1, N));
	
}