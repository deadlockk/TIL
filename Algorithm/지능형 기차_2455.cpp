#include <iostream>
#include <ios>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int in, out, max;

	for (auto i = 0; i < 4; i++) {
		cin >> out >> in;
		if (i == 0)
			max = in;
		
		else {
			if (in - out + max > max) {
				max = in - out + max;
			}
		}
	}
	cout << max;
	return 0;
}
