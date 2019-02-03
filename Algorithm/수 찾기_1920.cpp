#include <iostream>
#include <ios>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> A;

int binary_search(int x) {	
	
	int left = 0, right = A.size()-1;

	while (left <= right) {
		int mid = (left + right) / 2;
		if (A[mid] > x)
			right = mid - 1;
		else if (A[mid] < x)
			left = mid + 1;
		else {
			return 1;
		}
	}
	return 0;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int N, M, num;

	//A vector »ý¼º
	cin >> N;
	while (N--) {
		cin >> num;
		A.push_back(num);
	}
	sort(A.begin(), A.end());
	//M°³ ¼ö ÀÔ·Â
	cin >> M;
	for(int i=0;i<M;i++){
		cin >> num;
		cout << binary_search(num) << "\n";
	}
	return 0;
}
