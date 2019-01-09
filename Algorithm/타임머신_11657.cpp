#include<cstdio>
#include<algorithm>

using namespace std;

int graph[500][500];

int main() {
	int a, b, c;
	int N, M;
	int INF = 10001;
	scanf_s("%d", &N);//도시의 개수
	scanf_s("%d", &M);//버스의 개수

	//그래프 생성
	for (int i = 1; i <= M; i++) {
		scanf_s("%d %d %d", &a, &b, &c);
		graph[a][b] = c;
	}

}