#include <iostream>
#include <ios>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> N_v;
vector<int> M_v;

int binary_search(int x) {
	int answer = 0;
	int left = 0, right = N_v.size();

	while (left <= right) {
		int mid = (left + right) / 2;
		if (N_v[mid] > M_v[x])
			right = mid - 1;
		else if (N_v[mid] < M_v[x])
			left = mid + 1;
		else {
			answer = mid;
			break;
		}
	}
	if (N_v[answer]==M_v[x])
		return 1;
	else
		return 0;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M, input;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> input;
		N_v.push_back(input);
	}

	sort(N_v.begin(), N_v.end());

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> input;
		M_v.push_back(input);
		cout << binary_search(i) << "\n";
	}
	return 0;
}
