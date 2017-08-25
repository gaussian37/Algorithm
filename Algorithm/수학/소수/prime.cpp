#include <iostream>
#include <vector>

using namespace std;

bool prime(int N) {
	if (N < 2) {
		return false;
	}
	for (int i = 2; i * i <= N; ++i) {
		if (N % i == 0) {
			return false;
		}
	}
	return true;
}