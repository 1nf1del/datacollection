#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include <queue>
#include<string>
#include <sstream>
#include<list>
#include<map>
#include<cmath>
#include<algorithm>

using namespace std;


int main()
{
	
	
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);

	
	int T;
	scanf("%d",&T);
	for(int t = 1; t<=T; t++)
	{
		int r,c,w;
		scanf("%d %d %d",&r, &c, &w);
		int res = r*(c/w-1) + w;
		if(c%w) res++;
		printf("Case #%d: %d\n",t,res);
	}
	
	return 0;
}
