#include<iostream>

using namespace std;

#define MAX 1000005

int N;
int rear = 0;
int front = 0;
int menu[MAX];
int current[MAX];

void enQueue(char item){
		rear = (rear + 1) % N;
		menu[rear] = item;
}

int main() {
	char item;
	ios::sync_with_stdio(false);
	cin >> N;
	for (auto i = 0; i < N; i++) {
		cin >> item;
		enQueue(item);
	}
	for (auto i = 0; i < N; i++) {
		cin >> current[i];
	
	}
	return 0;
}
