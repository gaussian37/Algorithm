#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;

vii A;

void preorder(int x) {
	if (x == -1) return;
	printf("%c", (char)(x + 'A'));
	preorder(A[x][0]);
	preorder(A[x][1]);
}

void inorder(int x) {
	if (x == -1) return;
	inorder(A[x][0]);
	printf("%c", (char)(x + 'A'));
	inorder(A[x][1]);
}

void postorder(int x) {
	if (x == -1) return;
	postorder(A[x][0]);
	postorder(A[x][1]);
	printf("%c", (char)(x + 'A'));
}

int main() {
	int N;
	scanf("%d", &N);
	A = vii(N + 2, vi(2));
	for (int i = 1; i <= N; ++i) {
		string a, b, c;
		cin >> a >> b >> c;		
		if (b[0] == '.') {
			A[a[0] - 'A'][0] = -1;
		}
		else {
			A[a[0] - 'A'][0] = b[0] - 'A';
		}
		if (c[0] == '.') {
			A[a[0] - 'A'][1] = -1;
		}
		else {
			A[a[0] - 'A'][1] = c[0] - 'A';
		}
	}

	preorder(0); puts("");
	inorder(0); puts("");
	postorder(0); puts("");
	
}