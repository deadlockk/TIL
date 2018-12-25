#pragma warning (disable :4996)

#include <cstdio>
#include <vector>

using namespace std;

long long sum(int);
void update(int, long long);

vector<long long> arr;
vector<long long> tree;

int main() {
	
	int N, M, K;
	int a, b;
	long long c, difference;

	scanf("%d %d %d", &N, &M, &K);

	arr.resize(N + 1);
	tree.resize(N + 1);

	for (int i = 1; i <= N; i++) {
		
		scanf("%lld", &arr[i]);
		update(i, arr[i]);
		
	}

	for (int i = 0; i < M + K; i++) {
		scanf("%d", &a);
		if (a == 1) {
			scanf("%d %lld", &b, &c);
			difference = c - arr[b];
			arr[b] = c;
			update(b, difference);
		}
		if (a == 2) {
			scanf("%d %lld", &b, &c);
			printf("%lld\n", sum(c) - sum(b - 1));
		}
	}
	return 0;
}

void update(int i, long long difference) {
	while (i < tree.size()) {
		tree[i] += difference;
		i += (i & -i);
	}
}

long long sum(int i) {
	long long ans = 0;
	while (i > 0) {
		ans += tree[i];
		i -= (i & -i);
	}
	return ans;
}
