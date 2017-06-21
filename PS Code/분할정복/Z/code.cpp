#include <iostream>
using namespace std;
int power2(int k) {
	return (1 << k);
}
int solve(int n, int x, int y) {
	if (n == 1) {
		return 2 * x + y;
	}
	else {
		if (x < power2(n - 1)) {
			if (y < power2(n - 1)) {
				return solve(n - 1, x, y);
			}
			else {
				return solve(n - 1, x, y - power2(n - 1)) + power2(2 * n - 2);
			}
		}
		else {
			if (y < power2(n - 1)) {
				return solve(n - 1, x - power2(n - 1), y) + power2(2 * n - 2) * 2;
			}
			else {
				return solve(n - 1, x - power2(n - 1), y - power2(n - 1)) + power2(2 * n - 2) * 3;
			}
		}
	}
}
int main() {
	int n, x, y;
	cin >> n >> x >> y;
	printf("%d\n", solve(n, x, y));

}