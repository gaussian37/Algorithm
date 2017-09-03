#include <iostream>
#include <cstring>

using namespace std;

int board[16][16];
int N;
int cnt;

bool UP(int r, int c) {
	for (int i = r - 1; i >= 0; --i)
		if (board[i][c] == 1) return false;
	return true;
}

bool LU(int r, int c) {
	for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; --i, --j)
		if (board[i][j] == 1) return false;
	return true;
}

bool RU(int r, int c) {
	for (int i = r - 1, j = c + 1; i >= 0 && j<N; --i, ++j)
		if (board[i][j] == 1) return false;
	return true;
}

void NQueen(int r, int Queen) {

	for (int i = 0; i<N; ++i) {
		if (board[r][i] == 0)
			if (UP(r, i) && LU(r, i) && RU(r, i)) {

				if (Queen == N) { cnt++; return; }

				board[r][i] = 1;
				NQueen(r + 1, Queen + 1);
				board[r][i] = 0;
			}
	}
}

int main() {
	scanf("%d", &N);
	NQueen(0, 1);
	printf("%d\n", cnt);
	return 0;
}