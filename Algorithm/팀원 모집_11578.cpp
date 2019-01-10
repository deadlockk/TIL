#include <cstdio>
#include <iostream>

using namespace std;

void search(int);
int question[11];
int personCnt, result = 1e9, madeTeam = 0;
int N, M, O, solvable;
int P[11][11];

int main() {	
	
	ios::sync_with_stdio(false);
	cin >> N >> M;

	//Ç® ¼ö ÀÖ´Â ¹®Á¦¿¡ 1
	for (auto i = 1; i <= M; i++) {
		cin >> O;
		for (auto j = 0; j < O; j++) {
			cin >> solvable;
			P[i][solvable] = 1;
		}
	}

	for (int i = 1; i <= N; i++) {
		personCnt = 0;
		for (int j = 0; j <= N; j++)
			question[j] = 0;
		search(i);
	}

	if (madeTeam) {
		cout << result << "\n";
	}
	else {
		cout << -1 << "\n";
	}
	return 0;
}

void search(int a) {
	personCnt++;
	for (int i = 1; i <= N; i++) {
		if (P[a][i] == 1)
			question[i]++;
	}

	bool all = true;
	for (int i = 1; i <= N; i++) {
		if (question[i] == 0) {
			all = false;
			break;
		}
	}

	if (all) {
		madeTeam = 1;
		if (result > personCnt)
			result = personCnt;
	}
	else {
		for (int i = a + 1; i <= M; i++) {
			search(i);
		}
	}
	personCnt--;
	for (auto i = 1; i <= N; i++) {
		if (P[a][i] == 1) {
			question[i]--;
		}
	}
}
