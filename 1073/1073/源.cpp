#include<cstdio>
#include<string>
#include<cstring>
using namespace std;

int main()
{
	//对数字进行输入，前半部分保存为字符串，指数部分保存为整数
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

	//输出新数字，关键在于确定正负号与小数点的位置
	//正数不输出符号，负数输出负号
	if (str[0] == '-') putchar('-');

	//指数为负数小数点左移，超出范围添加0
	if (exp < 0)
	{
		//输出前面的0，并且在第一位后加上小数点
		for (int i = 0; i < -exp; i++)
		{
			putchar('0');
			if (i == 0) putchar('.');
		}
		//输出原来数字中除去小数点的位数
		for (int i = 1; i < n; i++)
		{
			if (str[i] != '.') putchar(str[i]);
		}
	}
	//指数为正数小数点右移，超出范围添加0
	else
	{
		//如果指数大于等于串长度-3，则不需要加小数点
		if (exp >= n - 3)
		{
			for (int i = 1; i < n; i++)
				if (str[i] != '.') putchar(str[i]);
			for (int i = 0; i < exp - n + 3; i++)
				putchar('0');
		}
		//如果指数小于串长度-3，则需要加小数点
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