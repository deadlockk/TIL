#include<stdio.h>
#include<stdlib.h>

void swap(int, int);
void perm(int, int, int);
int arr[20];
int check[20];
int num = 2;
int N, Q;
int k = 0;

int main() {
	
	int depth = 0;

	scanf_s("%d", &N);
	for (int j = 0; j < N; j++) {
		arr[j] = j + 1;
	}
	scanf_s("%d", &Q);

	if (Q == 1) {
		scanf_s("%d", &k);
		perm(depth, N, k);
	}
	else {
		for (int a = 0; a < N; a++) {
			scanf_s("%d", &check[a]);
		}
		perm(depth, N, k);
	}

	return 0;
}

void perm(int depth, int N, int k) {
	for (int i = depth; i < N; i++) {
		swap(i, depth);
		perm(depth + 1, N, k);
	
		swap(i, depth);
	}
}

void swap(int i, int j) {
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
	if (i != j)
		num++;
	if (Q == 1) {
		if (num == k * 2 - 1) {
			for (int a = 0; a < N; a++) {
				printf("%d", arr[a]);
			}
			exit(0);
		}
	}
	if (Q == 2) {
		int key = 0;
		for (int p = 0; p < N; p++) {
			if (arr[p] == check[p]) {
				key++;
			}
			else
				break;
		}
		if (key == 4) {
			printf("%d", (num + 1) / 2);
			exit(0);
		}
	}
}
