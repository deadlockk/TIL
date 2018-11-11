#pragma warning (disable :4996)
#include <cstdio>
#include <vector>

using namespace std;

int sum(int);
void update(int, int);

vector<int> arr;
vector<int> tree;

int main() {
	int N, M;
	int b,c;
	
	scanf("%d %d", &N, &M);

	arr.resize(N + 1);
	tree.resize(N + 1);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
		update(i, arr[i]);
	}

	for (int i = 0; i < M ; i++) {
			scanf("%d %d", &b, &c);
			printf("%d\n", sum(c) - sum(b - 1));
	}
	return 0;
}

void update(int i, int difference) {
	while (i < tree.size()) {
		tree[i] += difference;
		i += (i & -i);
	}
}

int sum(int i) {
	int ans = 0;
	while (i > 0) {
		ans += tree[i];
		i -= (i & -i);
	}
	return ans;
}