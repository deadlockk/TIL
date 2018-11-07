#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int A[200002];
string S, S2;
int r = 0, p = 0;
int ans = -1;

int main() {
	std::ios::sync_with_stdio(false);
	cin >> S;

	for (int i = 0; i < S.size(); i++) {
		S2 = S2 + '#';
		S2 += S[i];
	}
	S2 += '#';

	int len = S2.size();
	for (int i = 0; i < len; i++) {
		if (i <= r)
			A[i] = min(A[2 * p - i], r - i);
		else
			A[i] = 0;

		while (i - A[i] - 1 >= 0 && i + A[i] + 1 < len && S2[i - A[i] - 1] == S2[i + A[i] + 1])
			A[i]++;

		if (r < i + A[i]) {
			r = i + A[i];
			p = i;
		}

		ans = max(ans, A[i]);
	}

	cout << ans;
	return 0;
}