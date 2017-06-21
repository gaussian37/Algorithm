#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<string> a;
void solve(int y, int x, int n, bool star) {
	if (!star) {
		for (int i = y; i < y + n; ++i) {
			for (int j = x; j < x + n; ++j) {
				a[i][j] = ' ';
			}
		}
	}
	else {
		if (n == 1) {
			a[y][x] = '*';
		}
		else {
			int m = n / 3;
			bool isStar = true;
			for (int i = 0; i < 3; ++i) {
				for (int j = 0; j < 3; ++j) {
					if (i == 1 && j == 1) {
						isStar = false;
					}
					else {
						isStar = true;
					}
					solve(y + m*i, x + m*j, m, isStar);
				}
			}
		}
	}

}
int main() {

	int N;
	scanf("%d", &N);
	a = vector<string>(N, string(N, ' '));
	solve(0, 0, N, true);

	for (int i = 0; i < N; ++i) {
		cout << a[i] << endl;
	}


}