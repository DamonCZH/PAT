#include<cstdio>
#include<vector>
#define max 10000
using namespace std;

int sum[max][max] = {0};
vector<int> num;

int main()
{
	//����Ҫ���м����һϵ������
	int k, a;
	scanf("%d", &k);
	for (int i = 0; i < k; i++)
	{
		scanf("%d", &a);
		num.push_back(a);
	}
	int flag = false;
	for (int i = 0; i < k; i++)
	{
		if (num[i] > 0)
		{
			flag = true;
			break;
		}
	}
	if (!flag)
	{
		printf("0 %d %d", num.front(), num.back());
		return 0;
	}

	//�����ÿ������ĺͣ�����洢����ά���鵱��
	//�кŴ�����ʼλ�ã��кŴ�����㳤��
	int max_sum = -1000000000, max_index, max_len;


	//i������ʼλ�ã�j����ÿ�μ���ĳ��ȣ�p������͹����е�ָ��
	for (int i = 0; i < k; i++)
		for (int j = 1; j <= k - i; j++)
			for (int p = i; p < i + j; p++)
				sum[i][j] += num[p];


	//���ȫΪ���������0����β����
	//������������ʽ��β����
	for (int i = 0; i < k; i++)
	{
		for (int j = 1; j <= k - i; j++)
		{
			if (sum[i][j] > max_sum)
			{
				max_sum = sum[i][j];
				max_index = i;
				max_len = j;
			}
		}
	}

	printf("%d %d %d", max_sum, num[max_index], num[max_index+max_len-1]);
}