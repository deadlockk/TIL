#include <iostream>
#include <ios>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int input=0;
	cin >> input;
	for(int i=1;i<=9;i++){
		
		cout << input <<" * "<<i<<" = "<<input * i<< "\n";
	}
	return 0;
}
