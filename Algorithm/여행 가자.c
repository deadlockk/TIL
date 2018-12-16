#include <stdio.h>
#include <string.h>

int check[200];
int find(int);
void unionset(int, int);

int main() {
	int N, M;
	int a, b;
	int mtrx[200][200];
	int itinerary[200];

	scanf("%d", &N);
	scanf("%d", &M);

	memset(check, -1, sizeof(check));
	for (int p = 0; p < 200; p++)
		memset(mtrx[p], -1, sizeof(int) * 200);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &a);
			mtrx[i][j] = a;
			if (a==1)
				unionset(i, j);
		}
	}

	for (int k = 0; k < M; k++) {
		scanf("%d", &b);
		itinerary[k] = b;
	}

	for (int q = 0; q < M-1; q++) {
		if (find(check[q]) != find(check[q+1])) {
			printf("NO");
		//	system("pause");
			return 0;
		}
	}
	printf("YES");
	//system("pause");
	return 0;
}

int find(int a) {
	if (check[a] == -1)
		return a;
	return check[a] = find(check[a]);
}
void unionset(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return;
	check[b] = a;
}