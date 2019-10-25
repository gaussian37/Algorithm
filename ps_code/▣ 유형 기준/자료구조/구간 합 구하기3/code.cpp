#include <cstdio>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;

int N, M;
vii tree, A;
int range_sum(int y, int x) {
	int ans = 0;
	for(int i = y; i > 0; i -= i & -i){
		for (int j = x; j > 0; j -= j & -j) {
			ans += tree[i][j];
		}
	}
	return ans;
}

void update(int y, int x, int diff) {
	for (int i = y; i <= N; i+= i & -i) {
		for (int j = x; j <= N; j += j & -j) {
			tree[i][j] += diff;
		}
	}
}

int main() {
	scanf("%d%d", &N, &M);
	tree = A = vii(N + 2, vi(N + 2));	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &A[i][j]);
			update(i, j, A[i][j]);
		}
	}

	while (M--) {
		int a;
		scanf("%d", &a);
		if (a == 0) {
			int x, y, val;
			scanf("%d%d%d", &y, &x, &val);
			update(y, x, val - A[y][x]);
			A[y][x] = val;
		}
		else {
			int x1, y1, x2, y2;
			scanf("%d%d%d%d", &y1, &x1, &y2, &x2);
			printf("%d\n", range_sum(y2, x2) - range_sum(y1 - 1, x2) - range_sum(y2, x1 - 1) + range_sum(y1 - 1, x1 - 1));
		}
	}
	return 0;
}