#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	//录入字符串
	char a[85];
	scanf("%s", a);

	//计算行数列数
	int n = strlen(a);
	int row, col;

	row = (n + 2) / 3;
	if ((n + 2) % 3 == 0)
		col = row;
	else if ((n + 2) % 3 == 1)
		col = row + 1;
	else
		col = row + 2;

	//循环输出字符，中间加入定量的空格
	for (int i = 0; i < row - 1; i++)
	{
		putchar(a[i]);
		for (int j = 0; j < col - 2; j++)
			putchar(' ');
		putchar(a[n-i-1]);
		putchar('\n');
	}
	for (int i = row - 1; i < row - 1 + col; i++)
		putchar(a[i]);

	return 0;
}