#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef pair<int, int> ii;


vi parent;

int Find(int x) {
	if (x == parent[x]) {
		return x;
	}
	else {
		return parent[x] = Find(parent[x]);
	}
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x != y) {
		parent[y] = x;
	}
}

int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	parent = vi(N + 5);
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	while (M--) {
		int x, y;
		cin >> x >> y;
		Union(x, y);
	}

	int ans = 0;
	for (int i = 2; i <= N; i++) {
		if (Find(1) == Find(i)) {
			ans += 1;
		}
	}
	printf("%d\n", ans);

	return 0;
}