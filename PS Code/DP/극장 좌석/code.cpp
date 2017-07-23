#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int>> vii;
typedef pair<int, int> ii;

int N, M;
vl dp;
vi A;

ll solve(int i){
	if (i == 0) return 1;
	if (i == 1) return 1;

	if (dp[i] != -1) return dp[i];
	dp[i] = 0;
	return dp[i] += solve(i - 1) + solve(i - 2);
}

int main() {
	scanf("%d%d", &N, &M);
	dp = vl(N + 2, -1);
	
	A.push_back(0);
	for (int i = 0; i < M; ++i) {
		int temp;
		scanf("%d", &temp);
		A.push_back(temp);
	}
	A.push_back(N + 1);
	
	ll ans = 1;
	for (int i = 1; i < A.size(); ++i) {
		ans *= solve(A[i] - A[i - 1] - 1);
	}

	printf("%lld\n", ans);

}
