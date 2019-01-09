#include<cstdio>

int main()
{
	// ‰»ÎA∫ÕB
	int a, b, c, x, y, z; char m;
	scanf("%d%c%d%c%d", &a, &m, &b, &m, &c);
	scanf("%d%c%d%c%d", &x, &m, &y, &m, &z);

	int s1, s2, s3;
	s3 = (c + z) % 29;
	s2 = (b + y+ (c + z) / 29) % 17 ;
	s1 = a + x + (b + y + (c + z) / 29) / 17;

	printf("%d.%d.%d", s1, s2, s3);
	return 0;
}