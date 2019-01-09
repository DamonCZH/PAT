#include<cstdio>
#include<vector>
#define max 10000
using namespace std;

int sum[max][max] = {0};
vector<int> num;

int main()
{
	//输入要进行计算的一系列数字
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

	//计算出每种情况的和，将其存储进二维数组当中
	//行号代表起始位置，列号代表计算长度
	int max_sum = -1000000000, max_index, max_len;


	//i代表起始位置，j代表每次计算的长度，p代表求和过程中的指针
	for (int i = 0; i < k; i++)
		for (int j = 1; j <= k - i; j++)
			for (int p = i; p < i + j; p++)
				sum[i][j] += num[p];


	//如果全为负数，输出0和首尾数字
	//否则输出和与和式首尾数字
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