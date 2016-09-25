#include<cstdio>
#include<cstring>

unsigned i,j,m,n,cou[1001][5],maxc,maxj,l;
int t;
char s[1010],rea[]=" ACGT";

unsigned ass(char c)
{
  switch (c)
  {
  	case 'A':return 1;
  	case 'C':return 2;
  	case 'G':return 3;
  	case 'T':return 4;
  	default:return 0;
  }
}

int main()
{
  //freopen("test.in","r",stdin);
  //freopen("test.out","w",stdout);

  scanf("%d",&t);
  while(t--)
  {
  	memset(cou,0,sizeof(cou));
  	
    scanf("%u%u",&m,&n);
    for(i=0;i<m;++i)
    {
      scanf("%s",s);
      for(j=0;j<n;++j)
        ++cou[j][ass(s[j])];
    }
    
    /*
    for(j=0;j<=4;++j)
    {
      for(i=0;i<n;++i)
        printf("%-3u",cou[i][j]);
      printf("\n");
    }
    */
    
    l=0;
    for(i=0;i<n;++i)
    {
      maxc=1;
      maxj=1;
      for(j=1;j<=4;++j)
      {
      	l+=cou[i][j];
        if(maxc<cou[i][j])
        {
          maxc=cou[i][j];
          maxj=j;
		}
      }
      l-=cou[i][maxj];
	  printf("%c",rea[maxj]);
	}
	printf("\n%u\n",l);
  }
  return 0;
}

