#include <iostream>
#include <vector>

using namespace std;

bool prime(int N) {
	if (N < 2) {
		return false;
	}
	for (int i = 2; i * i <= N; ++i) {
		if (N % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {

	int N;
	scanf("%d", &N);
	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		int num;
		scanf("%d", &num);
		cnt += prime(num);
	}
	printf("%d\n", cnt);
}