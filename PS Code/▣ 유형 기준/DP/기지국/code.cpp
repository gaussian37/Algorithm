#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef pair<int, int> ii;

#define x first
#define y second

int N;
vector<ii> A;
vi dp;

int solve(int i) {
	if (i == 0) return 0;

	if (dp[i] != -1) return dp[i];

	dp[i] = 1e9;
	int width = 0, height = 0;
	for (int j = i; j >= 1; --j) {
		width = A[i].x - A[j].x;
		height = max(height, A[j].y);
		dp[i] = min(dp[i], solve(j - 1) + max(width, 2 * height));
	}
	return dp[i];
}


int main() {
	scanf("%d", &N);
	A = vector<ii>(N + 2);
	dp = vi(N + 2, -1);
	for (int i = 1; i <= N; ++i) {
		scanf("%d%d", &A[i].x, &A[i].y);
		A[i].y = abs(A[i].y);
	}

	sort(A.begin() + 1, A.begin() + 1 + N);

	printf("%d\n", solve(N));

}