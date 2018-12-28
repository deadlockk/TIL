#include <stdio.h>
#include <string.h>
int N[1000001];

int findSet(int);
void mergeSet(int, int);

int main() {
	int n, m;
	scanf_s("%d %d", &n, &m);
	memset(N, -1, sizeof(N));
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		scanf_s("%d %d %d", &c, &a, &b);
		if (c == 0)
			mergeSet(a, b);
		else {
			if (findSet(a) == findSet(b))
				printf("YES\n");
			else
				printf("NO\n");
		}
	} return 0;
}

int findSet(int a) {
	if (N[a] < 0)
		return a;
	return N[a] = findSet(N[a]);
}
void mergeSet(int a, int b) {
	a = findSet(a);//şÎ¸đ ĆÇş°
	b = findSet(b);
	if (a == b)
		return;
	N[b] = a;
}
