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
	scanf("%d %d", &N, &M);
	parent = vi(N + 10);
	for (int i = 0; i <= N; i++) {
		parent[i] = i;
	}
	while (M--) {
		int w, x, y;
		scanf("%d %d %d", &w, &x, &y);
		if (w == 0) {
			Union(x, y);
		}
		else {
			x = Find(x);
			y = Find(y);
			if (x == y) {
				puts("YES");
			}
			else {
				puts("NO");
			}
		}
	}
}