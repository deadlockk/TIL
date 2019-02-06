#include <iostream>
#include <ios>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	int N, Kim, Lim,tmp,chk=0,answer=0;
	
	cin >> N >> Kim >> Lim;
	tmp = N/2;
	for (int i = 0; i < tmp+1; i++) {
		answer++;
		
		if (Kim % 2 == 0) {
			if (Lim == Kim - 1)
				break;
		}
		if (Lim % 2 == 0) {
			if (Kim == Lim - 1)
				break;
		}
		
		if (Kim % 2 == 0)
			Kim = Kim / 2;
		else if (Kim % 2 == 1)
			Kim = (Kim + 1) / 2;
		if (Lim % 2 == 0)
			Lim = Lim  / 2;
		else if (Lim % 2 == 1)
			Lim = (Lim + 1) / 2;
		
	}

	cout << answer;
	return 0;
}
