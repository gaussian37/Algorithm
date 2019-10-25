#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a%b);
	}
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", lcm(a, b));
	}
}