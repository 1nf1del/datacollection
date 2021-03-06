#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <set>
#include <functional>
#include <list>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>
#include <iterator>
#define getI(a) scanf("%d", &a)
#define getII(a,b) scanf("%d%d", &a, &b)
#define getIII(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define wez(n) int (n); scanf("%d",&(n))
#define TESTS wez(testow); while(testow--)
#define F(i,L,R) for (int i = L; i < R; i++) //next four are for "for loops"
#define FE(i,L,R) for (int i = L; i <= R; i++)
#define FF(i,L,R) for (int i = L; i > R; i--)
#define FFE(i,L,R) for (int i = L; i >= R; i--)
#define MAX(a,b) ( (a) < (b) ? (b) : (a) )
#define MIN(a,b) ( (a) < (b) ? (a) : (b) )
#define tr(i,t) for (typeof((t).begin()) i=(t).begin(); i!=(t).end(); i++) // traverse an STL data structure
#define ALL(c) (c).begin(),(c).end() //handy for function like "sort()"
#define PRESENT(c,x) ((c).find(x) != (c).end())
#define CPRESENT(c,x) (find(ALL(c),x) != (c).end())
#define REMIN(a,b) (a)=min((a),(b))
#define REMAX(a,b) (a)=max((a),(b)) // set a to the maximum of a and b
#define SZ(x) ((int)((x).size()))
#define lastEle(vec) vec[vec.size()-1]
#define pb push_back
#define mp make_pair

//Debug Macros
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl
#define printA(a,L,R) FE(i,L,R) cout << a[i] << (i==R?'\n':' ')
#define printV(a) printA(a,0,a.size()-1)



#define MODN 1000000007

#define PI 3.1415926535897932384626
#define LSOne(S) (S & (-S))
#define MAXN 110
using namespace std;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef pair<int,int> ii;
typedef long long ll;

int dp[5][5][5];

void preProcess(){
    F(x,1,5){
        //    cout<<"For "<<x<<endl;
        F(r,1,5){
            F(c,1,5){
                if( (r*c)%x != 0   ||  MAX(r,c)<x  || MIN(r,c) < (x+1)/2 || (x==4 && (r==2 || c==2))) dp[x][r][c] = 0;
                else dp[x][r][c] =1;
          //      cout<<dp[x][r][c]<<" ";
            }
          //  cout<<endl;
        }
    }
}

int main(int argc, char const *argv[])
{
    preProcess();
    int x,r,c,tc=1;
    char gab[] = "GABRIEL";
    char rich[] = "RICHARD";
    TESTS{
        getIII(x,r,c);
        printf("Case #%d: %s\n", tc++,(dp[x][r][c]==0)?rich:gab );
    }


    return 0;
}