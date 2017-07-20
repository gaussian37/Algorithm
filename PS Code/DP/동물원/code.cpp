#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef pair<int, int> ii;

int N;
vii dp;

int solve(int i, int j) {
	if (i == 0) {
		if (j == 0) return 1;
		else return 0;
	}

	if (dp[i][j] != -1) return dp[i][j];
	
	dp[i][j] = 0;
	if (j == 0) dp[i][j] += solve(i - 1, 0) + solve(i - 1, 1) + solve(i - 1, 2);
	if (j == 1) dp[i][j] += solve(i - 1, 0) + solve(i - 1, 2);
	if (j == 2) dp[i][j] += solve(i - 1, 0) + solve(i - 1, 1);
	
	dp[i][j] %= 9901;

	return dp[i][j];
	
}
int main() {
	scanf("%d", &N);
	dp = vii(N + 2, vi(3, -1));

	printf("%d\n", (solve(N, 0) + solve(N, 1) + solve(N, 2)) % 9901);
}
