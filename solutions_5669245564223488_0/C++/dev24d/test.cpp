#include <bits/stdc++.h>
using namespace std;
#define test(t) while(t--)
#define cin(n) scanf("%d",&n)
#define cinl(n) scanf("%lld",&n)
 
#define cout(n) printf("%d\n",n)
#define rep(i,a,n) for(i=a;i<=n;i++)
#define vi vector<int>
#define vii vector< vector<int> >
#define vpii vector< pair<int,int> >
#define mii map<int,int>
#define eps 1e-12
#define pb push_back
#define mp make_pair
#define imax (int) 1000000007
#define ill long long
#define gc getchar_unlocked
#include<stack>
#define mod 1000000007
#define inf 10000000
 
using namespace std;
 
ill sol1(int aa,int b)
{
    ill ans=1;
    ill a=aa*1LL;
    while(b)
    {
        if(b&1)
            ans=(ans*1LL*a)%mod;
        a=(a*1LL*a)%mod;
        b=b/2;
    }
    return ans;
}
ill modinv(int a)
{
    return sol1(a,mod-2);
}
#define eps 1e-12
#define gc getchar_unlocked
 
int adj[27][27],coun[27],vis[27];
ill arr1[108];
 
ill dfs(int node)
{
    vis[node]=1;
 
    ill ret=arr1[coun[node]];
    for(int j=0;j<27;j++)
    {
        if(adj[node][j]&&!vis[node])
            ret=(ret*1LL*dfs(j))%mod;
    }
    return ret;
}
 
 
int main()
{
    int m,t,i,j,k,l,n;
    int tt;
    freopen("in2.txt","r",stdin);
    freopen("out3.txt","w",stdout);
 
    cin(t);
    arr1[0]=1LL;
    tt=1;
    for(i=1;i<=100;i++)
    {
        arr1[i]=(arr1[i-1]*1LL*i)%mod;
    }
    while(t--)
    {
 
        memset(adj,0,sizeof(adj));
        memset(coun,0,sizeof(coun));
        cin(n);
        int fg=1;
        string s[n+9];
        int indeg[27];
        memset(indeg,0,sizeof(indeg));
        memset(vis,0,sizeof(vis));
        for(i=0;i<n;i++)
        {
            cin>>s[i];
            int st=s[i][0]-'a';
            int gg=0;
            for(j=1;j<s[i].length();j++)
            {
                int val=s[i][j]-'a';
                if(val==st)
                    continue;
                gg=1;
                adj[st][val]++;
                indeg[val]++;
                if(adj[st][val]>1)
                    fg=0;
                st=val;
            }
            if(!gg)
                coun[st]++;
        }
 
        for(i=0;i<26;i++)
        {
            int c=0;
            for(j=0;j<26;j++)
            {
                if(i==j)
                    continue;
                if(adj[i][j])
                    c++;
            }
            if(c>1)
                fg=0;
        }
        cout<<"Case #"<<tt++<<": ";
        if(!fg)
            cout<<"0\n";
        else
        {
            ill ans=1LL;
            int c=0;
            for(i=0;i<26;i++)
            {
                if(vis[i]||indeg[i])
                   continue;
                int zz=0;
                if(coun[i])
                    zz=1;
                for(j=0;j<26;j++)
                {
                    if(adj[i][j])
                    zz=1;
                }
                if(!zz)
                    continue;
                ill z=dfs(i);
                ans=(ans*1LL*z)%mod;
                c++;
            }
            ans=(ans*1LL*arr1[c])%mod;
            cout<<ans<<"\n";
        }
    }
    return 0;
}
