#include<cstdio>
#include<string>
#include<cstring>
using namespace std;

int main()
{
	const char* str[10] = { "zero","one","two","three","four","five","six","seven","eight","nine" };//cosnt??

	int sum=0;
	char c[110];

	scanf("%s", c);
	for (char* t = c; *t; t++)
	{
		sum += (*t) - '0'; //use ascii to transfer digit to alphabet
	}
	sprintf(c, "%d", sum);//store it(sprintf & sscanf)

	for (char *t = c; *t; t++)
	{
		printf("%s", str[*t - '0']);
		if (*(t+1)) putchar(' ');
	}

	return 0;
}