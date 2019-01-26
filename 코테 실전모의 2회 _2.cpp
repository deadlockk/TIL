#include <iostream>
#include <ios>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(int l, vector<int> v) {
	int answer = 0;
	sort(v.begin(), v.end());

	int check = 0;
	int interval = 0;
	double max_interval = 0;

	for (int i = v.size(); i > 1; i--) {
		check = 1;
		interval = v[i - 1] - v[i - 2];
		max_interval = max((int)max_interval, interval);
	}

	if (check == 0) {
		if (l - v[0] <= l / 2) {
			answer = v[0];
		}
		else
		answer = l-v[0];
	}
	else
		answer = ceil(max_interval / 2);

	cout << answer << endl;

	return answer;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int l = 6;
	vector<int> v = { 1 };
	solution(l, v);
	return 0;
}