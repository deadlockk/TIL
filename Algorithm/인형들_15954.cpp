#include <iostream>
#include <ios>
#include<math.h>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int temp[500];
	int N, K= 0;

	double ans = 1e9;
	double distribute = 0.0;
	double standard_deviation = 0.0;
	
	cin >> N >> K;
	for(int i=1;i<=N;i++)
		cin >> temp[i];
	
	for (int i = 0; i<=N; i++) {
		for (int j = i + K; j <= N; j++) {
			double tmp = 0.0;
			double sum = 0.0;
			int n = 0;

			for (int k = i + 1; k <= j; k++) {
				sum += temp[k];
				n++;
			}

			double m = ((double)sum) / ((double)n);
			for (int k = i + 1; k <= j; k++) 
				tmp += (temp[k] - m)*(temp[k] - m);

			distribute = (double(tmp) / (double)n);
			standard_deviation = sqrt(distribute);
			if (ans == -1 || ans > standard_deviation) {
				ans = standard_deviation;
			}
		}	
	}
	cout.precision(10);
	cout << ans;
	return 0;
}