#include<stdio.h>
#include<stdlib.h>
#define INF 1000001

int adj[10000][10000];
int key[10000];
int n[10000];
int Q[10000];
int top = -1;
int rear = -1;

void push(int);
int pop();
int isEmpty();
void Extract_Min(int);

int main() {
	
	int V, E;
	int u, v, w;
	int vertex;
	
	scanf_s("%d %d", &V, &E);

	for (int i = 0; i < E; i++) {//인접행렬 작성
		scanf_s("%d %d %d", &u, &v, &w);
		adj[u - 1][v - 1] = w;
		adj[v - 1][u - 1] = w;
	}

	for (int j = 0; j < V; j++) {
		push(j + 1);//Q에다 박아넣기
		key[j] = INF;//key 무한대로 초기화
	}

	key[0] = 0;//source를 임의로 1로 정함

	while (isEmpty()==-1) {
		Extract_Min(V);
		vertex = pop()-1;

		for (int i = 0; i<V; i++) {
			if (adj[vertex][i]&& adj[vertex][i]<key[i]) {
				key[i] = adj[vertex][i];
				n[i] = vertex;
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < V; i++) {
		int num = n[i];
		sum += adj[num][i];
	}
	printf("%d", sum);
	return 0;
}

void Extract_Min(int V) {
	int min = key[0];
	int min_idx=0;
	int tmp;

	for (int i = 1; i < V; i++) {
		if (min > key[i]) {
			min = key[i];
			min_idx = i;
		}
	}
	if (rear > -1) {
		tmp = Q[rear];
		Q[rear] = Q[min_idx];
		Q[min_idx] = tmp;
	}
}

void push(int x) {
	Q[++top] = x;
}

int pop() {
	int num = Q[++rear];
	Q[rear] = 0;
	return num;
}

int isEmpty() {
	if (top == rear)
		return 1;
	else return -1;
}
