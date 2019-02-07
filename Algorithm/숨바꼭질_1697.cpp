#include <iostream>
#include <ios>
#include <vector>
#include <queue>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, K,answer=0,visitNum=1;
	vector<int> visit;
	queue<int> q;

	visit.resize(100011);
	cin >> N >> K;

	q.push(N);//수빈이 위치 집어 넣고
	visit[N] = visitNum;

	//bfs
	while (!q.empty()) {//여기서 수빈이 인접 다 집어 넣고
		int sz = q.size();

		visitNum++;
		for (int k = 0; k < sz; k++) {
			int y = q.front();
			if (y == K) {
				answer = visit[K];
				cout << answer-1;
				return 0;
			}
			q.pop();
			for (int i = 0; i < 3; i++) {
				
				if (i == 0 && y - 1 >= 0) {
					if (visit[y - 1] == 0) {
						q.push(y - 1);
						visit[y - 1] = visitNum ;
					}
				}
				if (i == 1 && y + 1 <= 100000) {
					if (visit[y + 1] == 0) {
						q.push(y + 1);
						visit[y + 1] = visitNum ;
					}
				}
				if (i == 2 && y * 2 <= 100000) {
					if (visit[y * 2] == 0) {
						q.push(y * 2);
						visit[y * 2] = visitNum ;
					}
				}
			}
		}
	}
}
