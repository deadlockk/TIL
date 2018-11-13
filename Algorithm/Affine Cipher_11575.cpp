#pragma warning(disable:4996)
#include<cstdio>
#include<string>
#include<iostream>

using namespace std;

string S;

int main() {
	int T, a, b;
	int char2int;
	char cipher[] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &a, &b);
		cin >> S;
		for (auto i = 0; i < S.length(); i++) {
			for (auto j = 0; j < 26; j++) {
				if (cipher[j] == S.at(i)) {
					char2int = j;
					break;
				}
			}
			printf("%c", cipher[(a*char2int + b) % 26]);
		}
		printf("\n");
	}
	return 0;
	
}
