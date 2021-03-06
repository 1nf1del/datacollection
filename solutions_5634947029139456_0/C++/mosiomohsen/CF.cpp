#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <ctime>
#include <functional>

using namespace std;

#define CLR(a,x) memset(a,x,sizeof a)
#define LL long long
#define ALL(v) v.begin(),v.end()
#define FR(i,n) for(LL i=0;i<(LL)n;i++)
#define FAB(i,a,b) for(LL i=(LL)a;i<(LL)b;i++)
#define FBA(i,b,a) for(LL i=(LL)b;i>=(LL)a;i--)
#define IIN(x) scanf("%d",&x)
#define IIN2(x,y) scanf("%d%d",&x,&y)
#define LIN(x) scanf("%I64d",&x)
#define LIN2(x,y) scanf("%I64d%I64d",&x,&y)
#define EXIT(n) {cout<<n<<endl;return 0;}
#define PII pair<int,int>
#define PPI pair<PII,int>
#define PLL pair<LL,LL>
#define PDD pair<double,double>
#define PDI pair<double,int>
#define PIS pair<int,string>
#define PSI pair<string,int>
#define PI 3.141592653589793238
#define VI vector<int>
#define VLL vector<long>
#define VS vector<string>
#define SI set<int>
#define SLL set<LL>
#define SIP set<PIP>
#define SS set<string>
#define MII map<int,int>
#define MLL map<LL,LL>
#define MSI map<string,int>
#define MSL map<string,LL>
#define MIS map<int,string>
#define INF 100000000000000000
#define MOD 1000000007
#define MAX 100*1000+10

int tc;
int n,l,res;
string a[11],b[11],c[11];

void input()
{
	cin>>n>>l;		
	FR(i,n) cin>>a[i];
	FR(i,n) cin>>b[i];
}

bool check()
{
	SS e;
	FR(i,n) e.insert(b[i]);
	FR(i,n)
	{
		SS::iterator it=e.find(c[i]);
		if(it==e.end()) return 0;
		e.erase(it);
	}
	return 1;
}

void solve()
{
	res=15;
	FR(i,(1<<l))
	{
		FR(j,n) c[j]=a[j];
		LL x=i;
		int k=0,cnt=0;
		while(x)
		{
			if(x&1)
			{
				FR(j,n)
				{
					if(c[j][k]=='1') c[j][k]='0';
					else c[j][k]='1';
				}
				cnt++;
			}
			k++;
			x>>=1;
		}
		if(check()) res=min(res,cnt);
	}
}

void output(int q)
{
	if(res==15) cout<<"Case #"<<q+1<<": NOT POSSIBLE"<<endl;
	else cout<<"Case #"<<q+1<<": "<<res<<endl;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	cin>>tc;
	FR(q,tc)
	{
		input();
		solve();
		output(q);
	}

	return 0;
}