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
	//输入字符串，负数情况首先记录下来，字符串中只存储数字
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

	//反转数字字符串，按照每四位划分一小节
	reverse(arab.begin(), arab.end());
	for (int i = 0; i < n; i++)
	{
		arab[i].wanyi = i / 4;
	}

	//对每一位进行判断，逆序连接拼音字符串
	//对单位的判断应当在数字之前，因为为逆序连接
	for (int i = 0; i < n; i++)
	{
		//对万亿单独判断
		if (i == 4 && !(arab[4].c == '0' && arab[5].c == '0' && arab[6].c == '0' && arab[7].c == '0'))
			chinese.push_back("Wan");
		if (i == 8)
			chinese.push_back("Yi");

		//对每一位单位进行判断，包括0和非0情况，非零不输出单位
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
		//对每一位数字进行判断，主要是注意0的情况
		//若在同一节内，当前位为0，上一位不为0，输出ling
		if (arab[i].c != '0')//不为0
		{
			chinese.push_back(num[arab[i].c - '0']);
		}
		else//为0
		{
			//上一位不为0
			if (i != 0)
				if (arab[i - 1].c != '0' && arab[i - 1].wanyi == arab[i].wanyi)
				{
					chinese.push_back("ling");
				}
		}
	}
	//逆序拼音字符串
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