#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	//����ʮ��������ת����Ľ���
	int a, base;
	scanf("%d%d", &a, &base);

	if (a == 0) { puts("Yes"); printf("0"); return 0; }

	//ת���ɶ�Ӧ���Ʋ���������
	int z[40]; int i;
	for (i = 0; a != 0; a /= base, i++)
		z[i] = a % base;

	//���������ж��Ƿ�Ϊ���������������鵹�����
	bool flag = true;
	for (int j = i - 1; j >=0 ; j--)
		if (z[j] != z[i - 1 - j])
		{
			flag = false; break;
		}
	if (flag) printf("Yes\n");
	else      printf("No\n");
	for (int j = i - 1; j >= 0; j--)
	{
		if (j != i - 1) putchar(' ');
		printf("%d", z[j]);
	}
	return 0;
}