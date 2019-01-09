#include<cstdio>
#include<cstring>
#include<cctype>

const char* s[7] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };

int main()
{
	//存储四个字符串
	char c1[65], c2[65], c3[65], c4[65];
	scanf("%s%s%s%s", c1, c2, c3, c4);

	//遍历字符串,找出共同字母
	int i;
	for (i = 0; ; i++)
		if (c1[i] == c2[i])
			if (c1[i] >= 'A' && c1[i] <= 'G')
			{
				printf("%s ", s[c1[i] - 'A']);
				break;
			}
	for (i++; ; i++)//初始条件应为i++
	{
		if (c1[i] == c2[i])
		{
			if (c1[i] >= '0' && c1[i] <= '9')
			{
				putchar('0');
				putchar(c1[i]);
				putchar(':');
				break;
			}
			else if (c1[i] >= 'A' && c1[i] <= 'N')
			{
				printf("%d:", 10 + c1[i] - 'A');//特殊情况判断，将字符A带入即可
				break;
			}

		}
	}
	for (i = 0; ; i++)
	{
		if (c3[i] == c4[i])
		{
			if (isalpha(c3[i]))
			{
				printf("%02d", i);
				break;
			}
		}	
	}
	
	return 0;
}