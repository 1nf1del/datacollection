//#include <algorithm>
//#include <string>
#include <stdio.h>

//using namespace std;

int main()
{
	int t=10;
	unsigned long long n, r, fisrt, sum, a, tmp;
	scanf("%d", &t);
	for (int i=1;i<=t;++i)
	{
		scanf("%llu %llu", &r, &n);
		sum = 1;
		n-=2*r + 1;
		r+=2;
int j=0;
		while(n/(22*r)  > 2*r+1 + 250)
		{
			//11 orkegow
			a = 22*r + 23*11;
			sum += 11;
			n -=a;
			r+=22;
			++j;
			//printf("aa %llu\n", sum);
		}
		a = 2*r+1;

	//	printf("po %d\n", j);
		j=0;

		while(a <= n)
		{
			sum +=1;
			r+=2;
			n-=a;
			a = 2*r + 1;
				++j;
		}
			//	printf("end %d\n", j);
		printf("Case #%d: %llu\n",i, sum);
	}
	return 0;
}