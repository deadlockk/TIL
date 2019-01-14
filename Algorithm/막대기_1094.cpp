#include <iostream>
#include <ios>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int X;
	int binary_num=0;

	cin >> X;

	while (X) {
		if (X % 2 == 1)
			binary_num++;
		X = X / 2;
	}

	cout << binary_num;
	return 0;
}