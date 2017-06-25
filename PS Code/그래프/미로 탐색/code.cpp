#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef pair<int, int> ii;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };
vii A, dist, visited;

int main() {
	int N, M;
	scanf("%d%d", &N, &M);

	A = vii(N + 5, vi(M + 5, -1));
	dist = visited = vii(N + 5, vi(M + 5));

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			scanf("%1d", &A[i][j]);
		}
	}

	queue<ii> q;
	q.push(ii(1, 1));
	dist[1][1] = 1;
	visited[1][1] = true;

	while (!q.empty()) {
		ii here = q.front();
		q.pop();

		int y = here.first;
		int x = here.second;

		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (!visited[ny][nx] && A[ny][nx] == 1) {
					visited[ny][nx] = true;
					q.push(ii(ny, nx));
					dist[ny][nx] = dist[y][x] + 1;
				}
			}
		}
	}

	printf("%d\n", dist[N][M]);

}