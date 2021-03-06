/// ///////////////////// ///
///                       ///
///      Tamanna_24       ///
///                       ///
///         JU            ///
///                       ///
/// ///////////////////// ///

#include<iostream>
#include<sstream>
#include<cstring>
#include<cstdio>
#include<string>
#include<cmath>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<cstdlib>
#include<cctype>

typedef long long ll;
typedef unsigned long long ull;

#define pi 2.0*acos(0.0)

template <class T> T _diff(T a,T b) {return (a<b?b-a:a-b);}
template <class T> T _abs(T a) {return(a<0?-a:a);}
template <class T> T _max(T a, T b) {return (a>b?a:b);}
template <class T> T _min(T a, T b) {return (a<b?a:b);}
template <class T> T max3(T a, T b, T c) {return (_max(a,b)>c ? _max(a,b) : c);}
template <class T> T min3(T a, T b, T c) {return (_min(a,b)<c ? _min(a,b) : c);}
template< class T>T GCD(T a,T b) {
    a=_abs(a);b=_abs(b);T tmp;while(a%b){ tmp=a%b; a=b; b=tmp; } return b;
}
template< class T>T LCM(T a,T b) {
    a=_abs(a);b=_abs(b);return (a/GCD(a,b))*b;
}
template<class T> T toRad(T deg) { return (deg*pi)/(180.0) ;}
template<class T> T toDeg(T rad) { return (rad*180.0)/(pi) ;}

#define pb(a) push_back(a)
#define SET(a) memset(a,-1,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))
#define S(a) scanf("%d",&a)
#define P(a) printf("%d",a)
#define PN() puts("")
#define PCASE() printf("Case #%d:",kk++)
#define eps 1e-9
#define inf 2000000000
#define mod 1000000007
#define MX  1000000
using namespace std;

int t,kk=1,n,i,j,h1,h2;
double d1,d2,m1,m2;
string s;


int main()
{
    freopen("c.txt","r",stdin);
    freopen("c1.txt","w",stdout);

    cin>>t;
    while(t--){
        cin>>n;
        if(n==2){
            cin>>d1>>h1>>m2;
            cin>>d2>>h2>>m2;
        }
        else if(n==1){
            cin>>d1>>h1>>m1;
            if(h1==1){
                PCASE();cout<<" "<<0<<endl;
                continue;
            }
            else {
                d2=d1;m2=m1+1.0;
            }
        }
        double atm,btm;
        int res=0;
        atm=(360.0-d1)/m1;
        btm=(360.0-d2)/m2;
        if(atm+eps<btm){
            atm=(720.0-d1)/m1;
            if(atm+eps<=btm){
                res=1;
            }
        }
        else{
            btm=(720.0-d2)/m2;
            if(btm+eps<=atm){
                res=1;
            }
        }
        PCASE();cout<<" "<<res<<endl;
    }

	return 0;
}










