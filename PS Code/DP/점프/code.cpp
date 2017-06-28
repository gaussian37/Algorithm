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

vii A;
vll dp;

int main() {

	int N;
	scanf("%d", &N);
	A = vii(N + 5, vi(N + 5));
	dp = vll (N + 5, vl(N + 5));

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			scanf("%d", &A[i][j]);
		}
	}

#if 0

	dp[1][1] = 1;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			

			for (int k = 1; k < j; ++k) {
				if (k + A[i][k] == j) {
					dp[i][j] += dp[i][k];
				}
			}

			for (int k = 1; k < i; ++k) {
				if (k + A[k][j] == i) {
					dp[i][j] += dp[k][j];
				}
			}
		}
	}

#else

	dp[1][1] = 1;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (A[i][j] == 0) continue;
			if(j + A[i][j] <= N) 
				dp[i][j + A[i][j]] += dp[i][j];
			if(i + A[i][j] <= N) 
				dp[i + A[i][j]][j] += dp[i][j];
		}
	}

#endif
	
	printf("%lld\n", dp[N][N]);
	
}

