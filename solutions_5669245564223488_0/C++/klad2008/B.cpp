#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>
#define LL long long
using namespace std;
const int pp=1000000007;
int st[1010],ne[1010],go[1010];
int pt,T,N,sum,ans;
int use[1010],in[1010];
bool uu[1010];
bool ok[1010],tr[1010];
char s[1010][1010];
bool flag;
void Add(int x,int y){ne[++pt]=st[x];st[x]=pt;go[pt]=y;}
int main(){
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	scanf("%d",&T);
	for (int tt=1;tt<=T;tt++){
		memset(st,0,sizeof(st));
		memset(ne,0,sizeof(ne));
		memset(go,0,sizeof(go));
		pt=N=sum=ans=0;
		memset(use,0,sizeof(use));
		memset(in,0,sizeof(in));
		memset(uu,0,sizeof(uu));
		memset(ok,0,sizeof(ok));
		memset(tr,0,sizeof(tr));
		flag=false;
		scanf("%d\n",&N);for (int i=1;i<=N;i++)scanf("%s",s[i]);scanf("\n");
		flag=true;
		memset(ok,0,sizeof(ok));
		for (int i=1;i<=N&&flag;i++){
			int ll=strlen(s[i]);memset(use,0,sizeof(use));
			for (int j=0;j<ll;j++)if (j&&use[s[i][j]]&&s[i][j-1]!=s[i][j]){flag=false;break;}else use[s[i][j]]=1;
			sum=0;for (int j=0;j<256;j++)if (use[j])sum++;if (sum==1)ok[i]=1;
		}//ֱ�����е����޽���� 
		if (!flag){printf("Case #%d: 0\n",tt);continue;}
		memset(st,0,sizeof(st));pt=0;
		for (int i=1;i<=N;i++)
		for (int j=1;j<=N;j++)
		if (!ok[i]&&!ok[j]){
			int l1=strlen(s[i]);
			if (s[i][l1-1]==s[j][0])Add(i,j),in[j]++;
		}//�������ӵ����ӣ�������ֱ���޽� 
		for (int i=1;i<=N;i++)if (in[i]>1){flag=false;break;}
		if (!flag){printf("Case #%d: 0\n",tt);continue;}
		memset(tr,0,sizeof(tr));memset(use,0,sizeof(use));
		sum=0;ans=1;
		for (int i=1;i<=N;i++)
		if (!in[i]&&!tr[i]&&!ok[i]){
			sum++;int x=i;tr[x]=true;
			memset(uu,0,sizeof(uu));
			while (true){
				bool rr=true;
				int ll=strlen(s[i]);
				for (int j=0;j<ll;j++)uu[s[i][j]]=true;
				for (int j=st[x];j;j=ne[j])
				if (in[go[j]]==1){in[go[j]]--;tr[go[j]]=1;x=go[j];rr=false;break;}
				if (rr)break;
			}
			for (int j=0;j<256;j++)
			if (uu[j]&&use[j]){flag=false;break;}
			for (int j=0;j<256;j++)use[j]|=uu[j];
		}
		//�������� 
		for (int i=1;i<=N;i++)if (!ok[i]&&!tr[i]){flag=false;break;}
		if (!flag){printf("Case #%d: 0\n",tt);continue;}
		memset(use,0,sizeof(use));
		for (int i=1;i<=N;i++)if (ok[i])use[s[i][0]]=true;
		for (int i=1;i<=N;i++)
		if (!ok[i]){
			int ll=strlen(s[i]),l=0,r=ll-1;
			while (l<ll&&s[i][0]==s[i][l])l++;
			while (r>=0&&s[i][ll-1]==s[i][r])r--;
			for (int k=l;k<=r;k++)if (use[s[i][k]]){flag=false;break;}
			for (int k=l;k<=r;k++)use[s[i][k]]=true;
		}
		//�ж��Ƿ��е��ַ�������İ������޽���� 
		if (!flag){printf("Case #%d: 0\n",tt);continue;}
		memset(use,0,sizeof(use));
		for (int i=1;i<=N;i++)if (ok[i])use[s[i][0]]++,tr[i]=true;
		for (int i=0;i<256;i++)
		if (use[i]>0){
			int s1=0,s2=0;
			for (int j=1;j<=N;j++)
			if (!ok[j]){
				int ll=strlen(s[j]);
				if (s[j][0]==i)s1++;
				if (s[j][ll-1]==i)s2++;
			}
			if (s1>1||s2>1){flag=false;break;}
			if (s1==0&&s2==0)sum++;
		}
		if (!flag){printf("Case #%d: 0\n",tt);continue;}
		//�жϵ��ַ����Ƿ���ȷ�������ӵ�λ��
		for (int j=1;j<=sum;j++)ans=ans*j%pp;
		for (int i=0;i<256;i++)
		for (int j=1;j<=use[i];j++)ans=ans*j%pp;
		//����� 
		printf("Case #%d: %d\n",tt,ans);
	}
}