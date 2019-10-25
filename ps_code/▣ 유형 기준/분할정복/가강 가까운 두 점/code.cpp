#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int, int> pi;

int n;
vector<pi> a;
pi ans[2];

bool cmp(pi a, pi b) {
	return a.second < b.second;
}

int dist(pi x, pi y) {
	return (y.second - x.second) * (y.second - x.second)
		+ (y.first - x.first) * (y.first - x.first);
}

int square(int x) {
	return x*x;
}

int closest_pair(int s, int e) {
	//분할 결과 3개의 점이 남을 때
	if (s == e - 2) {
		return min(min(dist(a[s], a[s + 1]), dist(a[s + 1], a[s + 2])), dist(a[s], a[s + 2]));
	}
	//분할 결과 2개의 점이 남을 때
	if (s == e - 1) {
		return dist(a[s], a[e]);
	}

	//가운데 부분 
	int mid = (s + e) / 2;
	//Divide & Conquer
	int rst = min(closest_pair(s, mid), closest_pair(mid + 1, e));

	//combine할 때 분할 된 경계 범위 사이 고려
	vector<pi> sub; //범위 rst 안에 드는 대상 저장할 vector
					//rst 범위 사이에 드는 점들은 일단 넣는다.
	for (int i = s; i <= e; i++) {
		if (abs(a[i].first - a[mid].first) < rst) {
			sub.push_back(a[i]);
		}
	}

	//저장된 점들만 y축 기준으로 정렬한다.
	sort(sub.begin(), sub.end(), cmp);
	for (int i = 0; i<sub.size(); i++) {
		for (int j = i + 1; j < sub.size(); ++j) {
			//이미 범위가 넘어가면 끝낸다.
			if (square((sub[j].second - sub[i].second)) >= rst) {
				break;
			}
			//최솟값 갱신
			rst = min(rst, dist(sub[j], sub[i]));
		}
	}
	return rst;
}

int main() {
	scanf("%d", &n);
	a = vector<pi>(n);

	for (int i = 0; i<n; i++) {
		scanf("%d %d", &a[i].first, &a[i].second);
	}

	//x축 기준으로 먼저 정렬한다.
	sort(a.begin(), a.end());
	printf("%d", closest_pair(0, n - 1));
}