#include <iostream>>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define Point pair<int,int> 
#define Y frist
#define value second

struct bar {
	int x, yl, yh;

	bool operator < (const bar& _bar) const {
		return x < _bar.x;
	}
};

int main(){

	//int N, st_y, end_x;
	//scanf("%d %d %d", &N, &st_y, &end_x);

	//vector<bar> barrier(N);
	//for (int i = 0; i < N; ++i) {
	//	scanf("%d %d %d", &barrier[i].x, &barrier[i].yl, &barrier[i].yh);
	//}
	//
	//sort(barrier.begin(), barrier.end());

	////first : y, second : value
	//set<pair<int, int>> data;
	//data.insert(Point(st_y, 0));

	//for (int i = 0; i < N; ++i) {
	//	Point im;
	//	int lmin = (int)1e9, rmin = (int)1e9;

	//	Point sim = Point(barrier[i].yl, 0);
	//	auto it = data.lower_bound(sim);
	//	if (it == data.end()) continue;

	//	vector<int> v;
	//	for (; it != data.end(); ++it) {
	//		im = *it;
	//		if (im.first > barrier[i].yh) break;
	//		v.push_back(im.second);

	//		if (im.second < barrier[i].yh) {
	//			lmin = min(lmin, im.second);
	//			data.insert(sim);
	//		}

	//		if()
	//	}

	//}




}