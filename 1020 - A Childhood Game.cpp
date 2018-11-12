#include<bits/stdc++.h>
using namespace std;
int main()
{
//    ios_base::sync_with_stdio(0);cin.tie(0);
    int t,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        int a;
        char s[10];
        scanf("%d %s",&a,s);

        printf("Case %d: ",cs++);
        if(s[0]=='A')
        {
            if(a%3==1)
                printf("Bob\n");
            else
                printf("Alice\n");
        }
        else if(s[0]=='B')
        {
            if(a%3==0)
                printf("Alice\n");
            else
                printf("Bob\n");

        }
    }
}
