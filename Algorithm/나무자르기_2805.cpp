#include <iostream>
#include <ios>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> tree;

long long cut(int x) {
	long long sum = 0;
	for (int i = 0; i < N; i++) {
		if (tree[i] - x > 0)
			sum += (tree[i] - x);
	}
	return sum;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int input,maxTreeHeight=0,cutter;
	
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		cin >> input;
		tree.push_back(input);
		maxTreeHeight = max(input, maxTreeHeight);
	}

	int cutterHigh = 0, cutterLow = maxTreeHeight,mid;

	while (cutterHigh <= cutterLow) {

		mid = (cutterHigh + cutterLow) / 2;
		if (cut(mid) > M)
			cutterHigh = mid + 1;
		else if (cut(mid) < M)
			cutterLow = mid - 1;
		else
		{
			cout << mid;
			return 0;
		}
	}

	cout << cutterLow;
	return 0;
}