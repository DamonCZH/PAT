#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	//¼���ַ���
	char a[85];
	scanf("%s", a);

	//������������
	int n = strlen(a);
	int row, col;

	row = (n + 2) / 3;
	if ((n + 2) % 3 == 0)
		col = row;
	else if ((n + 2) % 3 == 1)
		col = row + 1;
	else
		col = row + 2;

	//ѭ������ַ����м���붨���Ŀո�
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