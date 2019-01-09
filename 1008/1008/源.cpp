#include<cstdio>

int main()
{
	int n;
	scanf("%d", &n);

	int a[110]; a[0] = 0; int dif;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", a + i);
	}

	int t_sum = 0;
	t_sum += n * 5;
	for (int i = 1; i <= n; i++)
	{
		dif = a[i] - a[i - 1];
		if (dif > 0) t_sum += dif * 6;
		else         t_sum += (-dif) * 4;
	}
	printf("%d", t_sum);

	return 0;
}