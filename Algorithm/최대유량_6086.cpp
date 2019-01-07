#pragma warning (disable:4996)
#include <cstdio>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>
#include <vector>
#include <iostream>

#define INF 1e9
#define S 0//A
#define E 25//Z
#define MAX_A 55

using namespace std;

int N,c;
char a,b;
int level[MAX_A];
int work[MAX_A];

bool bfs();
int dfs(int, int);

struct Edge {
	int v, cap, rev;
	Edge(int v, int cap, int rev) :v(v), cap(cap), rev(rev) {}
};
vector<vector<Edge>> vt;

int main() {
	scanf("%d", &N);
	vt.resize(MAX_A);
	for (int i = 0; i < N; i++) {
		scanf(" %c %c %d", &a, &b, &c);
		
		int x, y;
		if ('A' <= a && a <= 'Z')
			x = a - 'A';
		else
			x = a - 'a' + 26;
		if ('A' <= b && b <= 'Z')
			y = b - 'A';
		else
			y = b - 'a' + 26;
		
		vt[x].emplace_back(y, c, (int)vt[y].size());
		vt[y].emplace_back(x, 0, (int)vt[x].size() - 1);
	}
	
	int res = 0;
	while (bfs()) {//level graph 생성될때만
		memset(work, 0, sizeof(work));
		while (1) {
			int flow = dfs(S, INF);//blocking flow
			if (!flow)break;
			res += flow;    //차단유량이 1이상일 경우 maximum flow에 더해줌
		}
	}
	printf("%d", res);
	return 0;
}

bool bfs() {
	memset(level, -1, sizeof(level));
	queue<int> q;
	level[S] = 0;
	q.push(S);
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		for (auto i : vt[here]) {
			int there = i.v;
			int cap = i.cap;
			if (level[there] == -1 && cap > 0) {    //레벨이 아직 정해지지 않았고 잔여용량이 0이상
				level[there] = level[here] + 1;    //현재의 레벨값+1을 할당해준다.
				q.push(there);
			}
		}
	}
	return level[E] != -1;    //E는 싱크를 의미한다. 싱크의 레벨이 할당이 안된 경우 0을 리턴
}

int dfs(int here, int crtcap) {
	if (here == E)return crtcap;        //싱크일 경우 현재 흐르는 유량을 return 
	for (int &i = work[here]; i < vt[here].size(); i++) {    //work 배열에는 다음 탐색 위치가 저장되어 있다.
		int there = vt[here][i].v;
		int cap = vt[here][i].cap;
		if (level[here] + 1 == level[there] && cap>0) {    //레벨 그래프가 1만큼 크고 잔여 용량이 0 이상인 간선
			int c = dfs(there, min(crtcap, cap));        //dfs로 다음 위치 탐색
			if (c> 0) {        //싱크까지 도달하여 흐르는 차단유량이 0 이상일 경우 
				vt[here][i].cap -= c;    //현재 용량에서 차단 유량만큼을 빼줌
				vt[there][vt[here][i].rev].cap += c;    //역방향 간선에 c만큼 용량을 추가해줌
				return c;
			}
		}
	}
	return 0;
}
