#include<stdio.h>

int gcd(int, int);

int main() {
	int a, b;
	int G;
	scanf_s("%d %d", &a, &b);
	G = gcd(a, b);
	printf("%d\n", G);
	printf("%d", a*b / G);
}

int gcd(int a, int b) {
	int big = 0, small = 0;
	int tmp = 0;

	if (a > b) {
		big = a;
		small = b;
	}
	else {
		big = b;
		small = a;
	}

	while (big % small != 0) {
		tmp = big % small;
		big = small;
		small = tmp;
	}
	return small;
	
}
