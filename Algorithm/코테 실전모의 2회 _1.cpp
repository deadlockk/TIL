#include <iostream>
#include <ios>
#include<vector>
using namespace std;

bool solution(vector<int> arrA, vector<int> arrB) {
	bool answer = true;
	int check = 0;
	int x = 0,y=0;
	int tmp1, tmp2, tmp3,tmp4,tmp5;

	if (arrA.size() != arrB.size())
		return false;

	for (int i = 0; i < arrA.size(); i++) {
		if (arrB[check] == arrA[i]) {
			x = 1;
			tmp1 = check; tmp2 = i, tmp3 = i;
			while (true) {
				y = 0;
				if (tmp3 + 1 == arrA.size())
					break;
				if (arrB[check] == arrA[++tmp3]) {
					tmp4 = tmp3;
					tmp5 = check;
					while (tmp4+1 < arrA.size()) {
						if (arrB[++tmp5] != arrA[++tmp4]) {
							y = 1;
							break;
						}
					}
					if(y==0)
						tmp2 = tmp3;
				}
			}
			while (true) {
				if (tmp1 + 1 == arrA.size() || tmp2 + 1 == arrA.size())
					break;
				if (arrB[++tmp1] == arrA[++tmp2]) {
					continue;
				}
				else
					return false;
			}
			for (int j = 0; j < arrA.size() - (tmp1 + 1); j++) {
				if (arrA[j] != arrB[tmp1 + 1 + j]) {
					return false;
				}
			}
			break;
		}
	}
	if (x == 0) {
		answer = false;
	}
	return answer;
}
int main() {
	
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> arrA = { 7,8,7,9,7,8,7,10 };
	vector<int> arrB = { 7,8,7,10,7,8,7,9 };

	if (solution(arrA, arrB)) {
		cout << "true";
	}
	else {
		cout << "false";
	}

	return 0;
}
