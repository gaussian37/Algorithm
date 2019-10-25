#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int w[20][20];

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i<N; i++) {
		for (int j = 0; j<N; j++) {
			scanf("%d", &w[i][j]);
		}
	}

	vector<int> d(N);
	for (int i = 0; i<N; i++) {
		d[i] = i;
	}

	int ans = 1e9;

	do {
		bool ok = true;
		int sum = 0;
		for (int i = 0; i<N - 1; i++) {
			if (w[d[i]][d[i + 1]] == 0) {
				ok = false;
			}
			else {
				sum += w[d[i]][d[i + 1]];
			}
		}
		if (ok && w[d[N - 1]][d[0]] != 0) {
			sum += w[d[N - 1]][d[0]];
			ans = min(ans, sum);
		}
	} while (next_permutation(d.begin(), d.end()));

	printf("%d\n", ans);
	return 0;
}