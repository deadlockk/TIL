#include<stdio.h>
#define DELETE 1009
//1009�� 1000�̻��� ù��° �Ҽ�
int arr[1001];

int main() {
	int N, K;
	int x = 0;
	int num = 0;
	int location = 0;
	int P = 0;
	int check = 0;
	int min = DELETE;

	scanf_s("%d %d", &N, &K);

	for (int i = 0; i < N-1; i++) {
		arr[i] = i + 2;
	}

	while (x<N) {
		min = DELETE;
		//�Ҽ��� ã�� �� �Ҽ� ���ĺ��� �ٽ� Ž���Ѵ�
		for (int j = location; j < N-1; j++) {
			if (arr[j] < min) {
				min = arr[j];
				location = j + 1;
			}
		}
		P = min;
		for (int a = 0; a < N-1; a++) {
			if (arr[a] % P == 0) {
				//check�� ���� �������� ���ڸ� ��Ÿ����
				check = arr[a];
				arr[a] = DELETE;
				num++;
				if (num == K) {
					printf("%d", check);
					break;
				}
			}
		}
		x++;
	}
	return 0;
}