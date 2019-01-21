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
	전제조건 : 하나초과의 홀수개의 문자가 있으면 아니되오

	입력을 받고
	첫번째 문자와 같은 문자가 있는지 탐색//
	1. 있으면 앞에껀 맨앞으로 뒤에껀 맨뒤로
	2. 없으면 두번째 문자로 넘어가기(홀수 카운트 +1)

	두번째 문자와 같은 문자가 있는지 탐색
	1.있으면 앞에껀 맨 앞으로 뒤에껀 맨뒤로
	2. 또 없으면 (홀수 카운트 2이므로 종료)

	//펠린드롬이 가능한 경우
	일련의 과정 이후 짝이 다 맞으면 종료
	하나의 문자가 남으면 전체 스트링 크기의 절반에 해당하는
	자리에 남는 문자 집어넣기

	//펠린드롬이 불가한 경우
	탐색중 홀수 카운트에 의해서 프로그램 종료

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
	//남는 문자 있으면 가운데로 옮기기
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
