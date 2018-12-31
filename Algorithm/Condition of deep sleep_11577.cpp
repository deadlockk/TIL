#include<iostream>

using namespace std;

int N, K;
int ret = 0;
int S[100005];

bool check() {
	for (auto i = 0; i < N; i++) {
		if (S[i] == 1)
			return false;
	}
	return true;
}

void turnoff() {
	int one_cnt = 0,flag=0,lastFlag;

	for (auto i = 0; i < N; i++) {
		if (S[i] == 1) {
			one_cnt++;
			flag = i;
		}
		if (one_cnt == K&&flag-1 == lastFlag) {
			one_cnt = 0;
			for (auto change = i; change > i - K; change--) {
				S[change] = 0;
			}
			ret++;
		}
		lastFlag = flag;
	}
}
void turnon() {
	int zero_cnt = 0, flag = 0, lastFlag;

	for (auto i = 0; i < N; i++) {
		if (S[i] == 0) {
			zero_cnt++;
			flag = i;
		}
		if (zero_cnt == K && flag - 1 == lastFlag) {
			zero_cnt = 0;
			for (auto change = i; change > i - K; change--) {
				S[change] = 1;
			}
			ret++;
		}
		lastFlag = flag;
	}
}
int sleep() {
	turnoff();
	if (check()) {
		return ret;
	}
	else {
		turnon();
		turnoff();
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> N;
	cin >> K;
	int zero = 0, one = 0;
	for (auto i = 0; i < N; i++) {
		cin >> S[i];
		if (S[i] == 0)
			zero++;
		else
			one++;
	}
	if (zero%K != 0 && one%K != 0)
		cout << "Insomnia";
	else
		cout << sleep();
	return 0;
}
