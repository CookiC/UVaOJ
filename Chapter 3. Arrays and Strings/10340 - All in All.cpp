#include<cstdio>
#include<cstring>
#define maxn 1000010

unsigned i,j,ls,lt;
char s[maxn],t[maxn];

int main()
{
  //freopen("test.in","r",stdin);
  //freopen("test.out","w",stdout);
  
  while(scanf("%s%s",s,t)!=EOF)
  {
  	ls=strlen(s);
  	lt=strlen(t);
  	
  	for(i=0,j=0;i<lt&&j<ls;++i)
  	  if(t[i]==s[j])
  	    ++j;
  	if(j==ls)
  	  printf("Yes\n");
    else
      printf("No\n");
  }
  return 0;
}

