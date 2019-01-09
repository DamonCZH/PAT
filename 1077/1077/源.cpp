#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

char str[110][257];

int main()
{
	//录入字符串
	int n; scanf("%d", &n);
	getchar(); int minLen = 10000;
	for (int i = 0; i < n; i++)
	{
		cin.getline(str[i], 257);
		if (strlen(str[i]) < minLen)
			minLen = strlen(str[i]);
	}

	//反转字符串
	for (int i = 0; i < n; i++)
	{
		reverse(str[i], str[i] + strlen(str[i]));
	}
	//比较前缀，若有相同前缀则反向输出
	int i, j;
	for (i = 0; i < minLen; i++)
	{//对每一位
		for (j = 1; j < n; j++)
		{//对每个字符串
			if (str[j][i] != str[j - 1][i])
			{
				goto aa;
			}
		}
	}
aa:;

	if (i)
		for (j = i - 1; j >= 0; j--)
		{
			putchar(str[0][j]);
		}
	else
		printf("nai");

	return 0;
}