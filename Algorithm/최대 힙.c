#include<stdio.h>
#include<string.h>

int length = 0;
int tree[200000] = { 0, };
void del();
void create();
void recreate();
void insert(int);
void swap(int, int);

int main() {

	int N = 0, x = 0;
	int j = 0;

	scanf_s("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf_s("%d", &x);
		if (x) {
			insert(x);
		}
		else {
			del();
		}
	}
	return 0;
}

void insert(int x) {
	int p = 1;
	while (tree[p]) {
		p++;
	}
	tree[p] = x;
	length = p;
	create();
}

void create() {
	int N = length;
	int end = 0;
	int index = 0, key = 0;
	end = N;

	while (end != 1) {
		if (tree[end / 2] < tree[end]) {
			swap(end, end / 2);
			end /= 2;
		}
		else break;
	}
}

void swap(int a, int b) {
	int tmp = 0;
	tmp = tree[a];
	tree[a] = tree[b];
	tree[b] = tmp;
}

void del() {
	printf("%d\n", tree[1]);
	if (tree[1] != 0) {
		tree[1] = tree[length];
		tree[length] = 0;
		length--;
		recreate();
	}
}

void recreate() {
	int N = length;
	int index = 1, key = 0;

	while (index != N) {
		if (tree[index * 2] < tree[index * 2 + 1]) {
			if (tree[index] < tree[index * 2 + 1]) {
				swap(index, index * 2 + 1);
				index = index * 2 + 1;
			}
			else break;
		}
		else if (tree[index] < tree[index * 2]) {
			swap(index, index * 2);
			index *= 2;
		}
		else break;
	}
}