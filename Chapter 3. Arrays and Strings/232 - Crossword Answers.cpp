#include<cstdio>
#include<cstring>

unsigned r,c,t,i,j,h,num[12][12],n;
char cro[12][12];
bool used[12][12];

int main()
{
  //freopen("test.in","r",stdin);
  //freopen("test.out","w",stdout);
  
  t=0;
  while(scanf("%u%u",&r,&c)==2&&r)
  {	  	
  	if(t)
  	  printf("\n");
  	++t;
	printf("puzzle #%u:\n",t);

    for(i=1;i<=r;++i)
      scanf("%s",&cro[i][1]);
  	for(i=0;i<=r+1;++i)
  	  for(j=0;j<=c+1;++j)
  	    if(i==0||j==0||i==r+1||j==c+1)
          cro[i][j]='*';    
    n=0;
  	memset(num,0,sizeof(num));
    for(i=1;i<=r;++i)
      for(j=1;j<=c;++j)
        if(cro[i][j]!='*'&&(cro[i-1][j]=='*'||cro[i][j-1]=='*'))
          num[i][j]=++n;
    /*
    for(i=1;i<=r;++i)
    {
      for(j=1;j<=c;++j)
        printf("%-3u",num[i][j]);
      printf("\n");
    }
    */
    
    memset(used,0,sizeof(used));
    printf("Across\n");
    for(i=1;i<=r;++i)
	  for(j=1;j<=c;++j)
	    if(num[i][j]&&!used[i][j])
	    {
	      printf("%3u.",num[i][j]);
	      do
		  {
		  	used[i][j]=true;
		    printf("%c",cro[i][j++]);
		  }while(cro[i][j]!='*');
		  printf("\n");
		}
	
	memset(used,0,sizeof(used));
    printf("Down\n");
    for(i=1;i<=r;++i)
	  for(j=1;j<=c;++j)
	    if(num[i][j]&&!used[i][j])
	    {
	      h=i;
	      printf("%3u.",num[h][j]);
	      do
		  {
		  	used[h][j]=true;
		    printf("%c",cro[h++][j]);
		  }while(cro[h][j]!='*');
		  printf("\n");
		}
  }
  return 0;
}

