#include <algorithm>
#include <iostream>
#include <utility>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <set>
using namespace std;
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define abs(a) ((a)<0?-(a):(a))
int x[5][5];
int main()
{
 freopen("a.in","r",stdin);
 freopen("a.out","w",stdout);
 int t,p,i,f;scanf("%d\n",&t);
 for(p=1;p<=t;p++)
 {printf("Case #%d: ",p);
  bool log=0;
  for(i=0;i<4;i++)
  {
   for(f=0;f<4;f++)
   {char c;
    scanf("%c",&c);
    if(c=='X'){x[i][f]=1;}
    if(c=='O'){x[i][f]=2;}
    if(c=='T'){x[i][f]=3;}
    if(c=='.'){x[i][f]=0;log=1;}
   }
   scanf("\n");
  }
  scanf("\n");
  if(((x[0][0]==1||x[0][0]==3)&&(x[0][1]==1||x[0][1]==3)&&(x[0][2]==1||x[0][2]==3)&&(x[0][3]==1||x[0][3]==3))||
     ((x[1][0]==1||x[1][0]==3)&&(x[1][1]==1||x[1][1]==3)&&(x[1][2]==1||x[1][2]==3)&&(x[1][3]==1||x[1][3]==3))||
     ((x[2][0]==1||x[2][0]==3)&&(x[2][1]==1||x[2][1]==3)&&(x[2][2]==1||x[2][2]==3)&&(x[2][3]==1||x[2][3]==3))||
     ((x[3][0]==1||x[3][0]==3)&&(x[3][1]==1||x[3][1]==3)&&(x[3][2]==1||x[3][2]==3)&&(x[3][3]==1||x[3][3]==3))||
     ((x[0][0]==1||x[0][0]==3)&&(x[1][0]==1||x[1][0]==3)&&(x[2][0]==1||x[2][0]==3)&&(x[3][0]==1||x[3][0]==3))||
     ((x[0][1]==1||x[0][1]==3)&&(x[1][1]==1||x[1][1]==3)&&(x[2][1]==1||x[2][1]==3)&&(x[3][1]==1||x[3][1]==3))||
     ((x[0][2]==1||x[0][2]==3)&&(x[1][2]==1||x[1][2]==3)&&(x[2][2]==1||x[2][2]==3)&&(x[3][2]==1||x[3][2]==3))||
     ((x[0][3]==1||x[0][3]==3)&&(x[1][3]==1||x[1][3]==3)&&(x[2][3]==1||x[2][3]==3)&&(x[3][3]==1||x[3][3]==3))||
     ((x[0][0]==1||x[0][0]==3)&&(x[1][1]==1||x[1][1]==3)&&(x[2][2]==1||x[2][2]==3)&&(x[3][3]==1||x[3][3]==3))||
     ((x[3][0]==1||x[3][0]==3)&&(x[2][1]==1||x[2][1]==3)&&(x[1][2]==1||x[1][2]==3)&&(x[0][3]==1||x[0][3]==3)))
     {printf("X won\n");continue;}
  if(((x[0][0]==2||x[0][0]==3)&&(x[0][1]==2||x[0][1]==3)&&(x[0][2]==2||x[0][2]==3)&&(x[0][3]==2||x[0][3]==3))||
     ((x[1][0]==2||x[1][0]==3)&&(x[1][1]==2||x[1][1]==3)&&(x[1][2]==2||x[1][2]==3)&&(x[1][3]==2||x[1][3]==3))||
     ((x[2][0]==2||x[2][0]==3)&&(x[2][1]==2||x[2][1]==3)&&(x[2][2]==2||x[2][2]==3)&&(x[2][3]==2||x[2][3]==3))||
     ((x[3][0]==2||x[3][0]==3)&&(x[3][1]==2||x[3][1]==3)&&(x[3][2]==2||x[3][2]==3)&&(x[3][3]==2||x[3][3]==3))||
     ((x[0][0]==2||x[0][0]==3)&&(x[1][0]==2||x[1][0]==3)&&(x[2][0]==2||x[2][0]==3)&&(x[3][0]==2||x[3][0]==3))||
     ((x[0][1]==2||x[0][1]==3)&&(x[1][1]==2||x[1][1]==3)&&(x[2][1]==2||x[2][1]==3)&&(x[3][1]==2||x[3][1]==3))||
     ((x[0][2]==2||x[0][2]==3)&&(x[1][2]==2||x[1][2]==3)&&(x[2][2]==2||x[2][2]==3)&&(x[3][2]==2||x[3][2]==3))||
     ((x[0][3]==2||x[0][3]==3)&&(x[1][3]==2||x[1][3]==3)&&(x[2][3]==2||x[2][3]==3)&&(x[3][3]==2||x[3][3]==3))||
     ((x[0][0]==2||x[0][0]==3)&&(x[1][1]==2||x[1][1]==3)&&(x[2][2]==2||x[2][2]==3)&&(x[3][3]==2||x[3][3]==3))||
     ((x[3][0]==2||x[3][0]==3)&&(x[2][1]==2||x[2][1]==3)&&(x[1][2]==2||x[1][2]==3)&&(x[0][3]==2||x[0][3]==3)))
     {printf("O won\n");continue;}
  if(log){printf("Game has not completed\n");continue;}
  printf("Draw\n");
 }
}