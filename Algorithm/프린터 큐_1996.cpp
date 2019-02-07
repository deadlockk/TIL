#include <iostream>
#include <ios>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> p;

int main() {
	
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int T, N, M, priority, answer = 0;
	vector<int> printer;
	cin >> T;
	
	for(int i=0;i<T;i++) {
		queue<p> q;
		answer = 0;
		printer.clear();
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			cin >> priority;
			printer.push_back(priority);
			if (i == M)
				q.push({ priority,1 });
			else
				q.push({ priority,0 });
		}
		
		sort(printer.begin(), printer.end());
		
		while (!q.empty()) {
			if (printer.back() == q.front().first) {
				answer++;
				if (q.front().second==1) {

					cout << answer<< "\n";
					break;
				}
				q.pop();
				printer.pop_back();
			}
			else {
				int x = q.front().first; int y = q.front().second;
				q.pop();
				q.push({ x,y });
			}
		}
	}
	return 0;

}
