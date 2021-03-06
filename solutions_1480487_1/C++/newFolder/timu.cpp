#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

double a[205], sum;
int n;

double erfen(int id, double left, double right)
{
	int i;
	double mid;
	double temp, p;
	double sump;
	while (fabs(right - left) > 1e-10)
	{
		mid = (left + right) / 2;
		temp = a[id] + sum * mid;
		sump = mid;
		for (i = 0; i < n; i++)
		{
			if (i == id)
				continue;
			if (a[i] > temp)
				continue;
			p = (temp - a[i]) / sum;
			sump += p;
			if (sump > 1.0)
				break;
		}
		if (i == n)
			left = mid;
		else
			right = mid;
	}
	return left * 100;
}

int main ()
{
	freopen("A.in","r",stdin);
	freopen("A.out", "w", stdout);
	int t, cas = 1;
	int i, j;
	scanf ("%d", &t);
	while (t--)
	{
		sum = 0;
		scanf ("%d", &n);
		for (i = 0; i < n; i++)
		{
			scanf ("%lf", &a[i]);
			sum += a[i];
		}
		printf ("Case #%d:", cas++);
		for (i = 0; i < n; i++)
			printf (" %.6lf", erfen(i, 0, 1) + 1e-8);
		printf ("\n");
	}
    return 0;
}