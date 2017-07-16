#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef pair<int, int> ii;

vii A, visited;

int dx[] = { -1,0, 1, -1, 1, -1, 0, 1 };
int dy[] = { -1,-1,-1, 0, 0, 1, 1, 1};
int w, h, cnt;

void dfs(int y, int x) {
	
	visited[y][x] = true;

	for (int i = 0; i < 8; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (A[ny][nx] > 0 && !visited[ny][nx]) {
			dfs(ny, nx);
		}
	}
}



int main() {
	
	while (1) {
		scanf("%d%d%", &w, &h);
		if (w == 0 && h == 0) break;
		A = vii(h + 5, vi(w + 5, -1));
		visited = vii(h + 5, vi(w + 5));
		cnt = 0;

		for (int i = 1; i <= h; ++i) {
			for (int j = 1; j <= w; ++j) {
				scanf("%d", &A[i][j]);
			}
		}

		for (int i = 1; i <= h; ++i) {
			for (int j = 1; j <= w; ++j) {
				if (!visited[i][j] && A[i][j] == 1) {
					cnt++;
					dfs(i, j);
				}
			}
		}

		printf("%d\n", cnt);
	}
}