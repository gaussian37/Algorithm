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

int N, M, st, dest;
vi visited;
vector<ii> AdjList[10010];

bool dfs(int x, int here) {

	visited[here] = true;
	if (here == dest) return true;

	bool rst = false;
	for (int i = 0; i < AdjList[here].size(); ++i) {
		int there = AdjList[here][i].first;
		int weight = AdjList[here][i].second;

		if (weight >= x && !visited[there]) {
			rst += dfs(x, there);
		}
	}

	return rst;
}

int main() {
	
	scanf("%d%d", &N, &M);
	visited = vi(N + 5);

	for (int i = 0; i < M; ++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		AdjList[u].push_back(ii(v, w));
		AdjList[v].push_back(ii(u, w));
	}

	scanf("%d%d", &st, &dest);

	ll ans = 0;
	ll left = 1, right = 1e9;
	
	while (left <= right) {
		visited = vi(N + 5);
		ll mid = (left + right) / 2;
		if (dfs(mid, st)) {
			ans = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
		
	}

	printf("%lld\n", ans);

}