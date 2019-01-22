#include <iostream>
#include <ios>
#include <algorithm>
#include<string.h>

using namespace std;

int height[10];
int answer[8];
void brute_force();

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int i = 0; i < 9; i++) {
		cin >> height[i];
	}
	brute_force();

	sort(answer, answer + 8);
	for (int i = 1; i <= 7; i++) {
		cout << answer[i]<<"\n";
	}
	return 0;
}

void brute_force() {	
	int sum = 0;
	int a = 0;
	int b = 1;
	int counter = 0;

	while (true) {
		b = a + 1;
		for (int i = b; i <= 8; i++) {
			memset(answer, 0, sizeof(answer));
			counter = 0;
			sum = 0;
			for (int j = 0; j < 9; j++) {
				if (j != a && j != i) {
					answer[counter] = height[j];
					counter++;
				}
			}
			for (int k = 0; k < 7; k++) {
				sum += answer[k];
			}
			if (sum == 100) {
				return;
			}
			b++;
		}
		a++;
	}
}
