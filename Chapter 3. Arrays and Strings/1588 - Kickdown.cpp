#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 110

char s[maxn],c[maxn];
bool a[maxn],b[maxn];
unsigned i,j,ls,lc,sum,la,lb;

int main()
{
  //freopen("test.in","r",stdin);
  //freopen("test.out","w",stdout);
  
  while(scanf("%s%s",s,c)==2)
  {
  	memset(a,0,sizeof(a));
  	memset(b,0,sizeof(b));
  	
  	ls=strlen(s);
	lc=strlen(c);
	for(i=0;i<ls;++i)
  	  if(s[i]=='2')
	    a[i]=1;
  	for(i=0;i<lc;++i)
  	  if(c[i]=='2')
  	    b[i]=1;
  	
    sum=1;
  	for(i=0;sum;++i)
  	{
  	  sum=0;
  	  for(j=i;j<ls&&j<lc+i;++j)
  	    sum+=a[j]&b[j-i];
	}
	la=std::max(ls,lc+i-1);
	
	sum=1;
  	for(i=0;sum;++i)
  	{
  	  sum=0;
  	  for(j=i;j<lc&&j<ls+i;++j)
  	    sum+=b[j]&a[j-i];
	}
	lb=std::max(lc,ls+i-1);
	
	printf("%u\n",std::min(la,lb));
  };
  return 0;
}

