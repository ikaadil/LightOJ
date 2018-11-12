#include<stdio.h>
int main()
{
    int tc,i;
    double v1,v2,v3,a1,a2,t1,t2,s,t;
    scanf("%d",&tc);
    for(i=1;i<=tc;i++)
    {
        scanf("%lf %lf %lf %lf %lf",&v1,&v2,&v3,&a1,&a2);
        t1=v1/a1;
        t2=v2/a2;
        if(t2>t1)
            t=t2;
        else
            t=t1;
        s=v1*t1-.5*a1*t1*t1+v2*t2-.5*a2*t2*t2;
        printf("Case %d: %lf %lf\n",i,s,t*v3);
    }
    return 0;
}
