#include<cstdio>

const char *s = "0123456789ABC";

void print(int x)
{
	//将十进制转换成十三进制
	char z[2]; z[0] = z[1] = '0';
	for (int i=0; x != 0; x /= 13, i++)
	{
		z[i] = s[x % 13];
	}
	printf("%c%c", z[1], z[0]);
}

int main()
{
	//输入三个十进制数字
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);

	//将十三进制数打印输出
	putchar('#');
	print(a); print(b); print(c);
	return 0;
}