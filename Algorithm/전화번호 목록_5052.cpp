#pragma warning (disable:4996)
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
	
	int test;
	scanf("%d", &test);

	while (test--)
	{
		int n;
		scanf("%d", &n);

		string str[10001];
		map<string, bool> mp;

		for (int i = 0; i < n; i++)
		{
			char tmp[12];
			scanf("%s", tmp);
			str[i] = tmp;
		}
		sort(str, str + n);

		mp[str[0]] = true;

		bool ans = true;
		for (int i = 1; i < n; i++)
		{
			for (int len = 1; len <= 10; len++)
			{
				if (mp[str[i].substr(0, len)])
				{
					ans = false;
					break;
				}
			}
			mp[str[i]] = true;
		}

		if (ans)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
