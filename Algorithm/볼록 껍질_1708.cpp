#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#pragma warning(disable:4996)

typedef struct dot {
	float x, y;
	float angle;
}Dot;

Dot P[100], S[100];
int top = -1;

void Push(Dot);
void Pop();
int cwccw(int, int, int);
int sort_agl(const void *, const void *);
int leftmost(const void *, const void *);
float Angle(int);

int main() {
	int N, ans = 0;
	int i = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%f %f", &P[i].x, &P[i].y);

	qsort(P, N, sizeof(Dot), leftmost);

	for (int i = 0; i < N; i++) {
		P[i].angle = Angle(i);
	}

	qsort(P, N, sizeof(Dot), sort_agl);
	Push(P[0]), Push(P[1]), Push(P[2]);

	for (i = 3; i <= N; ++i) {
		while (cwccw(top - 1, top, i) <= 0) {
			Pop();
		}Push(P[i]);
	}

	for (int i = 0; i < N; i++) {
		if (!S[i].x)
			break;
		ans++;
	}
	printf("%d", ans);

	return 0;
}

int sort_agl(const void *v1, const void *v2) {
	return  ((Dot*)v1)->angle - ((Dot*)v2)->angle;
}

int leftmost(const void *v1, const void *v2) {
	return  ((Dot*)v1)->y + ((Dot*)v1)->x - ((Dot*)v2)->x + ((Dot*)v2)->y;
}

int cwccw(int i, int j, int k) {
	int temp = P[i].x * P[j].y + P[j].x * P[k].y + P[k].x * P[i].y;
	temp = temp - P[i].y * P[j].x - P[j].y * P[k].x - P[k].y * P[i].x;

	if (temp > 0)
		return 1;
	else if (temp < 0)
		return -1;
	else
		return 0;
}

float Angle(int B) {
	double Dx, Dy;
	Dx = P[B].x - P[0].x;
	Dy = P[B].y - P[0].y;

	return atan(Dy / Dx)*(180.0 / M_PI);
}

void Push(Dot p) {
	S[++top] = p;
}

void Pop() {
	top--;
}