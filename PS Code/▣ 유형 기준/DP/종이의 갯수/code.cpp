#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> a;
vector<int> cnt(4);

bool same(int y, int x, int n) {
	for (int i = y; i < y + n; i++) {
		for (int j = x; j < x + n; j++) {
			if (a[y][x] != a[i][j])
				return false;
		}
	}
	return true;
}

void solve(int y, int x, int n) {
	if (same(y, x, n)) {
		cnt[a[y][x] + 1] += 1;
		return;
	}

	int m = n / 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			solve(y + i*m, x + j*m, m);
		}
	}
}
int main() {
	int N;
	scanf("%d", &N);
	a = vector<vector<int>>(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	solve(0, 0, N);

	printf("%d\n%d\n%d", cnt[0], cnt[1], cnt[2]);
}
