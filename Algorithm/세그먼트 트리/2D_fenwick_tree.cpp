#include <cstdio>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;

int N, M;
vii tree, A;
int range_sum(int y, int x) {
	int ans = 0;
	for (int i = y; i > 0; i -= i & -i) {
		for (int j = x; j > 0; j -= j & -j) {
			ans += tree[i][j];
		}
	}
	return ans;
}

void update(int y, int x, int diff) {
	for (int i = y; i <= N; i += i & -i) {
		for (int j = x; j <= N; j += j & -j) {
			tree[i][j] += diff;
		}
	}
}