#include <iostream>
#include <ios>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, tmp, answer = 0, X[5];
	cin >> N;

	for (int i = 1; i <= N; i++) {
		tmp = i;
		if (i < 100) {
			answer++;
		}
		else if (100 <= i && i < 1000) {
			X[2] = tmp % 10;
			tmp /= 10;
			X[1] = tmp % 10;
			tmp /= 10;
			X[0] = tmp % 10;
			if (X[1] - X[0] == X[2] - X[1]) {
				answer++;
			}
		}
		else//N == 1000
			break;
	}
	cout << answer;
	return 0;
}