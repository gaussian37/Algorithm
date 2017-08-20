#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int, int> pi;
typedef pair<int, pi> pii;
#define Y first
#define X second

bool a[101][101];
bool visited[101][101];
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };

int main() {
	int n, m;
	scanf("%d%d", &m, &n);
	for (int i = 0; i<n; ++i)
		for (int j = 0; j<m; ++j)
			scanf("%1d", &a[i][j]);

	priority_queue<pii> pq;
	pq.push(pii(0, pi(0, 0)));
	visited[0][0] = 1;

	while (!pq.empty()) {
		int k = -pq.top().first;
		int y = pq.top().second.Y;
		int x = pq.top().second.X;
		pq.pop();

		if (y == n - 1 && x == m - 1) return printf("%d\n", k), 0;
		for (int i = 0; i<4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny<0 || nx<0 || ny >= n || nx >= m || visited[ny][nx]) continue;
			pq.push(pii(-(k + (a[ny][nx])), pi(ny, nx)));
			visited[ny][nx] = 1;
		}
	}
}
