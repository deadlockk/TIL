#include <iostream>
#include <ios>
#include <queue>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	queue<int> card;
	queue<int> answer;

	int N, x, y;
	cin >> N;
	for (int i = 1; i <= N; i++)
		card.push(i);

	while (true) {
		if (card.size() == 1)
			break;
		x = card.front();
		answer.push(x);
		card.pop();
		x = card.front();
		card.pop();
		answer.push(x);
		card.push(x);
	}
	x = card.front();
	cout << x;
	return 0;
}