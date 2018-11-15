#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int arr[1000000];
vector<int> tree;

int build(int, int, int);
void updat(int, int);

int main() {
	int N, M, K;
	int a, b, c;

	scanf_s("%d %d %d", &N, &M, &K);

	int H = (int)ceil(log2(N));
	int size = (1 << (H + 1));
	tree.resize(size+1);

	for (int i = 1; i <= N; i++) {
		scanf_s("%d", &arr[i]);
	}
	build(1, 1, N+1);

	for (int i = 0; i < M + K; i++) {
		scanf_s("%d", &a);
		if (a == 1) {
			scanf_s("%d %d", &b, &c);
			updat(b, c);
		}
		if (a == 2) {
			scanf_s("%d %d", &b, &c);

		}
	}
	return 0;
}

void updat(int index, int key) {
	index;
}

int build(int node, int start, int end) {
	if (start == end)
		return tree[node] = arr[start];
	int mid = (start + end) / 2;
	return tree[node] = build(node * 2, start, mid) + build(node * 2 + 1, mid + 1, end);
}