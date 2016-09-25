#include<cstdio>
#include<cstring>

unsigned e[12],m[12],x,y,i,n;

void inc(unsigned l)
{
  unsigned i;
  for(i=0;e[i];++i)
    if(e[i]==l)
    {
      ++m[i];
      return;
	}
  e[i]=l;
  ++m[i];
  ++n;
}

int main()
{
  //freopen("test.in","r",stdin);
  //freopen("test.out","w",stdout);
  
  do
  {
  	memset(m,0,sizeof(m));
  	memset(e,0,sizeof(e));
  	n=0;
  	
    for(i=0;i<6&&scanf("%u%u",&x,&y)==2;++i)
	  if(x==y)
	    inc(x);
	  else
	  {
	  	inc(x);
	  	inc(y);
	  }
    
    if(i<6)
      break;
    else
	{
      if(n==1&&m[0]==6
	  ||n==2&&(m[0]==4&&m[1]==6||m[0]==6&&m[1]==4)
	  ||n==3&&m[0]==4&&m[1]==4&&m[2]==4)
	    printf("POSSIBLE\n");
	  else
	    printf("IMPOSSIBLE\n");
	}
  }while(true);
  return 0;
}

