#include <iostream>
using namespace std;
void solve(int N) {
	if (N == 0) {
		return;
	}
	if (N % 2 == 0) {
		solve(N / (-2));
		printf("0");
	}
	else {
		if (N > 0) {
			solve(N / (-2));
		}
		else {
			solve((N - 1) / (-2));
		}
		printf("1");
	}
}

int main() {
	int N;
	scanf("%d", &N);
	if (N == 0) {
		printf("0\n");
	}
	else {
		solve(N);
	}
	return 0;
}