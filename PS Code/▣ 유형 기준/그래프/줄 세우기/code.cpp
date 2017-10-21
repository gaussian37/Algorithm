#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pi;

vector<int> AdjList[32010];
vi ind;

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	ind = vi(N + 2);

	for (int i = 0; i<M; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		AdjList[u].push_back(v);
		ind[v] += 1;
	}

	queue<int> q;
	for (int i = 1; i <= N; ++i) {
		if (ind[i] == 0) {
			q.push(i);
		}
	}

	for (int j = 0; j<N; ++j) {
		int u = q.front();
		q.pop();
		printf("%d ", u);

		for (int i = 0; i<AdjList[u].size(); ++i) {
			int v = AdjList[u][i];
			ind[v] -= 1;
			if (ind[v] == 0) {
				q.push(v);
			}
		}
	}

	return 0;
}