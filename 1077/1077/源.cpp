#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

char str[110][257];

int main()
{
	//¼���ַ���
	int n; scanf("%d", &n);
	getchar(); int minLen = 10000;
	for (int i = 0; i < n; i++)
	{
		cin.getline(str[i], 257);
		if (strlen(str[i]) < minLen)
			minLen = strlen(str[i]);
	}

	//��ת�ַ���
	for (int i = 0; i < n; i++)
	{
		reverse(str[i], str[i] + strlen(str[i]));
	}
	//�Ƚ�ǰ׺��������ͬǰ׺�������
	int i, j;
	for (i = 0; i < minLen; i++)
	{//��ÿһλ
		for (j = 1; j < n; j++)
		{//��ÿ���ַ���
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