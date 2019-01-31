#include <iostream>
#include <ios>
#include <algorithm>
#include<functional>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> n;
	// 0과1을 저장 할 벡터 생성
	vector<int> ind;
	int k, input;
	while (true) {
		n.clear();
		ind.clear();
		cin >> k;
		if (k == 0) {
			break;
		}
		for (int i = 0; i < k; i++) {
			cin >> input;
			n.push_back(input);
		}

		// 6개의 1 추가
		for (int i = 0; i < 6; i++) {
			ind.push_back(1);
		}
		for (int i = 0; i < n.size() - 6; i++) {
			ind.push_back(0);
		}
		// 정렬
		sort(ind.begin(), ind.end(),greater<int>());

		//조합
		do {
			for (int i = 0; i < ind.size(); i++) {
				if (ind[i] == 1) {
					cout << n[i] << " ";
				}
			}
			cout << "\n";
		} while (prev_permutation(ind.begin(), ind.end()));
		cout << "\n";
	}
	
	return 0;
}
