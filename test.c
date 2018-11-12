#include<stdio.h>
int main()
{
   char s[100];
   scanf("%s",s);
   int l=strlen(s);
   int d=0,r=0,i;
   for(i=0;i<l;i++)
   {
       d+=s[i]-48;
       r=d%15;
       d=r*10;
   }
   if(d==0)printf("YES");
}
