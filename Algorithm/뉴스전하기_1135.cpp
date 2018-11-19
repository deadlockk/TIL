#pragma warning(disable:4996)
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>

using namespace std;

vector<int> v[55];
int dfs(int);
int boss[55];
int N = 0;

int main() {
	scanf("%d", &N);
	boss[100];
	for (auto i = 0; i < N; i++) {
		scanf("%d", &boss[i]);
		if (boss[i] != -1)
			v[boss[i]].push_back(i);
	}

	printf("%d\n", dfs(0));
	return 0;
}

int dfs(int employee) {
	int ret = 0;
	
	//size�� ���ӻ�翡 �����ִ� ���� ��
	int size = v[employee].size();

	if (size == 0) return 0;

	//���� ������ ���� ����Ʈ
	int* list = new int[size + 1];

	for (int i = 0; i < size; i++) {
		list[i] = dfs(v[employee][i]);
	}

	//list[0]���� list[size-1]���� �������� ����
	sort(list, list + size, greater<int>());

	//���� ������ ���� ����Ʈ���� �ɸ��� ��ȭ�ð��� ���� update��Ų��
	for (int i = 0; i < size; i++) {
		if (ret < list[i] + (i + 1))
			ret = list[i] + (i + 1);
	}
	//free
	delete[] list;

	return ret;
}