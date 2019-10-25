#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> a;

bool same(int y, int x, int n) {
	for (int i = y; i < y + n; i++) {
		for (int j = x; j < x + n; j++) {
			if (a[y][x] != a[i][j]) {
				return false;
			}
		}
	}
	return true;
}

void solve(int y, int x, int n) {
	if (same(y, x, n)) {
		printf("%d", a[y][x]);
	}
	else {
		printf("(");
		int m = n / 2;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				solve(y + m*i, x + m*j, m);
			}
		}
		printf(")");
	}
}

int main() {
	int N;
	scanf("%d", &N);
	a = vector<vector<int>>(N + 1, vector<int>(N + 1)); 
	for (int i= 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &a[i][j]);
		}
	}
	solve(0, 0, N);

}