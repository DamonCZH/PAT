#include<cstdio>
#include<string>
#include<cstring>
using namespace std;

int main()
{
	//�����ֽ������룬ǰ�벿�ֱ���Ϊ�ַ�����ָ�����ֱ���Ϊ����
	char str[10000], c; int n = 0;
	for (int i = 0;; i++)
	{
		c = getchar();
		if (c == 'E')
			break;
		else
		{
			str[i] = c;
			n++;
		}
	}

	double a; sscanf(str, "%lf", &a);
	if (a == 0.0)
	{
		putchar('0');
		return 0;
	}

	int exp;
	scanf("%d", &exp);

	//��������֣��ؼ�����ȷ����������С�����λ��
	//������������ţ������������
	if (str[0] == '-') putchar('-');

	//ָ��Ϊ����С�������ƣ�������Χ���0
	if (exp < 0)
	{
		//���ǰ���0�������ڵ�һλ�����С����
		for (int i = 0; i < -exp; i++)
		{
			putchar('0');
			if (i == 0) putchar('.');
		}
		//���ԭ�������г�ȥС�����λ��
		for (int i = 1; i < n; i++)
		{
			if (str[i] != '.') putchar(str[i]);
		}
	}
	//ָ��Ϊ����С�������ƣ�������Χ���0
	else
	{
		//���ָ�����ڵ��ڴ�����-3������Ҫ��С����
		if (exp >= n - 3)
		{
			for (int i = 1; i < n; i++)
				if (str[i] != '.') putchar(str[i]);
			for (int i = 0; i < exp - n + 3; i++)
				putchar('0');
		}
		//���ָ��С�ڴ�����-3������Ҫ��С����
		else
		{
			putchar(str[1]);
			for (int i = 3; i < n; i++)
			{
				if (i == exp + 3) putchar('.');
				putchar(str[i]);
			}
		}
	}

	return 0;
}