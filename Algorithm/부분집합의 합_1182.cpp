#include <iostream>
#include <ios>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, S,answer=0,sum=0,digits=1;
	int newN[21];
	vector<int> idx;

	cin >> N >> S;
	for (int i = 0; i < N; i++)
		cin >> newN[i];

	for (int i = 0; i < N; i++) {
		idx.clear();
		for (int j = 0; j < digits; j++) 
			idx.push_back(1);
		
		for (int k = 0; k < N - digits; k++)
			idx.push_back(0);

		sort(idx.begin(), idx.end());
		
		do {
			for (int x = 0; x < idx.size(); x++) {
				if (idx[x] == 1) {
					sum += newN[x];
				}
			}
			if (sum == S)
				answer++;
			sum = 0;
		} while (next_permutation(idx.begin(), idx.end()));
		digits++;
	}
	cout << answer;
	return 0;
}