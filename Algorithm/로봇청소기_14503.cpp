#pragma warning(disable:4996)
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

void cleaning(int, int, int);
void clearQueue();
int map[55][55];
int result = 0;
queue<int> q;

int main() {
	int N, M, d, r, c;
	scanf("%d %d", &N, &M);

	scanf("%d %d %d", &r, &c, &d);

	for (auto i = 1; i < N+1; i++) {
		for (auto j = 1; j < M+1; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	if (map[r][c] == 0) {
		result++;
		map[r][c] = 2;
	}

	cleaning(r, c, d);

	printf("%d", result);
	return 0;
}

void clearQueue() {
	queue<int> empty;
	swap(q, empty);
}

void cleaning(int r, int c, int d) {
	if (q.size() == 4) {
		if (d == 0) {
			if (map[r + 1][c] == 1)
				return;
			else {
				q.pop(); q.pop(); q.pop(); q.pop();

				cleaning(r + 1, c , 3);
			}
		}
		else if (d == 1) {
			if (map[r][c - 1] == 1)
				return;
			else {
				q.pop(); q.pop(); q.pop(); q.pop();

				cleaning(r , c - 1, 0);
			}
		}
		else if (d == 2) {
			if (map[r - 1][c] == 1)
				return;
			else {
				q.pop(); q.pop(); q.pop(); q.pop();

				cleaning(r - 1, c , 1);
			}
		}
		else {
			if (map[r][c + 1] == 1)
				return;
			else {
				q.pop(); q.pop(); q.pop(); q.pop();

				cleaning(r , c + 1, 2);
			}
		}
	}

	if (d == 0) {
		if (map[r][c - 1] == 0) {
			result++;
			map[r][c - 1] = 2;
			clearQueue();
			cleaning(r, c - 1, 3);
		}
		else {
			q.push(3);
			cleaning(r, c, 3);
		}
	}
	else if (d == 1) {
		if (map[r - 1][c] == 0) {
			result++;
			map[r - 1][c] = 2;
			clearQueue();
			cleaning(r - 1, c, 0);
		}
		else {
			q.push(0);
			cleaning(r , c, 0);
		}
	}
	else if (d == 2) {
		if (map[r][c + 1] == 0) {
			result++;
			map[r][c + 1] = 2;
			clearQueue();
			cleaning(r, c + 1, 1);
		}
		else {
			q.push(1);
			cleaning(r, c, 1);
		}

	}
	else {
		if (map[r + 1][c] == 0) {
			result++;
			map[r + 1][c] = 2;
			clearQueue();
			cleaning(r + 1, c, 2);
		}
		else {
			q.push(2);
			cleaning(r, c, 2);
		}
	}

}