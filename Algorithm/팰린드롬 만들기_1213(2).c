/*
�������� : �ϳ��ʰ��� Ȧ������ ���ڰ� ������ �ƴϵǿ�

�Է��� �ް�
������ ������������ �ؼ�

���ĺ� Ȧ���� �Ǻ�

//�縰����� �Ұ��� ���
Ȧ�� ī��Ʈ�� ���ؼ� ���α׷� ����

ù��° ���ڿ� ���� ���ڰ� �ִ��� Ž��
1. ������ �տ��� �Ǿ����� �ڿ��� �ǵڷ�

�ι�° ���ڿ� ���� ���ڰ� �ִ��� Ž��
1.������ �տ��� �� ������ �ڿ��� �ǵڷ�

//�縰����� ������ ���
�Ϸ��� ���� ���� ¦�� �� ������ ����


*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char name[50];
char tmp[3];
int num = 0;
void swap(int, int);

int compare(const void *a, const void *b);

int main() {

	int i = 0, j = 0;
	int a = 0;
	int b = 0;
	int k = 0;
	int odd = 0;
	int cnt = 0;
	char check = '\0';

	gets(name);
	while (name[a]) {
		num++;
		a++;
	}

	qsort(name, num, sizeof(name[0]), compare);

	while (name[k]) {
		b = k;
		odd = 0;
		check = name[k];
		while (name[b]) {
			if (check == name[b])
				odd++;
			else {
				k = b;
				break;
			}
			b++;
		}
		if (odd % 2 != 0)
			cnt++;

		if (b == num)
			break;
	}

	if (cnt > 1) {
		printf("I'm Sorry Hansoo");
		return 0;
	}

	check = '\0';

	while (name[i]) {
		if (cnt == 1) {
			if (i > num / 2)
				break;
		}
		else {
			if (i >= num / 2)
				break;
		}
		if (check == name[i] && check != name[i + 1]) {
			i++;
			continue;
		}
		check = name[i];
		j = i + 1;

		while (name[j]) {

			if (check == name[j]) {
				swap(i, j);
				break;
			}
			j++;
		}
		i++;
	}
	puts(name);
	return 0;
}

void swap(int i, int j) {
	int a = 0, b = 0;
	memset(tmp, 0, 3);
	a = i;
	b = j;
	tmp[0] = name[i];
	while (a >= 1) {
		name[a] = name[a - 1];
		a--;
	}
	name[0] = tmp[0];
	tmp[1] = name[j];
	while (b <= num - 2) {
		name[b] = name[b + 1];
		b++;
	}
	name[num - 1] = tmp[1];
}

int compare(const void *a, const void *b) {
	return strcmp((char*)b, (char*)a);
}