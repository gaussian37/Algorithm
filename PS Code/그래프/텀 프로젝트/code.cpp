#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
vi A, visited, S;
int N;

int dfs(int x, int cnt, int step) {
	if (visited[x] != 0) {
		if (step != S[x]) {
			return 0;
		}
		return cnt - visited[x];
	}
	visited[x] = cnt;
	S[x] = step;
	return dfs(A[x], cnt + 1, step);
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		A = S = visited = vi(N + 2);

		for (int i = 1; i <= N; i++) {
			scanf("%d", &A[i]);
		}

		int ans = 0;
		for (int i = 1; i <= N; i++) {
			if (visited[i] == 0) {
				ans += dfs(i, 1, i);
			}
		}
		printf("%d\n", N - ans);
	}
	return 0;
}