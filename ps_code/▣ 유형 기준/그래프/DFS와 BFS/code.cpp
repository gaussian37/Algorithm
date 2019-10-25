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
	printf("%d ", x);

	for (int i = 0; i < AdjList[x].size(); ++i) {
		int y = AdjList[x][i];
		if(!visited[y]) {
			dfs(y);
		}
	}
}

int main() {
	scanf("%d%d%d", &N, &M, &V);
	int u, v;
	for (int i = 0; i < M; ++i) {
		scanf("%d%d", &u, &v);
		AdjList[u].push_back(v);
		AdjList[v].push_back(u);
	}

	for (int i = 0; i <= N; ++i) {
		sort(AdjList[i].begin(), AdjList[i].end());
	}

	visited = vi(N + 10);
	dfs(V);
	puts("");

	visited = vi(N + 10);
	queue<int> q;
	visited[V] = true; //방문하기 전 체크
	q.push(V);
	while (!q.empty()) {
		int x = q.front(); // 탐색 노드 확인
		q.pop(); //확인 후 pop
		printf("%d ", x);
		// 다음 노드 확인
		for (int i = 0; i < AdjList[x].size(); ++i) {
			int y = AdjList[x][i];
			if (!visited[y]) {
				visited[y] = true;
				q.push(y);
			}
		}
	}
}