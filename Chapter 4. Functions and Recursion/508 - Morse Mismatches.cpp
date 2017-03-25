#include<cstdio>
#include<cctype>
#include<cstring>
#include<cstdlib>
#include<algorithm>

char wor[110][20],mwor[110][90],mcha[100][10],mor[100],c;
unsigned i,j,n,l,maxd,k,cou,dif;

int main()
{
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);
  
  while(scanf("%c",&c)==1&&c!='*')
  	if(isdigit(c)||isalpha(c))
  	  scanf("%s",mcha[c]);
/*
  for(i=0;i<91;++i)
    if(strlen(mcha[i])!=0)
      printf("%c:%s\n",i,mcha[i]);
*/
  for(i=0;scanf("%s",wor[i])==1&&wor[i][0]!='*';++i)
  {
  	l=strlen(wor[i]);
  	for(j=0;j<l;++j)
  	  strcat(mwor[i],mcha[wor[i][j]]);
//  	printf("%10s:%s\n",wor[i],mwor[i]);
  }
  n=i;
  
  while(scanf("%s",mor)&&mor[0]!='*')
  {
  	cou=0;
  	k=0;
	maxd=0xFFFFFFFF;
    for(i=0;i<n;++i)
      if(strncmp(mor,mwor[i],std::min(strlen(mor),strlen(mwor[i])))==0)
	  {
	  	dif=abs(strlen(mor)-strlen(mwor[i]));
		if(maxd>dif)
	    {
		  maxd=dif;
	      k=i;
	      cou=0;
	    };
	    if(maxd==dif)
	    {
	      ++cou;
	      if(strcmp(wor[k],wor[i])>0)
	        k=i;
	    }
      }
    
	printf("%s",wor[k]);
    if(maxd!=0)
      printf("?");
	else if(cou>1)
      printf("!");
    printf("\n");
  }
  return 0;
}

