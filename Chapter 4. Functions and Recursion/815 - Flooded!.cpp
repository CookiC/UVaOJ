#include<cstdio>
#define area 100

unsigned T,m,n,i,j,vol,fv,flonum;
int reg[30][30],minhei,nexhei;
double hei,per;

unsigned FillVol(int hei)
{
  if(hei==0x7FFFFFFF)
    return 0x7FFFFFF;
  unsigned i,j,vol=0;
  for(i=0;i<m;++i)
    for(j=0;j<n;++j)
      if(reg[i][j]<hei)
      	vol+=(hei-reg[i][j])*area;
  return vol;
}

void Fill(int hei)
{
  unsigned i,j;
  for(i=0;i<m;++i)
    for(j=0;j<n;++j)
      if(reg[i][j]<hei)
        reg[i][j]=hei;
}

int main()
{
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);

  for(T=1;scanf("%u%u",&m,&n)==2&&m;++T)
  {
  	for(i=0;i<m;++i)
  	  for(j=0;j<n;++j)
  	    scanf("%d",&reg[i][j]);
  	scanf("%u",&vol);

  	do
  	{
  	  minhei=nexhei=0x7FFFFFFF;
  	  for(i=0;i<m;++i)
  	    for(j=0;j<n;++j)
  	      if(minhei>reg[i][j])
  	      {
  	      	nexhei=minhei;
  	        minhei=reg[i][j];
  	      }
  	      else if(nexhei>reg[i][j]&&reg[i][j]>minhei)
  	        nexhei=reg[i][j];
	  
	  fv=FillVol(nexhei);
  	  if(fv<vol)
  	  {
  	  	vol-=fv;
  	  	Fill(nexhei);
	  }
  	  else
  	    break;
    }while(true);
    
    flonum=0;
    for(i=0;i<m;++i)
      for(j=0;j<n;++j)
        if(reg[i][j]<nexhei)
          ++flonum;
    hei=(double)vol/(flonum*area)+minhei;
    per=(double)flonum/(n*m)*100;
  	printf("Region %u\n",T);
  	printf("Water level is %.2lf meters.\n",hei);
    printf("%.2lf percent of the region is under water.\n\n",per);
  }  
  return 0;
}

