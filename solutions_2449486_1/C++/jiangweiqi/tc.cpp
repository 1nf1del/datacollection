#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <cctype> 
#include <string> 
#include <cstring> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <string.h>

using namespace std; 

#define ALL(X)       (X).begin(),(X).end()
#define SIZE(X)      ((int)(X).size())
#define FORI(x,a,b)  for(x=(a);x<=(b);x++)
#define FORD(x,a,b)  for(x=(a);x>=(b);x--)
#define min(a,b)     ((a)<(b)?(a):(b))
#define max(a,b)     ((a)<(b)?(b):(a))
#define MEM(X,with)  memset((X),(with),sizeof(X))
#define Contains(X,item)    ((X).find(item)!=(X).end())
#define Contains_n(X,item)    (find((X).begin(),(X).end(),(item))!=(X).end())
#define rep(i,m,n) for((i)=m;(i)<(int)(n);(i)++)
#define PQ priority_queue
#define LB lower_bound
#define UB upper_bound
#define NXETSORT next_permutation
#define PREVSORT prev_permutation
#define ONLYONE(A,B,n) unique_copy(A,A+n,B)
#define IT iterator
#define N 100005
#define EPS 1e-6
#define Mod 1000000007
//bool prime[N];

const int inf =(1<<30)-1;
const long long linf = (1ll<<62)-1;
const int dirx[]={-1,0,0,1,-1,-1,1,1}, diry[]={0,-1,1,0,-1,1,-1,1};
const double ERR = 1e-11, PI=(2*acos(0.0));


typedef long long ll;
typedef unsigned long long ull;
typedef stringstream   SS;
typedef vector<string> VS;
typedef vector<double> VD;
typedef vector<ll>     VL;
typedef vector<int>    VI;

template<class T> bool cmpmin(T a, T b){return a<b;}
template<class T> bool cmpmax(T a, T b){return a>b;}
template<class T> inline T ABS(T a) {return ((a<0)?(-a):(a));}
template<class T> T GCD(T a,T b) {return ((!b)?(a):GCD(b,a%b));}
template<class T> T fastPow(T Base,T Power) {T Result=1; while(Power>0){if(Power&((T)1))Result*=Base; Power>>=1; Base*=Base;} return Result;}
//template<class T> T fastModPow(T Base,T Power,T Mod) {T Result=1;while(Power>0){if(Power&((T)1))Result=(Result*Base)%Mod; Power>>=1; Base=(Base*Base)%Mod;} return (Result%Mod);}
inline int compDouble(double x,double y) {double d=x-y; if(d-ERR>0.0) return 1; else if(d+ERR<0.0) return -1; else return 0;}
inline void file(){freopen("B-large.in","r",stdin);freopen("B.txt","w",stdout);}
//void prim(){prime[0]=1;prime[1]=1;int i;long long j;for(i=2;i<N;i++){if(prime[i]==0){for(j=i,j=j*i;j<N;j+=i){prime[j]=1;}}}}

ll Eular(ll n){int i;ll ret=n;for(i=2;i*i<=n;++i){if(n%i==0){ret-=ret/i;while(n%i==0)n/=i;if(n==1)break;}}if(n!=1)ret-=ret/n;return ret;}

/*int cross(int a, int b, int c, int d){
return a * d - b * c;
}*/


int main(){
	file();
	int t,cas,i,j,n,m,ii,jj;
	int rec[105][105];
	scanf("%d",&t);
	for(cas=1;cas<=t;cas++){
		bool flag=1;
		scanf("%d %d",&n,&m);
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				scanf("%d",&rec[i][j]);
			}
		}
		for(i=0;i<n&&flag;i++){
			for(j=0;j<m&&flag;j++){
				for(ii=0;ii<n;ii++){
					if(rec[ii][j]>rec[i][j])break;
				}
				if(ii==n)continue;
				for(jj=0;jj<m;jj++){
					if(rec[i][jj]>rec[i][j])break;
				}
				if(jj!=m){
					flag = 0;
				}
			}
		}
		if(flag)printf("Case #%d: YES\n",cas);
		else printf("Case #%d: NO\n",cas);
	}
	return 0;
}