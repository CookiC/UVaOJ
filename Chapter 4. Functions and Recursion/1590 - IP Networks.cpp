#include<cstdio>

unsigned m,ip[1010],a,b,c,d,j,i,mask,seg=0x000000FF;

int main()
{
  //freopen("test.in","r",stdin);
  //freopen("test.out","w",stdout);
  
  while(scanf("%u",&m)==1)
  {
  	for(i=0;i<m;++i)
  	{
  	  scanf("%u.%u.%u.%u",&a,&b,&c,&d);
  	  ip[i]=a<<24|b<<16|c<<8|d;
	}
	
	i=0;
	mask=~0;
	j=0;
	while(j<m-1)
	{
	  if(i++)
	    mask<<=1;
	  for(j=0;j<m-1&&(ip[j]&mask)==(ip[j+1]&mask);++j);
    }
    
	i=ip[0]&mask;
	printf("%u.%u.%u.%u\n%u.%u.%u.%u\n",
	i>>24&seg,i>>16&seg,i>>8&seg,i&seg,
	mask>>24&seg,mask>>16&seg,mask>>8&seg,mask&seg);
  }
  return 0;
}

