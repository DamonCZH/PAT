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
	//¼���˺�����
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%s%s", &node[i].name, &node[i].pswd);
	}

	//�������ַ����������Ԫ����һ�˶�
	//�鿴�Ƿ�����Ҫ�滻���ַ�,������򽫱�־λ��Ϊtrue
	//���޸Ķ�Ӧλ�õ��ַ�
	//��¼�޸Ĺ�����������
	int n = 0;
	for (int i = 0; i < m; i++)
	{//��ÿ���˻�
		for (int j = 0; j < strlen(node[i].pswd); j++)
		{//�������ÿһλ
			for (int k = 0; k < 4; k++)
			{//�����ĸ��ַ�
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


	//���û���޸�����ض��ַ���
	//������޸�����޸��������޸��û���Ϣ
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