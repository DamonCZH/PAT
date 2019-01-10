#include<cstdio>
#include<cctype>
#include<string>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

string num[10] =
{ "ling","yi","er","san","si",
"wu","liu","qi","ba","jiu" };
string dan[3] =
{ "Qian","Bai","Shi" };

struct node
{
	char c;
	int wanyi;
};
vector<string> chinese;
vector<node> arab;

int main()
{
	//�����ַ���������������ȼ�¼�������ַ�����ֻ�洢����
	char c; int n = 0; bool minus = false;
	c = getchar();
	while (c != '\n')
	{
		if (c == '-')
		{
			minus = true;
			c = getchar();
			continue;
		}
		node p;
		p.c = c;
		arab.push_back(p);

		c = getchar(); n++;
	}

	//��ת�����ַ���������ÿ��λ����һС��
	reverse(arab.begin(), arab.end());
	for (int i = 0; i < n; i++)
	{
		arab[i].wanyi = i / 4;
	}

	//��ÿһλ�����жϣ���������ƴ���ַ���
	//�Ե�λ���ж�Ӧ��������֮ǰ����ΪΪ��������
	for (int i = 0; i < n; i++)
	{
		//�����ڵ����ж�
		if (i == 4 && !(arab[4].c == '0' && arab[5].c == '0' && arab[6].c == '0' && arab[7].c == '0'))
			chinese.push_back("Wan");
		if (i == 8)
			chinese.push_back("Yi");

		//��ÿһλ��λ�����жϣ�����0�ͷ�0��������㲻�����λ
		if (i % 4 == 0)
		{
			if (n == 1)
			{
				chinese.push_back(num[arab[i].c - '0']);
				break;
			}
		}
		else if (i % 4 == 1)
		{
			if (arab[i].c != '0')
				chinese.push_back("Shi");
		}
		else if (i % 4 == 2)
		{
			if (arab[i].c != '0')
				chinese.push_back("Bai");
		}
		else
		{
			if (arab[i].c != '0')
				chinese.push_back("Qian");
		}
		//��ÿһλ���ֽ����жϣ���Ҫ��ע��0�����
		//����ͬһ���ڣ���ǰλΪ0����һλ��Ϊ0�����ling
		if (arab[i].c != '0')//��Ϊ0
		{
			chinese.push_back(num[arab[i].c - '0']);
		}
		else//Ϊ0
		{
			//��һλ��Ϊ0
			if (i != 0)
				if (arab[i - 1].c != '0' && arab[i - 1].wanyi == arab[i].wanyi)
				{
					chinese.push_back("ling");
				}
		}
	}
	//����ƴ���ַ���
	reverse(chinese.begin(), chinese.end());

	if (minus) printf("Fu ");
	for (int i = 0; i < chinese.size(); i++)
	{
		if (i)
			putchar(' ');
		cout << chinese[i];
	}

	return 0;
}