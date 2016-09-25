#include<cstdio>
#include<cstring>
#define maxn 1000

unsigned t,i,j,k,l;
char s[maxn];
bool b;

int main()
{
  //freopen("test.in","r",stdin);
  //freopen("test.out","w",stdout);
  
  scanf("%u",&t);
  for(i=0;i<t;i++)
  {
  	b=false;
  	scanf("%s",s);
  	//printf("%s",s);
  	l=strlen(s);
  	
  	for(j=1;j<=l&&!b;j++)
  	  if(l%j==0)                 
  	  {
  	  	b=true;
	    for(k=j;k<l;k++)
	      if(s[k]!=s[k%j])
	      {
	      	b=false;
	      	break;
		  }
      }
    
    printf("%u\n",j-1);
    if(i<t-1)
      printf("\n");
  }
  return 0;
}

