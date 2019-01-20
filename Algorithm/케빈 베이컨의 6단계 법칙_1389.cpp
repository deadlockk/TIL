#include <iostream>
#include <ios>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

void bfs(int);

vector<int> friends[5001];
int dist[101];
int visit[101];
int N = 0;//À¯ÀúÀÇ ¼ö
int M = 0;//Ä£±¸ °ü°èÀÇ ¼ö

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int a, b;
	int kevin_bacon = 0;
	int temp = 1e9;
	int ans[101];

	cin >> N >> M;

	for (int i = 1; i <= M; i++) {
		cin >> a >> b;
		friends[a].push_back(b);
		friends[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		for (int i = 1; i <= N; i++) {
			visit[i] = 0;
			dist[i] = 0;
		}
		bfs(i);
		kevin_bacon = 0;
		for (int j = 1; j <= N; j++) {
			kevin_bacon += dist[j];
		}
		ans[i] = kevin_bacon;
	}
	for (int i = 1; i <= N; i++) {
		temp = min(ans[i], temp);
	}
	for (int i = 1; i <= N; i++) {
		if (temp == ans[i]) {
			cout << i;
			break;
		}
	}
	return 0;
}

void bfs(int s) {
	queue<int> q;
	q.push(s);

	while (!q.empty()) {
		int y = q.front();
		q.pop();

		if (visit[y] == 0) {
			visit[y] = 1;
			for (int i = 0; i < friends[y].size(); i++) {
				q.push(friends[y][i]);
				dist[friends[y][i]] = dist[y] + 1;
			}
		}
	}

}
