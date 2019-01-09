#include<cstdio>
using namespace std;

struct node
{
	int a;
	float d;
	node* next;
};

int main()
{
	int n1, n2;
	int a; float d;

	scanf("%d", &n1);
	node* head1 = NULL, *p1 = NULL, *q;
	for (int i = 0; i < n1; i++)
	{
		q = new node;
		scanf("%d %f", &a, &d);
		q->a = a; q->d = d; q->next = NULL;
		if (p1)
		{
			p1->next = q;
			p1 = p1->next;
		}
		else
			p1 = head1 = q;
	}

	scanf("%d", &n2);
	node* head2 = NULL, *p2 = NULL;
	for (int i = 0; i < n2; i++)
	{
		q = new node;
		scanf("%d %f", &a, &d);
		q->a = a; q->d = d; q->next = NULL;
		if (p2)
		{
			p2->next = q;
			p2 = p2->next;
		}
		else
			p2 = head2 = q;
	}
	//计算乘积并将计算结果放入第三个链表当中
	node* former, *later;
	node* head3 = NULL, *p3 = NULL;
	int n = 0;
	for (p1 = head1; p1; p1 = p1->next)
	{
		for (p2 = head2; p2; p2 = p2->next)
		{
			//创建新结点，将乘积放入其中
			q = new node;
			q->a = p1->a + p2->a;
			q->d = (p1->d)*(p2->d);
			q->next = NULL;
			//将新结点用尾插法链接到链表末尾
			if (head3 == NULL) {
				p3 = head3 = q; n++;
			}
			else if (head3->next == NULL) {
				p3 = head3->next = q; n++;
			}
			else
				//一直找到所在位置，将结点插入或者与已有结点加和，并退出循环
				for (former = head3->next, later = head3;; former = former->next, later = later->next)
				{
					if (former == NULL)
					{
						q->next = former;
						later->next = q;
						n++;
						break;
					}
					else
					{
						if (former->a > q->a) continue;
						else if (former->a == q->a)
						{
							former->d += q->d;
							if (former->d == 0) n--;//注意结点为0时结点总数应当减去1；
							break;
						}
						else if (former->a < q->a)
						{
							q->next = former;
							later->next = q;
							n++;
							break;
						}
					}
				}
		}
	}
	//遍历新链表，注意结尾不能有多余的空格
	p3 = head3;
	printf("%d", n);
	while (p3)
	{
		if(p3->d)
			printf(" %d %.1f", p3->a, p3->d);//注意结点为0的情况
		p3 = p3->next;
	}
	return 0;
}