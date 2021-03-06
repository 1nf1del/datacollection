//#include <algorithm>
//#include <string>
#include <stdio.h>
#include <vector>

#define INF 1000000000

using namespace std;

struct UP
{
	UP(int a, int b, int c) : w(a), e(b), s(c) {}
int w;
int e;
int s;

};


class Trib
{
public:
	Trib()
	{
		scanf("%d %d %d %d %d %d %d %d", &d0, &n, &w, &e, &s0, &d, &p, &s);
//		printf("trib d0 %d power %d from %d to %d with interval %d\n", d0, s0, w, e, d);
	}
	int n;
	int d0;
	int d;
	int s0;
	int s;
	int p;
	int e;
	int w;
};

int WALL[600];

bool checkWall(int a, int b, int s)
{
	a+=300;
	b+=300;
	for(int i = a; i<b;++i)
	{

		if (WALL[i]<s)
		{
			return true;
		}
	}
	return false;
}

void updateWall(UP up)
{
	int a= up.w +300;
	int b= up.e +300;

	for(int i = a; i<b; ++i)
	{
		if (WALL[i]<up.s)
		{
			WALL[i]=up.s;
		}
	}
}


int main()
{
	int t;
	scanf("%d", &t);
	
	for (int k=1;k<=t;++k)
	{
		int res = 0;
		for(int i=0;i<600;++i)
		{
			WALL[i]=0;
		}
		vector<Trib> T;
		int N;
		int min;
		scanf("%d", &N);
		for(int i=0;i<N;++i)
		{
			T.push_back(Trib());
		}
		while(true)
		{
			min = INF;
			vector<UP> update;
			for(int i=0;i<N;++i)
			{
				if(T[i].n>0) 
				{
					if(T[i].d0 < min) min = T[i].d0;
				}
			}
			if (min == INF) break;
			for(int i=0;i<N;++i)
			{
//perform attack
				if(T[i].n>0 && T[i].d0 == min)
				{
					if(checkWall(T[i].w, T[i].e, T[i].s0))
					{
						//printf("attack of %d at time %d from %d to %d with power %d\n", i, T[i].d0, T[i].w, T[i].e, T[i].s0);
						res++;
						update.push_back(UP(T[i].w, T[i].e, T[i].s0));
					}
					//else
					//{
					//		printf("attack failed of %d at time %d from %d to %d with power %d\n", i, T[i].d0, T[i].w, T[i].e, T[i].s0);
					//}
					T[i].n--;
					T[i].d0 = T[i].d0 + T[i].d;
					T[i].s0 = T[i].s0 + T[i].s;
					T[i].w += T[i].p;
					T[i].e += T[i].p;
				}
			}
//update WALL
			for(int i=0;i<update.size();++i)
			{
				updateWall(update[i]);
			}
		}
		printf("Case #%d: %d\n",k, res);
	}
	return 0;
}