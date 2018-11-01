#pragma warning (disable:4996)
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int A, B;//진법
	int result[20];
	int m, value, power;
	int Decimal_Notation = 0;
	int valueCheck;

	cin >> A >> B;
	cin >> m;

	//10진법 생성
	while (m--) {
		power = 1;
		cin >> value;
		for (auto i = 0; i < m; i++)
			power *= A;
		Decimal_Notation = Decimal_Notation + (value * power);
	}

	//B진법으로 변환
	for (valueCheck = 0; Decimal_Notation > 0; valueCheck++) {
		result[valueCheck] = Decimal_Notation % B;
		Decimal_Notation = Decimal_Notation / B;
	}

	//역으로 출력
	for (auto j = valueCheck - 1; j >= 0; j--)
		cout << result[j] << " ";

	return 0;
}