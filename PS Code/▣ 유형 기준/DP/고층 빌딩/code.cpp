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

int N, L, R;
vi A;
vector<vll> dp;
ll mod = 1000000007;
ll solve(int n, int l, int r) {
	if (n == 1 && l == 1 && r == 1) return 1LL;
	if (n == 0 || l == 0 || r == 0) return 0;

	if (dp[n][l][r] != -1) return dp[n][l][r];
	
	dp[n][l][r] = 0;
	dp[n][l][r] += solve(n - 1, l - 1, r) + solve(n - 1, l, r - 1) + solve(n - 1, l, r)*(n - 2);
	dp[n][l][r] %= mod;
	
	return dp[n][l][r];
}

int main() {
	
	scanf("%d %d %d", &N, &L, &R);
	dp = vector<vll>(N + 5, vll(L + 5, vl(R + 5, -1)));

	printf("%lld\n", solve(N, L, R));

	//dp[1][1][1] = 1LL;
	//for (int i = 2; i <= N; ++i) {
	//	for (int j = 1; j <= L; ++j) {
	//		for (int k = 1; k <= R; ++k) {
	//			dp[i][j][k] = dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1] 
	//				          + dp[i - 1][j][k] * (i - 2);
	//			dp[i][j][k] %= mod;
	//		}
	//	}
	//}

	return 0;
}