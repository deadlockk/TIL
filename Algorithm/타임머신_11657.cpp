#include<cstdio>
#include<algorithm>

using namespace std;

int graph[500][500];

int main() {
	int a, b, c;
	int N, M;
	int INF = 10001;
	scanf_s("%d", &N);//������ ����
	scanf_s("%d", &M);//������ ����

	//�׷��� ����
	for (int i = 1; i <= M; i++) {
		scanf_s("%d %d %d", &a, &b, &c);
		graph[a][b] = c;
	}

}