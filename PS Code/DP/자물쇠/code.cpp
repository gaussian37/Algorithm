#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;
typedef pair<int, int> ii;

int N;
vi A, B, turn;
viii dp;

int solve(int i, int j, int k) {
	if (i == N) return 0;
	
	if (dp[i][j][k] != -1) return dp[i][j][k];
	dp[i][j][k] = 1e9;
	
	int origin = (A[i] + j) % 10;
	int to = B[i];
	
	for (int three = 0; three < 10; ++three) {
		for (int two = 0; two < 10; ++two) {
			int from = (origin + two + three) % 10;
			int one = to - from;
			if (one < 0) one += 10;
			int cost = turn[one] + turn[two] + turn[three];
			dp[i][j][k] = min(dp[i][j][k], cost + solve(i + 1, (k + two + three) % 10, three));
		}
	}
	return dp[i][j][k];
}

int main() {
	scanf("%d", &N);
	A = B = vi(N);
	turn = { 0, 1, 1, 1, 2, 2, 2, 1, 1, 1 };
	dp = viii(N + 2, vii(10, vi(10, -1)));
	
	for (int i = 0; i < N; ++i) {
		scanf("%1d", &A[i]);
	}
	for (int i = 0; i < N; ++i) {
		scanf("%1d", &B[i]);
	}
	
	printf("%d\n", solve(0, 0, 0));
}