#include<cstdio>
#include<cstring>

const char* mod = "10lO";
const char* alt = "@%Lo";

struct Node
{
	char name[11];
	char pswd[11];
	bool flag = false;
}node[1010];

int main()
{
	//录入账号密码
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%s%s", &node[i].name, &node[i].pswd);
	}

	//将密码字符与检验数组元素逐一核对
	//查看是否有需要替换的字符,如果有则将标志位设为true
	//并修改对应位置的字符
	//记录修改过的密码数量
	int n = 0;
	for (int i = 0; i < m; i++)
	{//对每个账户
		for (int j = 0; j < strlen(node[i].pswd); j++)
		{//对密码的每一位
			for (int k = 0; k < 4; k++)
			{//对照四个字符
				if (node[i].pswd[j] == mod[k])
				{
					node[i].flag = true;
					node[i].pswd[j] = alt[k];
					break;
				}
			}
		}
		if (node[i].flag) n++;
	}


	//如果没有修改输出特定字符串
	//如果有修改输出修改数量和修改用户信息
	if (n == 0)
	{
		if (m == 1)
			printf("There is 1 account and no account is modified");
		else
			printf("There are %d accounts and no account is modified", m);
	}
	else
	{
		printf("%d\n", n);
		for (int i = 0; i < m; i++)
		{
			if (node[i].flag)
			{
				printf("%s %s\n", node[i].name, node[i].pswd);
			}
		}
	}

	return 0;
}