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

int N;
int INF = 1e9;

vi W;
vi AdjList[10010];
vii dp;
vi ans;

void solve(int here, int parent) {
	for (int child : AdjList[here]){
		if (parent == child) continue;
		solve(child, here);
	}

	dp[here][0] = 0;
	dp[here][1] = W[here];

	for (int child : AdjList[here]) {
		if (parent == child) continue;
		dp[here][0] += max(dp[child][0], dp[child][1]);
		dp[here][1] += dp[child][0];
	}
}

void tracking(int here, int choose, int parent) {
	if (choose == 0) {
		for (int child : AdjList[here]) {
			if (parent == child) continue;
			if (dp[child][0] < dp[child][1]) {
				tracking(child, 1, here);
			}
			else {
				tracking(child, 0, here);
			}
		}
	}
	else if(choose == 1){
		ans.push_back(here);
		for (int child : AdjList[here]) {
			if (parent == child) continue;
			tracking(child, 0, here);
		}
	}
}

int main() {

	scanf("%d", &N);
	W = vi(N + 2);
	dp = vii(N + 2, vi(2));

	for (int i = 1; i <= N; ++i) {
		scanf("%d", &W[i]);
	}

	for (int i = 0; i < N - 1; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		AdjList[u].push_back(v);
		AdjList[v].push_back(u);
	}
		
	solve(1, 0);	
	printf("%d\n", max(dp[1][0], dp[1][1]));

	if (dp[1][0] < dp[1][1]) {
		tracking(1, 1, 0);
	}
	else {
		tracking(1, 0, 0);
	}

	sort(ans.begin(), ans.end());
	for (int i : ans) {
		printf("%d ", i);
	}
}