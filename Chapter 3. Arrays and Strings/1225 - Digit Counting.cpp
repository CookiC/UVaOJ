#include<cstdio>
#include<cstring>

unsigned t,i,j,k,n,l,a[10];
char s[10];

int main()
{
  scanf("%u",&t);
  for(i=0;i<t;i++)
  {
  	memset(a,0,sizeof(a));
  	scanf("%u",&n);
  	
	for(j=1;j<=n;j++)
  	{
  	  sprintf(s,"%u",j);
  	  l=strlen(s);
  	  for(k=0;k<l;k++)
  	    ++a[s[k]-'0'];
    }
    
	for(j=0;j<9;j++)
	  printf("%u ",a[j]);
	printf("%u\n",a[9]);
  }
  return 0;
}

