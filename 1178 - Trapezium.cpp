#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,cs=1;
    cin>>t;
    while(t--)
    {
        double a,b,c,d,e,tringle,h,s;
        scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
        if(c>a)
            swap(a,c);
        e=a-c;
        s=(b+d+e)/2;
////        cout<<s<<endl;
        tringle=sqrt(s*(s-b)*(s-d)*(s-e));
        h=2*(tringle/e);
//            cout<<tringle <<" "<<h<<endl;
        printf("Case %d: %.9lf\n",cs++,.5*h*(c+a));

    }
}
