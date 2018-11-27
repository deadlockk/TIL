//#pragma warning(disable:4996)
//#include <cstdio>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//struct Point {
//	int x, y;
//};
//
//bool cmp(Point, Point);
//int dist(Point, Point);
//
//int main() {
//	int N;
//	scanf("%d", &N);
//	vector<Point> a(N);
//	for (int i = 0; i < N; i++) {
//		scanf("%d %d", &a[i].x, &a[i].y);
//	}
//	sort(a.begin(), a.end(), cmp);
//
//	return 0;
//}
//bool cmp(Point &u, Point &v) {
//	return u.x < v.x;
//}
//int dist(Point &p1, Point &p2) {
//	return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
//}

#include<stdio.h>
int main(void) {
	int i, j, k;
	int line = 5;
	for (i = 0; i < line; i++) {
		for (j = line - i; j > 0; j--) {
			printf(" ");
		}
		for (k = 0; k < (2 * i + 1); k++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}