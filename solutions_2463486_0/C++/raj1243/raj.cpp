#include <iostream>
#include<cmath>

using namespace std;


int main()
{
   long long  int p[39]={1,4,9,121,484,10201,12321,14641,40804,44944,1002001,1234321,4008004,100020001,102030201,104060401,121242121,123454321,125686521,400080004,404090404,10000200001,10221412201,12102420121,12345654321,40000800004,1000002000001,1002003002001,1004006004001,1020304030201,1022325232201,1024348434201,1210024200121,1212225222121,1214428244121,1232346432321,1234567654321,4000008000004,4004009004004};
   long long int k,i,j,n,t,c=0;
    int s,e;
    cin>>t;
    int l=1;
    while(t--)
    {
     s=e=0;
     cin>>i>>j;
     /*
    for(i=0;i<39;i++)
     cout<<p[i]<<" ";
     cout<<"\n";*/
     k=0;
     while(p[k]<i&&k<40)
     {
      //cout<<p[k]<<" ";
       k++;
     }
     s=k;
     while(p[k]<=j&&k<40)
     {
       //cout<<p[k]<<" ";
       k++;
     }
     e=k-1;
    if(s==e)
     cout<<"Case #"<<l<<": "<<1<<"\n";
    else
     cout<<"Case #"<<l<<": "<<e-s+1<<"\n";
     l++;
    }

    return 0;
}
