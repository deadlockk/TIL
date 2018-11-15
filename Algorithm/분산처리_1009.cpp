#include <iostream>
#include <ios>
#include <math.h>

using namespace std;

int pow_mod(int x, int y, int p, int temp){
	if (y == 1)return temp;
	y--;
	return pow_mod(x, y, p, (x*temp) % p);
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int T = 0;
	int a,b=0;
	int result = 0;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> a >> b;
		result = pow_mod(a, b, 10, a % 10);
		if (result == 0) result = 10;
		cout << result<< "\n";
	}
	return 0;
}
