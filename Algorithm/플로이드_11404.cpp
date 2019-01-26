#include<cstdio>
#include<algorithm>

using namespace std;

int dist[101][101];

int main() {
	int a, b, c;
	int N, M;
	int INF = 100001;
	scanf_s("%d", &N);//������ ����

	//�׷��� �ʱ�ȭ
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i != j)
				dist[i][j] = INF;
		}
	}
	scanf_s("%d", &M);//������ ����

	//�׷��� ����
	for (int i = 1; i <= M; i++) {
		scanf_s("%d %d %d", &a, &b, &c);
		if (dist[a][b] > c)
			dist[a][b] = c;
	}

	//�÷��̵���� �˰���
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	//���
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