#include <iostream>
#include <ios>

using namespace std;

int moneyA(int a) {
	
	int money_A;
	if (a == 0)
		money_A = 0;
	else if (a == 1)
		money_A = 5000000;
	else if (2 <= a && a <= 3)
		money_A = 3000000;
	else if (4 <= a && a <= 6)
		money_A = 2000000;
	else if (7 <= a && a <= 10)
		money_A = 500000;
	else if (11 <= a && a <= 15)
		money_A = 300000;
	else if (16 <= a && a <= 21)
		money_A = 100000;
	else
		money_A = 0;
	return money_A;
}
int moneyB(int b) {
	int money_B;
	if (b == 0)
		money_B = 0;
	else if (b == 1)
		money_B = 5120000;
	else if (2 <= b && b <= 3)
		money_B = 2560000;
	else if (4 <= b && b <= 7)
		money_B = 1280000;
	else if (8 <= b && b <= 15)
		money_B = 640000;
	else if (16 <= b && b <= 31)
		money_B = 320000;
	else
		money_B = 0;

	return money_B;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T, a, b;
	cin >> T;

	while (T) {
		cin >> a >> b;
		cout << moneyA(a) + moneyB(b)<<"\n";
		T--;
	}
	return 0;
}
