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
vi AdjList[1010];
void dfs(int x){
	visited[x] = true;

	for (int i = 0; i < AdjList[x].size(); ++i) {
		int y = AdjList[x][i];
		if(!visited[y]) {
			dfs(y);
		}
	}
}

int main() {
	scanf("%d%d", &N, &M);
	int u, v;
	for (int i = 0; i < M; ++i) {
		scanf("%d%d", &u, &v);
		AdjList[u].push_back(v);
		AdjList[v].push_back(u);
	}

	visited = vi(N + 10);
	int components = 0;
	for (int i = 1; i <= N; ++i) {
		if (!visited[i]) {
			dfs(i);
			components++;
		}
	}
	printf("%d\n", components);

	
}