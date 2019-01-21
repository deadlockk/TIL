/**
@file DFSBFS.cpp
@brief print DFSBFS.cpp file
@author Sang-won
@return none
@remark none
@version none
@code
this is very important code sector.
@endcode
*/
#pragma warning(disable:4996)
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

void dfs(int);
void bfs();

int visit[1005];
int V, E, S, i, a, b;

vector<int> graph[1005];
vector<int> node;

/**
* \brief Main function
* \details Print DFS, BFS of graph traversal
* \Tutor#1
* \version 0.0
* \date 2018
* \pre First initialize the system.
* \bug N/A
* \warning N/A
* \copyright Sang-won
*/
int main() {
	scanf("%d %d %d", &V, &E, &S);

	for (int i = 1; i <= E; i++) {
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1; i <= V; i++)
		sort(graph[i].begin(), graph[i].end());

	dfs(S);
	for (int i = 0; i < node.size(); i++)
		printf("%d ", node[i]);
	printf("\n");

	for (int i = 1; i <= V; i++)
		visit[i] = 0;
	node.clear();

	bfs();
	for (int i = 0; i < node.size(); i++)
		printf("%d ", node[i]);
	printf("\n");
}
/**
* \brief DFS Graph traversal
* \details Make DFS traversal
* \author Main Tutor
* \version 0.0
* \date 2018
* \pre First initialize the system.
* \bug N/A
* \warning N/A
* \copyright Sang-won
*/
void dfs(int x) {
	if (visit[x] == 0) {
		visit[x] = 1;

		node.push_back(x);
		for (int i = 0; i < graph[x].size(); i++)
			dfs(graph[x][i]);
	}
}
/**
* \brief BFS Graph traversal
* \details Make BFS traversal
* \author Main Tutor
* \version 0.0
* \date 2018
* \pre First initialize the system.
* \bug N/A
* \warning N/A
* \copyright Sang-won
*/
void bfs() {		
	
	queue<int> q;
	q.push(S);

	while (!q.empty()) {
		int y = q.front();
		q.pop();

		if (visit[y] == 0) {
			visit[y] = 1;

			node.push_back(y);
			for (int i = 0; i < graph[y].size(); i++)
				q.push(graph[y][i]);
		}
	}
}
