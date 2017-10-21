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

int pow(int x, int p) {
	int ans = 1;
	for (int i = 0; i<p; i++) {
		ans = ans * x;
	}
	return ans;
}
int next(int a, int p) {
	int ans = 0;
	while (a > 0) {
		ans += pow(a % 10, p);
		a /= 10;
	}
	return ans;
}
int dfs(int a, int p, int cnt) {
	if (visited[a] != 0) {
		return visited[a] - 1;
	}
	visited[a] = cnt;
	int b = next(a, p);
	return dfs(b, p, cnt + 1);
}
int main() {
	int a, p;
	visited = vi(1000000);
	scanf("%d%d", &a, &p);
	printf("%d\n", dfs(a, p, 1));

	return 0;
}