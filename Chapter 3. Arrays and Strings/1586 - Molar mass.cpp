#include<cstdio>
#include<cstring>

unsigned num(char c)
{
  switch (c)
  {
  	case 'C':return 1;
  	case 'H':return 2;
  	case 'O':return 3;
  	case 'N':return 4;
  }
  return 0;
}

unsigned t,i;
double saw[5]={0,12.01,1.008,16.00,14.01};
char s[100];

int main()
{
  scanf("%d",&t);
  for(i=0;i<t;i++)
  {
    scanf("%s",s);
    unsigned j,l=strlen(s),m=0,n=num(s[0]);
  	double sum=0;
  	
    for(j=1;j<=l;j++)
      if('0'<=s[j]&&s[j]<='9')
      {
        m*=10;
        m+=s[j]-'0';
   	  }
	  else
	  {
	    if(m==0)
	      m=1;
		sum+=saw[n]*m;
	    n=num(s[j]);
	    m=0;
      }
	printf("%.3lf\n",sum);
  }
  return 0;
}

