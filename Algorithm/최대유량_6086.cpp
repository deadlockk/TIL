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
	while (bfs()) {//level graph �����ɶ���
		memset(work, 0, sizeof(work));
		while (1) {
			int flow = dfs(S, INF);//blocking flow
			if (!flow)break;
			res += flow;    //���������� 1�̻��� ��� maximum flow�� ������
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
			if (level[there] == -1 && cap > 0) {    //������ ���� �������� �ʾҰ� �ܿ��뷮�� 0�̻�
				level[there] = level[here] + 1;    //������ ������+1�� �Ҵ����ش�.
				q.push(there);
			}
		}
	}
	return level[E] != -1;    //E�� ��ũ�� �ǹ��Ѵ�. ��ũ�� ������ �Ҵ��� �ȵ� ��� 0�� ����
}

int dfs(int here, int crtcap) {
	if (here == E)return crtcap;        //��ũ�� ��� ���� �帣�� ������ return 
	for (int &i = work[here]; i < vt[here].size(); i++) {    //work �迭���� ���� Ž�� ��ġ�� ����Ǿ� �ִ�.
		int there = vt[here][i].v;
		int cap = vt[here][i].cap;
		if (level[here] + 1 == level[there] && cap>0) {    //���� �׷����� 1��ŭ ũ�� �ܿ� �뷮�� 0 �̻��� ����
			int c = dfs(there, min(crtcap, cap));        //dfs�� ���� ��ġ Ž��
			if (c> 0) {        //��ũ���� �����Ͽ� �帣�� ���������� 0 �̻��� ��� 
				vt[here][i].cap -= c;    //���� �뷮���� ���� ������ŭ�� ����
				vt[there][vt[here][i].rev].cap += c;    //������ ������ c��ŭ �뷮�� �߰�����
				return c;
			}
		}
	}
	return 0;
}