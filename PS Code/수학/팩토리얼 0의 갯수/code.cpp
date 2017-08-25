#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

int main() {
	int N;
	scanf("%d", &N);
	
	int ans = 0;
	for (int i = 5; i <= N; i *= 5) {
		ans += N / i;
	}
	printf("%d\n", ans);
}