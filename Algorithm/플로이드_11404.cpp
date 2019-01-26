#include<cstdio>
#include<algorithm>

using namespace std;

int dist[101][101];

int main() {
	
	int a, b, c;
	int N, M;
	int INF = 100001;
	scanf_s("%d", &N);//도시의 개수

	//그래프 초기화
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i != j)
				dist[i][j] = INF;
		}
	}
	scanf_s("%d", &M);//버스의 개수

	//그래프 생성
	for (int i = 1; i <= M; i++) {
		scanf_s("%d %d %d", &a, &b, &c);
		if (dist[a][b] > c)
			dist[a][b] = c;
	}

	//플로이드워셜 알고리즘
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	//출력
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (dist[i][j] == INF)
				printf("0 ");
			else
				printf("%d ", dist[i][j]);
		}
		printf("\n");
	}
}
