#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef pair<int, int> ii;


int N, M, V;
vi visited;
vi a;

void dfs(int x) {
	if (visited[x]) return;
	visited[x] = true;
	dfs(a[x]);
}

int main() {

	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		visited = a = vi(N + 10);
		for (int i = 1; i <= N; ++i) {
			scanf("%d", &a[i]);
		}
		
		int cnt = 0;
		for (int i = 1; i <= N; ++i) {
			if (!visited[i]) {
				dfs(i);
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}
	
}