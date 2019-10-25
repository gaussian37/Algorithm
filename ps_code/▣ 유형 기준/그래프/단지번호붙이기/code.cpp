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

int N, start;
bool isCycle;
vi A, visited, team;

void dfs(int here) {
	cout <<"!! "<< here << endl;
	visited[here] = true;
	
	int there = A[here];
	if (!visited[there]) {
		if (there == start) {
			cout << here << " " << there << endl;
			isCycle = true;
			return;
		}
		dfs(there);
	}
	
	if (isCycle) {
		team[here] = true;
	}
}


int main() {

	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		A = team = visited = vi(N+1);
		for (int i = 1; i <= N; ++i) {
			scanf("%d", &A[i]);
		}

		for (int i = 1; i <= N; ++i) {
			isCycle = false;
			start = i;
			if(!visited[i])dfs(i);
		}

		int ans = 0;
		for (int i = 1; i <= N; ++i) {
			if (team[i] == 0) ans++;
		}
		printf("%d\n", ans);
	}
	
}