#include<cstdio>
#include<cstring>

int t,i,j;
char s[100];

int main()
{
  scanf("%d",&t);
  for(i=0;i<t;i++)
  {
  	scanf("%s",s);
  	int res=0,l=strlen(s),k=0;
  	for(j=0;j<l;j++)
  	  if(s[j]=='O')
  	    res+=++k;
  	  else
  	  	k=0;
  	printf("%d\n",res);
  }
  return 0;
}

