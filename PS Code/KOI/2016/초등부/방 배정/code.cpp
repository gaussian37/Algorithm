#include <iostream>>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	vector<int> data2(10);
	vector<vector<int>>data(2, vector<int>(8));
	
	//row - 0 : W, row - 1 : M
	for (int i = 0; i < N; ++i) {
		int y, x;
		scanf("%d %d", &y, &x);
		data[y][x]++;
	}
	
	int ans = 0;
	for (int i = 0; i < 2; ++i) {
		for (int j = 1; j <= 7; ++j) {
			if (data[i][j] == 0)
				continue;
			else{
				int q = data[i][j] / K;
				if (data[i][j] % K != 0)
					ans += q + 1;
				else
					ans += q;
			}
		}
	}

	printf("%d", ans);
}