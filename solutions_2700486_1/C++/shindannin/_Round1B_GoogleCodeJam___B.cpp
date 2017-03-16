// I may use the MPIR library. Its website is this,
// http://www.mpir.org/

#include <stdio.h>
#include <tchar.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
using namespace std;

typedef long long ll;

static const double EPS = 1e-6;
inline int ROUND(double x) { return (int)(x+0.5); }
inline bool ISINT(double x) { return fabs(ROUND(x)-x)<EPS; }
inline bool ISEQUAL(double x,double y) { return fabs(x-y)<EPS; }
#define INRANGE(x,a,b) ((a)<=(x)&&(x)<=(b))
#define ARRAY_NUM(a) (sizeof(a)/sizeof(a[0])) 
#define SZ(a) ((int)a.size())
#define NG	(987654321)


int main()
{
	freopen("_google_code_jam_input.txt","r",stdin);
	freopen("_google_code_jam_output.txt","w",stdout);

	int C;
	scanf("%d ",&C);

/*
	int sum = 0;
	for (int n = 0; n < 10000; n++)
	{
		sum += (4*n+1);
		// BEGIN CUT HERE
		cout << " n=" << n << " 4*n+1=" << 4*n+1 << " sum=" << sum << endl;
		// END CUT HERE
	}
*/


#if 1
	for (int c=0;c<C;c++)
	{
		int N,X,Y;
		scanf("%d %d %d ",&N,&X,&Y);

		int n;
		int sum = 0;
		for (n = 0; n < 10000; n++)
		{
			sum += (4*n+1);

			if(sum>=N)
			{
				break;
			}
		}

		double ret = 0.0;

		if(abs(X)+abs(Y)<2*n)
		{
			ret = 1.0;
		}
		else if (abs(X)+abs(Y)==2*n)
		{
			int amari = N-(sum-(4*n+1));

			if(amari==0)
			{
				ret = 1.0;
			}
			else
			{
				static double dp[5000][5000]; // [][�E�̌�]
				memset(dp,0,sizeof(dp));

				dp[0][0]=1;
				for (int i = 0; i < amari; i++)
				{
					for (int right = 0; right < 5000; right++)
					{
						int left = i-right;

						if(left<2*n && right<2*n)
						{
							dp[i+1][right+1] += dp[i][right]*0.5; 
							dp[i+1][right]   += dp[i][right]*0.5;
						}
						else if (left<2*n)
						{
							dp[i+1][right]   += dp[i][right]*0.5;
							dp[i+1][right]   += dp[i][right]*0.5;
						}
						else if (right<2*n)
						{
							dp[i+1][right+1]   += dp[i][right]*0.5;
							dp[i+1][right+1]   += dp[i][right]*0.5;
						}
					}
				}

				ret = 0.0;
				for (int right = 0; right < 5000; right++)
				{
					if(Y+1<=right)
					{
						ret += dp[amari][right];
					}
				}
			}
		}
#else

		int tomaru = 0;
		for (int i = 0; i < (1<<N); i++)
		{
			set < pair <int, int> > st;
			for (int k = 0; k < N; k++)
			{
				int x=0,y=20;
				for (int turn = 0; turn < 1000; turn++)
				{
					if(y==0) break;
					int down  = st.count(make_pair(x,y-2));
					int left  = st.count(make_pair(x-1,y-1));
					int right = st.count(make_pair(x+1,y-1));

					if( down )
					{
						if(left && right)
						{
							break;
						}
						else if (left)
						{
							x++;
							y--;
						}
						else if (right)
						{
							x--;
							y--;
						}
						else
						{
							if(i & (1<<k))
							{
								x++;
								y--;
							}
							else
							{
								x--;
								y--;
							}
						}
					}
					else
					{
						if(left && right)
						{
							break;
						}
						else if (left)
						{
							x++;
							y--;
						}
						else if (right)
						{
							x--;
							y--;
						}
						else
						{
							y-=2;
						}
					}
				}


				st.insert(make_pair(x,y));
			}

			if(st.count(make_pair(X,Y)))
			{
				tomaru++;
			}
		}

		double prob = (double)tomaru/(1<<N);
#endif

		{
			fprintf(stderr,"Case #%d: %.16f\n",c+1,ret);
			printf("Case #%d: %.16f",c+1,ret);
		}

		printf("\n");

	 }
	return 0;
}
