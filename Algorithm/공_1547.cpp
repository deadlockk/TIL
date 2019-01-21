#include <iostream>
#include <ios>
#include <algorithm>

using namespace std;

int find(int);
int cup[4] = { 0,1,2,3 };

int main() {
	
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int M = 0;
	int X, Y;

	cin >> M;
	while (M--) {
		cin >> X >> Y;
		swap(cup[find(X)], cup[find(Y)]);
	}
	cout << cup[1];
	return 0;
}

int find(int num) {
	for (int i = 1; i <= 3; i++) {
		if (cup[i] == num) {
			return i;
		}
	}
}
