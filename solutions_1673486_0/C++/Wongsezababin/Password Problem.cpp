#include<stdlib.h>
#include<stdio.h>
int main()
{
    int t,a,b;
    double p1,p2,p3,exp1,exp2,exp3,exp4,ans;
    
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d%d",&a,&b);
        if(a==1)
        {
            scanf("%lf",&p1);
            exp1=b*p1+(2*b+1)*(1-p1);
            exp2=b+2;
            if(exp1<exp2)
                ans=exp1;
            else
                ans=exp2;
        }
        else if(a==2)
        {
            scanf("%lf%lf",&p1,&p2);
            exp1=(b-1)*p1*p2+(2*b)*(1-p1*p2);
            exp2=(b+1)*p1+(2*b+2)*(1-p1);
            exp3=b+2;
            if(exp1<exp2)
            {
                if(exp1<exp3)
                    ans=exp1;
                else
                    ans=exp3;
            }
            else
            {
                if(exp2<exp3)
                    ans=exp2;
                else
                    ans=exp3;
            }
        }
        else //if(a==3)
        {
            scanf("%lf%lf%lf",&p1,&p2,&p3);
            exp1=(b-2)*p1*p2*p3+(2*b-1)*(1-p1*p2*p3);
            exp2=b*p1*p2+(2*b+1)*(1-p1*p2);
            exp3=(b+2)*p1+(2*b+3)*(1-p1);
            exp4=b+2;
            if(exp1<exp2)
            {
                if(exp1<exp3)
                {
                    if(exp1<exp4)
                        ans=exp1;
                    else
                        ans=exp4;
                }
                else
                {
                    if(exp3<exp4)
                        ans=exp3;
                    else
                        ans=exp4;
                }
            }
            else
            {
                if(exp2<exp3)
                {
                    if(exp2<exp4)
                        ans=exp2;
                    else
                        ans=exp4;
                }
                else
                {
                    if(exp3<exp4)
                        ans=exp3;
                    else
                        ans=exp4;
                }
            }
        }
        printf("Case #%d: %lf\n",i+1,ans);
    }
    //system("pause");
}
