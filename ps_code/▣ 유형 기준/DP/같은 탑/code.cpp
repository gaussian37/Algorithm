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
vi A;
vii dp;
const int inf = 1e9;

//dp[i][j] = i개의 블럭을 이용하였을 때 두 탑의 차이가 j인 경우 최대 높이
int solve(int i, int j) {
	if (j > 250000) {
		return -inf;
	}
	if (i == 0) {
		if (j == 0) return 0;
		else return -inf;
	}

	if (dp[i][j] != -1) return dp[i][j];
	
	dp[i][j] = solve(i - 1, j);
	dp[i][j] = max(dp[i][j], solve(i - 1, j + A[i]));
	if (A[i] > j) {
		dp[i][j] = max(dp[i][j], solve(i - 1, A[i] - j) + j);
	}
	else {
		dp[i][j] = max(dp[i][j], solve(i - 1, j - A[i]) + A[i]);
	}
	
	return dp[i][j];

}

int main() {
	
	scanf("%d", &N);

	A = vi(N + 5);
	dp = vii(N + 5, vi(250010, -1));

	for (int i = 1; i <= N; ++i) {
		scanf("%d", &A[i]);
	}
	
	int ans = solve(N, 0);
	if (ans == 0) {
		printf("-1");
	}
	else {
		
		printf("%d\n", ans);
	}

	return 0;
}