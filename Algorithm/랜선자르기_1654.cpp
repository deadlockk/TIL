#include <iostream>
#include <ios>
#include <vector>
#include <algorithm>

using namespace std;

int K, N;//이미 가지고 있는 랜선의 개수 K, 그리고 필요한 랜선의 개수 N
vector<int> cable;

long long cut(int x) {
	long long num = 0;
	for (int i = 0; i < K; i++) {
		num += cable[i] / x;
	}
	return num;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int input, max_length = 0;

	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		cin >> input;
		cable.push_back(input);
		max_length = max(input, max_length);
	}
	long long min_lan = 1, max_lan = max_length, mid;
	
	while (min_lan <= max_lan) {
		mid = (min_lan + max_lan) / 2;
		if (cut(mid) < N)
			max_lan = mid - 1;
		else if (cut(mid) >= N)
			min_lan = mid + 1;
	}

	cout << min_lan-1;
	return 0;
}