#include<cstdio>

const char *s = "0123456789ABC";

void print(int x)
{
	//��ʮ����ת����ʮ������
	char z[2]; z[0] = z[1] = '0';
	for (int i=0; x != 0; x /= 13, i++)
	{
		z[i] = s[x % 13];
	}
	printf("%c%c", z[1], z[0]);
}

int main()
{
	//��������ʮ��������
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);

	//��ʮ����������ӡ���
	putchar('#');
	print(a); print(b); print(c);
	return 0;
}