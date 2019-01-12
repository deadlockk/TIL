#pragma warning (disable:4996)
#include<stdio.h>

int arr[2005];
int dp[2005][2005];

int main() {
	int N,j,M;

	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}
	//자기 자신을 항상 펠린드롬
	for (int i = 1; i <= N; i++) {
		dp[i][i] = 1;
	}
	//자신과 자신보다 한칸 뒤에 있는 것이 같으면 펠린드롬
	for (int i = 1; i <= N - 1; i++) {
		if (arr[i] == arr[i + 1])
			dp[i][i + 1] = 1;
	}

	for (int k = 2; k <= N - 1; k++) {
		for (int i = 1; i <= N - k; i++) {
			j = i + k;
			//start와 end가 같은지 확인하고 그 중간에 있는 값들이 펠린드롬인지 확인한다
			if (arr[i] == arr[j] && dp[i + 1][j - 1])
				dp[i][j] = 1;
		}
	}

	scanf("%d", &M);
	
	for (int i = 0; i < M; i++) {
		int S, E;
		scanf("%d %d", &S, &E);

		if (dp[S][E] == 1)
			printf("1\n");
		else
			printf("0\n");
	}

	return 0;
}
