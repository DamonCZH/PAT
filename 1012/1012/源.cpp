//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//
//const char *s = "ACME";
//
//struct student
//{
//	int id;
//	int score[4];
//	int rank[4];
//	int best_rank;
//	int index_best_rank;
//}stu[2010];
//
//int now;
//
//bool cmp(student a, student b)
//{
//	return a.score[now] > b.score[now];
//}
//
//int main()
//{
//	//¼��ѧ����������ѯ����
//	int n, m;
//	scanf("%d%d", &n, &m);
//
//	//¼��ѧ����Ϣ����ѯ��Ϣ
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d%d%d%d", &stu[i].id, &stu[i].score[1], &stu[i].score[2], &stu[i].score[3]);
//		stu[i].score[0] = stu[i].score[1] + stu[i].score[2] + stu[i].score[3];
//		stu[i].best_rank = 4;
//	}
//
//	//���ÿ��ѧ����ÿһ��Ŀ�ĵȼ����������ѵȼ��������
//
//	//��ÿһ��Ŀ�����ѧ���ȼ�����д��
//	for (now = 0; now < 4; now++)
//	{
//		sort(stu, stu + n, cmp);
//		for (int i = 0; i < n; i++)
//		{
//			if (i == 0)
//				stu[i].rank[now] = 1;
//			else
//			{
//				if (stu[i].score[now] == stu[i - 1].score[now])
//					stu[i].rank[now] = stu[i - 1].rank[now];
//				else
//					stu[i].rank[now] = i + 1;
//			}
//		}
//	}
//	
//	
//	//���ÿ��ѧ����������μ�������ο�Ŀ����
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < 4; j++)
//		{
//			if (stu[i].best_rank > stu[i].rank[j])
//			{
//				stu[i].best_rank = stu[i].rank[j];
//				stu[i].index_best_rank = j;
//			}
//		}
//	}
//
//	//��Բ�ѯ�������
//	int id, i, j;
//	for (i = 0; i < m; i++)
//	{
//		scanf("%d", &id);
//		for (j = 0; j < n; j++)
//		{
//			if (stu[j].id == id)
//			{
//				printf("%d %c\n", stu[j].best_rank, s[stu[j].index_best_rank]);
//				break;
//			}
//		}
//		if (j == n) puts("N/A");
//	}
//	return 0;
//}


#include<cstdio>
#include<algorithm>
using namespace std;

struct student
{
	int id;
	int score[4];
}stu[2010];

int now;

bool cmp(student a, student b)
{
	return a.score[now] > b.score[now];
}

int main()
{
		//¼��ѧ����������ѯ����
		int n, m;
		scanf("%d%d", &n, &m);
	
		//¼��ѧ����Ϣ����ѯ��Ϣ
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d%d%d", &stu[i].id, &stu[i].score[1], &stu[i].score[2], &stu[i].score[3]);
			stu[i].score[0] = stu[i].score[1] + stu[i].score[2] + stu[i].score[3];
			stu[i].best_rank = 4;
		}
}