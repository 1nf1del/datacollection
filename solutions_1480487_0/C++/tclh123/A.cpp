#include<cstdio>
#include<cstring>
using namespace std;

#define MAXN 202
#define eps 1e-8
int n;
int x;
int a[MAXN];

int main()
{
	int t;
	scanf("%d", &t);
	for(int T=0; T<t; T++)
	{
		x = 0;
		printf("Case #%d:", T+1);
		scanf("%d", &n);
		for(int i=0; i<n; i++)
		{
			scanf("%d", &a[i]);
			x += a[i];
		}
		//int nx=0;
		int nn=0;
		int j=0;
		int sum = 0;
		for(int i=0; i<n; i++)
		{
			if(a[i]>2*x/(double)n)
			{
				sum += a[i];
			}
			else
			{
				j++;
				//nx += a[i];
			}
		}
		nn = j;
		for(int i=0; i<n; i++)
		{
			double ans;
			if(a[i]>2*x/(double)n)
			{
				ans = 0.0;
			}
			else
			{
				//ans = 2/(double)nn - (double)a[i]/x;
				ans = ((2*x-sum)/(double)nn - a[i])/x;
			}
			ans*=100;
			if(ans<0.0) printf("shit!!!!!!!!!\n");
			printf(" %.6lf", ans);
		}
		printf("\n");
	}
}