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
	//输入学生人数，并录入学生信息
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s%s%s%d", &stu[i].name, &stu[i].gender, &stu[i].id, &stu[i].grade);
	}

	//寻找女生最高分与男生最低分（注意特殊情况）
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

	//特殊情况输出,输出上述两人的信息，并输出分差
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