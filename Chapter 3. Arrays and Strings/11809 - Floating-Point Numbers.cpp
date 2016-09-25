#include<cstdio>
#include<cmath>
#include<cstring>

unsigned i,u,E,M,l;
double d,f;
char s[40];

int main()
{
  while(scanf("%s",s)==1)
  {
  	l=strlen(s);
  	for(i=0;i<l;++i)
  	  if(s[i]=='e')
  	  {
  	    s[i]=' ';
  	    break;
      }
    sscanf(s,"%lf%u",&d,&u);

    if(u==0&&d==0)
      break;
    E=log(log(d)/log(2)+u/log10(2)+2.1)/log(2);
    f=pow(10,log10(d)+u-(pow(2,E)-1)*log10(2));
    
	f*=2;
	for(i=0;f+0.1>=1&&f>0;++i)
      f=(f-1)*2;
	M=i-1;
	printf("%u %u\n",M,E);
  }
  return 0;
}

