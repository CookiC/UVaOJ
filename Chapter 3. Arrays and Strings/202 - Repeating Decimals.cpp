#include<cstdio>
#include<cstring>

unsigned i,n,p,app[3010],s[51],b,e,t;

int main()
{
  //freopen("test.in","r",stdin);
  //freopen("test.out","w",stdout);
  
  while(scanf("%u%u",&n,&p)==2)
  {
  	printf("%u/%u = %u.",n,p,n/p);
  	
	memset(app,0,sizeof(app));
  	i=1;
	do
  	{
  	  n%=p;
  	  if(!app[n])
  	    app[n]=i;
  	  else
  	  {
	    b=app[n];
	    e=i-1;
	    break;
      }
  	  n*=10;
	  if(i<=50)
  	    s[i]=n/p;
  	  ++i;
    }while(true);
    
    for(i=1;i<=e&&i<=50;++i)
    {
      if(i==b)
        printf("(");
      printf("%u",s[i]);
	}
	if(e<=50)
	  printf(")\n");
	else
	  printf("...)\n");
	printf("   %u = number of digits in repeating cycle\n\n",e-b+1);
  }
  return 0;
}

