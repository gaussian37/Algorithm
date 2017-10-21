#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef pair<int, int> ii;

//Top-down
#if 1

int N, M;
vii A, dp;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int solve(int y, int x) {
	if (y == N && x == M){
		return 1;
	}

	if (dp[y][x] != -1) {
		return dp[y][x];
	}

	dp[y][x] = 0;
	for (int k = 0; k < 4; ++k){
		int ny = y + dy[k];
		int nx = x + dx[k];
		if (A[ny][nx] > 0 && A[y][x] > A[ny][nx]) {
			dp[y][x] += solve(ny, nx);
		}
	}

	return dp[y][x];
}
int main() {
	scanf("%d %d", &N, &M);

	A = vii(N + 5, vi(M + 5, -1));
	dp = vii(N + 5, vi(M + 5, -1));

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			scanf("%d", &A[i][j]);
		}
	}

	printf("%d\n", solve(1, 1));

	return 0;
}

//bottom up
#else

struct Cell {
	int row, col, val;

	/*bool operator < (const Cell _cell) {
		return val < _cell.val;
	}*/
};

bool cmp(const Cell &u, const Cell &v) {
	return u.val > v.val;
}

int N, M;
vii A, dp;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int main() {
	scanf("%d%d", &N, &M);
	A = vii(N + 5, vi(M + 5, -1));
	dp = vii(N + 5, vi(M + 5));
	
	vector<Cell> v;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &A[i][j]);
			v.push_back({ i, j, A[i][j] });
		}
	}

	sort(v.begin(), v.end(), cmp);
	
	dp[1][1] = 1;
	for (int i = 0; i < v.size(); i++) {

		int y = v[i].row;
		int x = v[i].col;

		for (int k = 0; k < 4; k++) {

			int ny = y + dy[k];
			int nx = x + dx[k];			

			if (A[ny][nx] >= 0 && A[ny][nx] < A[y][x]) {
				dp[ny][nx] += dp[y][x];
			}
		}
	}

	cout << dp[N][M] << '\n';
	return 0;
}


#endif
