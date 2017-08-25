#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

int factorial(int N) {
	if (N == 0) {
		return 1;
	}
	else {
		return N * factorial(N - 1);
	}
}

int main() {
	int N;
	scanf("%d", &N);
	printf("%d\n", factorial(N));
}