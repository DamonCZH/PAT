#include<cstdio>
#include<vector>
using namespace std;
struct node
{
	int a;
	float d;
	node* next;
};

int main()
{	//input
	int n1, n2, a; float d;
	node *head1, *head2; head1 = NULL; head2 = NULL;
	node *p1 = head1;  node *p2 = head2;

	scanf ("%d",&n1);
	for (int i = 0; i < n1; i++)
	{
		node *p = new node;
		scanf("%d %f", &a, &d);
		p->a = a; p->d = d;
		p->next = NULL;
		if (p1)
		{
			p1->next = p;
			p1 = p1->next;
		}
		else
		{
			head1 = p;
			p1 = p;
		}
	}

	scanf("%d", &n2);
	for (int i = 0; i < n2; i++)
	{
		node *p = new node;
		scanf("%d %f", &a, &d);
		p->a = a; p->d = d;
		p->next = NULL;
		if (p2)
		{
			p2->next = p;
			p2 = p2->next;
		}
		else
		{
			head2 = p;
			p2 = p;
		}
	}

	//create the third linkedlist
	p1 = head1; p2 = head2;
	node *head3 = NULL;
	node *p3 = head3;
	int n = 0;
	while(!(p1 == NULL && p2 == NULL))
	{			
		node *p = new node;

		if (p1 == NULL)//判断是否为空应当放在前面
		{
			p->a = p2->a;
			p->d = p2->d;
			p->next = NULL;
			p2 = p2->next;
		}
		else if (p2 == NULL)
		{
			p->a = p1->a;
			p->d = p1->d;
			p->next = NULL;
			p1 = p1->next;
		}
		else
		{
			if (p1->a == p2->a)
			{
			p->a = p1->a;
			p->d = p1->d + p2->d;
			p->next = NULL;
			p1 = p1->next; p2 = p2->next;
			}
			else if (p1->a > p2->a)
			{
				p->a = p1->a;
				p->d = p1->d;
				p->next = NULL;
				p1 = p1->next;
			}
			else
			{
				p->a = p2->a;
				p->d = p2->d;
				p->next = NULL;
				p2 = p2->next;
			}
		}

		if (p->d == 0.0) continue;//the sum is 0?
		if (p3)
		{
			p3->next = p;
			p3 = p3->next;
		}
		else
		{
			p3 = head3 = p;
		}
		n++;
	}

	p3 = head3; printf("%d", n);
	while (p3)
	{
		printf(" %d %.1f", p3->a, p3->d);
		p3 = p3->next;
	}
	return 0;
}