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
