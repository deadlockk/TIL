/*
전제조건 : 하나초과의 홀수개의 문자가 있으면 아니되오

입력을 받고
소팅을 내림차순으로 해서

알파벳 홀수개 판별

//펠린드롬이 불가한 경우
홀수 카운트에 의해서 프로그램 종료

첫번째 문자와 같은 문자가 있는지 탐색
1. 있으면 앞에껀 맨앞으로 뒤에껀 맨뒤로

두번째 문자와 같은 문자가 있는지 탐색
1.있으면 앞에껀 맨 앞으로 뒤에껀 맨뒤로

//펠린드롬이 가능한 경우
일련의 과정 이후 짝이 다 맞으면 종료

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
