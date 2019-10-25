#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solve(int n, int x, int y) {
	if (n == 0) return;
	solve(n - 1, x, 6 - x - y);
	printf("%d %d\n", x, y);
	solve(n - 1, 6 - x - y, y);
}

int main() {
	int N;
	scanf("%d", &N);
	printf("%d\n", (1 << N) - 1);
	solve(N, 1, 3);
}