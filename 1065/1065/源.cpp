#include<cstdio>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	bool flag;
	long long int a, b, c;
	long long int sum;

	for (int i = 1; i <= n; i++)
	{
		scanf("%lld%lld%lld", &a, &b, &c);
		sum = a + b;

		printf("Case #%d: ", i);
		if (a < 0 && b < 0)
		{
			if (sum >= 0)//溢出,要加等号
				flag = false;
			else
			{
				if (sum <= c)
					flag = false;
				else
					flag = true;
			}
		}
		else if (a > 0 && b > 0)
		{
			if (sum <= 0)//溢出
				flag = true;
			else
			{
				if (sum <= c)
					flag = false;
				else
					flag = true;
			}
		}
		else
		{
			if (sum > c)
				flag = true;
			else
				flag = false;
		}

		if (flag)
			printf("true");
		else
			printf("false");

		putchar('\n');
	}
	return 0;
}