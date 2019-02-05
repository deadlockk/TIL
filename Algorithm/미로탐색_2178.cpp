#include <ios>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

typedef pair<int, int> p;

int main() {	
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int N, M,check=0;
	int visit[101][101] = { 0, };
	char maze[101][101];
	int dir[4][2] = { { 1,0 },{ 0,1 },{ -1,0 },{ 0,-1 } };

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> maze[i][j];
			if (maze[i][j] == '0')
				visit[i][j] = 1;
		}

	queue<p> q;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visit[i][j] == 0) {
				q.push({ i,j });
				check++;
				visit[i][j] = check;
			}
			else continue;

			while (!q.empty()) {
				int a = q.front().first;
				int b = q.front().second;
				q.pop();
				
				check = visit[a][b] + 1;
				for (int k = 0; k < 4; k++) {
					int nx = a + dir[k][0], ny = b + dir[k][1];
					if (nx < 0 || ny < 0 || nx >= N || ny >= M || visit[nx][ny])
						continue;
					q.push({ nx,ny });
					visit[nx][ny] = check;
				}
			}

		}
	}
	cout << visit[N-1][M-1];
	return 0;
}
