#include <iostream>
using namespace std;
#include <stdio.h>
#define MAXN 1000100
int count[MAXN];
int calc(int now) { return (now+1)*now/2; }
int main()
{
    int T;
    string name;
    int N;
    freopen("A-small-attempt4.in","r",stdin);
    freopen("A-small-attempt4.out","w",stdout);
    scanf("%d",&T);
    for(int cnt = 1;cnt<=T;cnt++)
    {
        cin>>name>>N;
        int length = name.length();
        int start = -1,end=0;

        int ans = calc(length-N+1);
        if(N==1)
        {
                    int total= 0;
            for(int i=0;i<length;i++)
            {
                if(name[i]=='a'||name[i]=='e'||name[i]=='i'||name[i]=='o'||name[i]=='u')
                {
                    total++;
                }
                else if(total!=0)
                {
                    ans -= calc(total);
                    total = 0;
                }
            }
            if(total!=0) ans-=calc(total);
            printf("Case #%d: %d\n",cnt,ans);
            continue;
        }
        if(name[0]=='a'||name[0]=='e'||name[0]=='i'||name[0]=='o'||name[0]=='u') count[0] = 0;
        else count[0] = 1;
        for(int i=1;i<length;i++)
        {
            if(name[i]=='a'||name[i]=='e'||name[i]=='i'||name[i]=='o'||name[i]=='u') count[i] = 0;
            else count[i] = count[i-1]+1;
        }
        if(count[0]==0) start = 0;
        else start = -1;
       // cout<<"length: "<<length<<endl;
        for(int i=1;i<length;i++)
        {
            if(count[i]>N) continue;
            if(count[i]==0&&start == -1) { start = i; }
            if(count[i]==N||i==length-1)
            {
                if(start == -1) continue;
                if(start == i||(i==length-1&&count[i]!=N)) end = i;
                else end = i-1;
                int left = start>(N-1)?start-(N-1):0;
                int right = end;
                ans -= calc(right-left+1-N+1);
                start = -1;
            }
        }
        printf("Case #%d: %d\n",cnt,ans);
    }
    return 0;
}
