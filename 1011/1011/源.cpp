#include<cstdio>
using namespace std;

float g1[3], g2[3], g3[3];

int main()
{
	//������������������
	int i;
	for (i = 0; i < 3; i++)
		scanf("%f", g1 + i);
	for (i = 0; i < 3; i++)
		scanf("%f", g2 + i);
	for (i = 0; i < 3; i++)
		scanf("%f", g3 + i);

	//ɸѡ��������ʲ������������������ı������
	float max1_num = 0, max2_num = 0, max3_num = 0;
	int max1_i = 0, max2_i = 0, max3_i = 0;//����������������

	for (i = 0; i < 3; i++)
	{
		if (g1[i] > max1_num)
		{
			max1_num = g1[i];
			max1_i = i;
		}
	}
	if (max1_i == 0) putchar('W');
	else if (max1_i == 1) putchar('T');
	else putchar('L');
	putchar(' ');

	for (i = 0; i < 3; i++)
	{
		if (g2[i] > max2_num)
		{
			max2_num = g2[i];
			max2_i = i;
		}
	}
	if (max2_i == 0) putchar('W');
	else if (max2_i == 1) putchar('T');
	else putchar('L');
	putchar(' ');

	for (i = 0; i < 3; i++)
	{
		if (g3[i] > max3_num)
		{
			max3_num = g3[i];
			max3_i = i;
		}
	}
	if (max3_i == 0) putchar('W');
	else if (max3_i == 1) putchar('T');
	else putchar('L');
	putchar(' ');

	//������ջ�������
	printf("%.2f", (max1_num*max2_num*max3_num*0.65 - 1) * 2);
	return 0;
}