#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        int Ax,Ay,Bx,By,Cx,Cy;
        cin>>Ax>>Ay>>Bx>>By>>Cx>>Cy;
        int Dx,Dy;
        Dx=Ax-Bx+Cx;
        Dy=Ay-By+Cy;
        double a,b,c,s,ans;
        a=sqrt((Ax-Bx)*(Ax-Bx)+(Ay-By)*(Ay-By));
        b=sqrt((Dx-Ax)*(Dx-Ax)+(Dy-Ay)*(Dy-Ay));
        c=sqrt((Dx-Bx)*(Dx-Bx)+(Dy-By)*(Dy-By));
        s=(a+b+c)/2.0;
        ans = sqrt(s*(s-a)*(s-b)*(s-c));
        cout<<"Case"<<" "<<i<<":"<<" "<<Dx<<" "<<Dy<<" "<<ans*2<<endl;
////         printf("Case %d: %.0lf %.0lf %.0lf\n",i,Dx,Dy,ans*2);
//        printf("Case %d: %d %d %d\n",i,Dx,Dy,ans*2);
    }
    return 0;
}
