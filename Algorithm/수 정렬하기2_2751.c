#include<stdio.h>

void swap(int*, int*);
void quickSort(int, int, int*);
int arr[1000000];

int main() {
	int N = 0;

	scanf_s("%d", &N);

	for (int j = 0; j < N; j++)
		scanf_s("%d", &arr[j]);

	quickSort(0, N - 1, arr);
	for (int i = 0; i < N; i++)
		printf("%d\n", arr[i]);

	return 0;
}

void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void quickSort(int left, int right, int* data) {
	int pivot = left;
	int j = pivot;
	int i = left + 1;

	if (left < right) {
		for (; i <= right; i++) {
			if (data[i] < data[pivot]) {
				j++;
				swap(&data[j], &data[i]);
			}
		}
		swap(&data[left], &data[j]);
		pivot = j;

		quickSort(left, pivot - 1, data);
		quickSort(pivot + 1, right, data);

	}
}