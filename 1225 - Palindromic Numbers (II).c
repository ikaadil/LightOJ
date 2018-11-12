#include<stdio.h>
#include<string.h>
int main()
{
    int t,i,l,j,flag;
    scanf("%d",&t);
    char s[11];
    for(i=1; i<=t; i++)
    {
        scanf("%s",s);
        l=strlen(s);
        flag=0;
        for(j=0; j<l/2; j++)
        {
            if(s[j]!=s[l-j-1])
            {
                flag=1;
                break;
            }
        }
        if(flag)
            printf("Case %d: No\n",i);
        else
            printf("Case %d: Yes\n",i);
    }
    return 0;
}
