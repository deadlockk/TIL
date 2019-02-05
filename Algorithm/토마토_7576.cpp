#include <iostream>
#include <ios>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> p;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	vector<vector<int>> tomato;
	vector<vector<int>> visit;
	vector<int> it;

	int M, N, input, level = 1;
	int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };

	cin >> M >> N;

	tomato.resize(N);
	visit.resize(N);

	for (int i = 0; i < N; i++) //입력
		for (int j = 0; j < M; j++) {
			cin >> input;
			tomato[i].push_back(input);
			if (tomato[i][j] == 0)
				visit[i].push_back(0);
			else if (tomato[i][j] == 1)
				visit[i].push_back(1);
			else
				visit[i].push_back(-1);
		}

	queue <p> q;
	for (int i = 0; i < N; i++)//익은 토마토 push 
		for (int j = 0; j < M; j++) {
			if (visit[i][j] == 1)
				q.push({ i,j });
		}

	while (!q.empty()) {
		int sz = q.size();
		level++;
		for (int i = 0; i < sz; i++) {
			int x = q.front().first, y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dir[i][0], ny = y + dir[i][1];
				if (nx < 0 || ny < 0 || nx >= N || ny >= M || visit[nx][ny])
					continue;
				q.push({ nx,ny });
				visit[nx][ny] = level;
			}
		}
	}
	for (int i = 0; i < N; i++)//익은 토마토 push 
		for (int j = 0; j < M; j++) {
			if (visit[i][j] == 0) {
				cout << -1;
				return 0;
			}
		}

	cout << level - 2;
	return 0;
}