#include<iostream>
using namespace std;

int main()
{
	long long n, x, a, b, p[40];
	cin>>n;
p[0]=1LL;
p[1]=4LL;
p[2]=9LL;
p[3]=121LL;
p[4]=484LL;
p[5]=10201LL;
p[6]=12321LL;
p[7]=14641LL;
p[8]=40804LL;
p[9]=44944LL;
p[10]=1002001LL;
p[11]=1234321LL;
p[12]=4008004LL;
p[13]=100020001LL;
p[14]=102030201LL;
p[15]=104060401LL;
p[16]=121242121LL;
p[17]=123454321LL;
p[18]=125686521LL;
p[19]=400080004LL;
p[20]=404090404LL;
p[21]=10000200001LL;
p[22]=10221412201LL;
p[23]=12102420121LL;
p[24]=12345654321LL;
p[25]=40000800004LL;
p[26]=1000002000001LL;
p[27]=1002003002001LL;
p[28]=1004006004001LL;
p[29]=1020304030201LL;
p[30]=1022325232201LL;
p[31]=1024348434201LL;
p[32]=1210024200121LL;
p[33]=1212225222121LL;
p[34]=1214428244121LL;
p[35]=1232346432321LL;
p[36]=1234567654321LL;
p[37]=4000008000004LL;
p[38]=4004009004004LL;
	for(int i=1; i<=n; i++)
	{
		cin>>a>>b;
		x=0;
		for(int j=0; j<39; j++)
		{
			if(a<=p[j] && p[j]<=b)
			x++;
		}
		cout<<"Case #"<<i<<": "<<x<<"\n";
	}
	return 0;
}
		
