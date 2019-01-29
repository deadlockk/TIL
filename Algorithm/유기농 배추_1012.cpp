#include <iostream>
#include <ios>
#include<vector>
#include<queue>
#include<string.h>

using namespace std;
typedef pair <int, int> p;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T, M, N, K, X, Y;
	int visit[51][51];
	int cabbage[51][51];

	int dir[4][2] = { { 1,0 },{ 0,1 },{ -1,0 },{ 0,-1 } };

	int earthworm;

	cin >> T;
	while (T--) {
		memset(visit, 0, sizeof(visit));
		memset(cabbage, 0, sizeof(cabbage));
		earthworm = 0;

		cin >> M >> N >> K;
	
		while (K--) {
			cin >> X >> Y;
			cabbage[X][Y] = 1;
		}

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (!visit[i][j] && cabbage[i][j] == 1) {
					queue <p> q;

					earthworm++;
					q.push({ i,j });
					visit[i][j] = 1;
					while (!q.empty()) {
						int x = q.front().first, y = q.front().second;
						q.pop();
						
						for (int i = 0; i < 4; i++) {
							int nx = x + dir[i][0], ny = y + dir[i][1];
							if (nx < 0 || ny < 0 || nx >= M || ny >= N || visit[nx][ny] || cabbage[nx][ny] == 0)
								continue;
							q.push({ nx,ny });
							visit[nx][ny] = 1;
						}
					}
				}
			}
		}
		cout << earthworm << "\n";
	}
	return 0;
}
