#include<stdio.h>
#include<string.h>

char name[50];
char tmp[3];
int num = 0;
void swap(int, int);

int main() {

	int i = 0, j = 0;
	int a = 0;
	int cnt = 0;
	char check;

	gets_s(name);
	while (name[a]) {
		num++;
		a++;
	}
	/*
	�������� : �ϳ��ʰ��� Ȧ������ ���ڰ� ������ �ƴϵǿ�

	�Է��� �ް�
	ù��° ���ڿ� ���� ���ڰ� �ִ��� Ž��//
	1. ������ �տ��� �Ǿ����� �ڿ��� �ǵڷ�
	2. ������ �ι�° ���ڷ� �Ѿ��(Ȧ�� ī��Ʈ +1)

	�ι�° ���ڿ� ���� ���ڰ� �ִ��� Ž��
	1.������ �տ��� �� ������ �ڿ��� �ǵڷ�
	2. �� ������ (Ȧ�� ī��Ʈ 2�̹Ƿ� ����)

	//�縰����� ������ ���
	�Ϸ��� ���� ���� ¦�� �� ������ ����
	�ϳ��� ���ڰ� ������ ��ü ��Ʈ�� ũ���� ���ݿ� �ش��ϴ�
	�ڸ��� ���� ���� ����ֱ�

	//�縰����� �Ұ��� ���
	Ž���� Ȧ�� ī��Ʈ�� ���ؼ� ���α׷� ����

	*/
	while (name[i]) {
		check = name[i];
		j = i + 1;
		while (name[j]) {
			if (check == name[j]) {
				swap(i, j);
				break;
			}
			if (cnt > 1) {
				printf("\nI'm Sorry Hansoo");
				return 0;
			}
			j++;
			if (num == j)
				cnt++;
		}
		i++;
	}
	//���� ���� ������ ����� �ű��
	puts(name);
	return 0;
}

void swap(int i, int j) {
	memset(tmp, 0, 3);
	tmp[0] = name[0];
	name[0] = name[i];
	name[i] = tmp[0];
	tmp[num - 1] = name[num - 1];
	name[num - 1] = name[j];
	name[j] = tmp[num - 1];
}