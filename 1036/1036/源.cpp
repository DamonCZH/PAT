#include<cstdio>
using namespace std;

struct student
{
	char name[12];
	char gender[2];
	char id[12];
	int grade;
}stu[100];

int main()
{
	//����ѧ����������¼��ѧ����Ϣ
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s%s%s%d", &stu[i].name, &stu[i].gender, &stu[i].id, &stu[i].grade);
	}

	//Ѱ��Ů����߷���������ͷ֣�ע�����������
	int max = -1, min = 101;
	int max_i = 0, min_i = 0;
	for (int i = 0; i < n; i++)
	{
		if (stu[i].gender[0] == 'F')
		{
			if (stu[i].grade > max)
			{
				max_i = i;
				max = stu[i].grade;
			}
		}
		else
		{
			if (stu[i].grade < min)
			{
				min_i = i;
				min = stu[i].grade;
			}
		}
	}

	//����������,����������˵���Ϣ��������ֲ�
	if (max == -1 || min == 101)
	{
		if (max == -1)
		{
			puts("Absent");
			printf("%s %s\n", stu[min_i].name, stu[min_i].id);
		}
		else
		{
			printf("%s %s\n", stu[max_i].name, stu[max_i].id);
			puts("Absent");
		}
		puts("NA");
	}
	else
	{
		printf("%s %s\n", stu[max_i].name, stu[max_i].id);
		printf("%s %s\n", stu[min_i].name, stu[min_i].id);
		printf("%d", max - min);
	}

	return 0;
}