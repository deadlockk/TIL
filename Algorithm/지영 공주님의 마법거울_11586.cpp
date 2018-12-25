#include<cstdio>
#pragma warning(disable:4996)

using namespace std;

int main() {
	int N;
	int sentiment;
	char mirror[101][101];
	scanf("%d", &N);
	getchar();
	for (auto i = 0; i < N; i++) {
		for (auto j = 0; j < N; j++) {
			scanf("%c", &mirror[i][j]);
		}
		getchar();
	}
	scanf("%d", &sentiment);
	if (sentiment == 1) {
		for (auto i = 0; i < N; i++) {
			for (auto j = 0; j < N; j++) {
				printf("%c", mirror[i][j]);
			}
			printf("\n");
		}
	}
	else if (sentiment == 2) {
		for (auto i = 0; i < N; i++) {
			for (auto j = N-1; j >= 0; j--) {
				printf("%c", mirror[i][j]);
			}
			printf("\n");
		}
	}
	else {
		for (auto i = N-1; i >= 0; i--) {
			for (auto j = 0; j < N; j++) {
				printf("%c", mirror[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}