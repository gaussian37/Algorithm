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
vl A;
vll dp;
//dp[i][j] = i번째 수 까지 사용해서 j를 만드는 방법
ll solve(int i, int j) {
	if (i == 1) {
		if (j == A[1]) return 1;
		else return 0;
	}

	if (dp[i][j] != -1) return dp[i][j];
	dp[i][j] = 0;
	if (j - A[i] >= 0) dp[i][j] += solve(i - 1, j - A[i]);
	if (j + A[i] <= 20) dp[i][j] += solve(i - 1, j + A[i]);
	return dp[i][j];
}

int main() {

	scanf("%d", &N);
	N -= 1;
	A = vl(N+5);
	for (int i = 1; i <= N; ++i) {
		scanf("%lld", &A[i]);
	}

	scanf("%lld", &M);
	dp = vll(N+5, vl(22, -1));

	printf("%lld\n", solve(N, M));

	return 0;
}