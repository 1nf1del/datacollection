/*#include<stdio.h>
int main()
{
long long int t,g=1;
scanf("%lld",&t);
while(t--){
	long long int p,q,i,count=1;;
	char c;
	double temp;
	scanf("%lld",&p);
	scanf("%c",&c);
	scanf("%lld",&q);
printf("%lld %lld",p,q);
	if(((q&(q-1))!=0)||(p%2==0)){
		printf("Case #%lld: impossible\n",g);
		g++;
		continue;
	}
	temp=2*(p/q);
	printf("%lld %lld",p,q);
	while(temp<1){
		//printf("hello%lf\n",temp);
		temp=temp*2;
		count++;
	}
	printf("Case #%lld: %lld\n",count,g);
	g++;
}
return 0;
}	
*/
//
//  main.c
//  elf question
//
//  Created by Tapan on 11/05/14.
//  Copyright (c) 2014 Tapan. All rights reserved.
//

#include <stdio.h>
long long gcd(long long a,long long b){
    
    if(b==0) return a;
    else return gcd(b,a%b);
}
int main(int argc, const char * argv[])
{
    long long  t,f=1; scanf("%lld",&t);
    while(t--){
        long long n,m,q,k=0,nn;
        scanf("%lld",&n);
        char a;
        scanf("%c",&a);
        scanf("%lld",&m);
        nn=gcd(m,n);
        m/=nn;n/=nn;
        printf("Case #%lld: ",f);f++;
	q=m;
        while(q%2==0){
            q/=2;
        }
        if(q!=1||n>m){printf("impossible\n");}
        else {
            
            while(1){
                k++;m/=2;
                if(n>=m)break;
                
            }
            printf("%lld\n",k);
        }
        
    }
    return 0;
}
		
