#include<cstdio>
#include<cstring>
using namespace std;

struct student
{
	char id[20];
	char intime[10];
	char outime[10];
}stu[100];

int main()
{
	//����ͬѧ��������ѭ��������ͬѧ�����ݣ�ʹ�ýṹ����
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s%s%s", &stu[i].id, &stu[i].intime, &stu[i].outime);
	}

	//�Խṹ�����е�Ԫ�ؽ��бȽϣ��ҳ���С����ʱ������
	//����ʱ�䣬ͬʱ��¼��ID
	int min = 0, max = 0,i;
	for (i = 0; i < n; i++)
	{
		if (strcmp(stu[i].intime,stu[min].intime)<0)
			min = i;
		if (strcmp(stu[i].outime,stu[max].outime)>0)
			max = i;
	}

	//����λͬѧ��ID�������
	printf("%s %s", stu[min].id, stu[max].id);
	return 0;
}