#include <iostream>
#include <ios>
#include <queue>
#include<algorithm>
#include<string.h>

using namespace std;

typedef pair<int, int> p;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	char house[28][28];
	int visit[28][28];

	fill(&visit[0][0], &visit[27][27], 1);
	memset(house, 0, sizeof(house));

	vector<int> answer;
	int N;
	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> house[i][j];
			if (house[i][j] == '1') {
				visit[i][j] = 0;
			}
		}
	}
	
	queue<p> q;
	int housesNum = 0;
	int sum = 0;

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			if (visit[i][j] == 0) {
				q.push({ i,j });
				visit[i][j] = 1;
			}
			else continue;

			while (!q.empty()) {
				int a = q.front().first;
				int b = q.front().second;
				q.pop();
				sum++;
				if (house[a][b + 1] == '1') {//µ¿
					if (visit[a][b + 1] == 0) {
						visit[a][b + 1] = 1;
						q.push({ a,b + 1 });
					}
				}
				if (house[a][b - 1] == '1') {//¼­
					if (visit[a][b - 1] == 0) {
						visit[a][b - 1] = 1;
						q.push({ a,b - 1 });
					}
				}
				if (house[a + 1][b] == '1') {//³²
					if (visit[a + 1][b] == 0) {
						visit[a + 1][b] = 1;
						q.push({ a + 1,b });
					}
				}
				if (house[a - 1][b] == '1') {//ºÏ
					if (visit[a - 1][b] == 0) {
						visit[a - 1][b] = 1;
						q.push({ a - 1,b });
					}
				}
			}
			housesNum++;
			answer.push_back(sum);
			sum = 0;
		}
	}
	
	cout << housesNum<<"\n";
	sort(answer.begin(),answer.end());
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << "\n";
	}
		
	return 0;
}
