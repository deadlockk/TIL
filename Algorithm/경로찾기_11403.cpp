#include<cstdio>

int find(int, int);
int G[101][101];
int arr[101];

int main() {

	int N,a;
	scanf_s("%d", &N);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf_s("%d", &a);
			G[i][j] = a;
			if (a)
				arr[i] = j;
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (find(i, j) == 1)
				printf("1");
			else printf("0");
		}
		printf("\n");
	}
	return 0;
}

int find(int i, int j) {
	int n;
	
	return;
}