#include<cstdio>
#include<cstring>

unsigned d,s,b,i,j,k,T,cou,ans;
char strdis[7][6402],c;
bool par,pass;

bool valid(unsigned y)
{
  unsigned x,i,cou;
  bool res;
  cou=res=0;
  for(i=0;i<d;++i)
    if(strdis[i][y]=='x')
    {
      x=i;
      ++cou;
    }
    else
      res^=strdis[i][j]-'0';
  if(cou==0)
    return !res^par;
  if(cou==1)
  {
  	strdis[x][y]=res^par+'0';
  	return 1;
  }
  return 0;
}

int main()
{
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);

  for(T=1;scanf("%u%u%u",&d,&s,&b)==3&&d;++T)
  {
	do{scanf("%c",&c);}while(c!='E'&&c!='O');
	if(c=='E')
	  par=0;
	else
	  par=1;
	for(i=0;i<d;++i)
	  scanf("%s",strdis[i]);
	/*
    printf("%u %u %u\n%c\n",d,s,b,c);
	for(i=0;i<d;++i)
	  printf("%s\n",strdis[i]);
    */
	pass=1;
	for(j=0;j<b*s;++j)
	  if(!valid(j))
	  {
	  	pass=0;
	  	break;
	  }
	/*
	printf("\n");
	for(i=0;i<d;++i)
	  printf("%s\n",strdis[i]);
    */
	if(pass)
	{
	  printf("Disk set %u is valid, contents are: ",T);
	  ans=cou=0;
	  for(j=0;j<b;++j)
		for(i=0;i<d;++i)
		  if(j%d!=i)
	        for(k=0;k<s;++k)
	        {
	          ans<<=1;
			  ans+=strdis[i][j*s+k]-'0';
			  ++cou;
			  if(cou%4==0)
			  {
			    printf("%X",ans);
			    ans=0;
		      }
			}
	  if(cou%4!=0)
	  {
	    ans<<=4-cou%4;
	    printf("%X",ans);
      }
      printf("\n");
	}
	else
	  printf("Disk set %u is invalid.\n",T);
  }
  return 0;
}

