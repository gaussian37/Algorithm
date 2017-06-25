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
vi AdjList[20010];
void dfs(int x, int c){
	visited[x] = c;

	for (int i = 0; i < AdjList[x].size(); ++i) {
		int y = AdjList[x][i];
		if(visited[y] == 0) {
			dfs(y, 3-c);
		}
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &N, &M);

		visited = vi(N + 10);
		for (int i = 0; i <= N; ++i) {
			AdjList[i].clear();
		}

		int u, v;
		for (int i = 0; i < M; ++i) {
			scanf("%d%d", &u, &v);
			AdjList[u].push_back(v);
			AdjList[v].push_back(u);
		}
		
		for (int i = 1; i <= N; ++i) {
			if (visited[i] == 0) {
				dfs(i, 1);
			}
		}

		bool ok = true;
		for (int i = 1; i <= N; ++i) {
			for (int j = 0; j < AdjList[i].size(); ++j) {
				if (visited[i] == visited[AdjList[i][j]]) {
					ok = false;
					break;
				}
			}
		}

		printf("%s\n", ok ? "YES" : "NO");
	}
	
}