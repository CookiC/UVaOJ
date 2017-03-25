#include<cstdio>
#include<cctype>
#include<cstring>

unsigned n,m,i,j,t,T,row,col,d,cou[9];
bool H[10][10],V[10][10],b;
char c;

bool issqu(unsigned x,unsigned y,unsigned d)
{
  unsigned i;
  for(i=0;i<d&&V[x+i][y]&&H[x][y+i]&&V[x+i][y+d]&&H[x+d][y+i];++i);
  if(i==d)
    return true;
  return false;
}

int main()
{
  //freopen("test.in","r",stdin);
  //freopen("test.out","w",stdout);
  
  T=0;
  while(scanf("%u%u",&n,&m)==2)
  {
  	if(T++)
      printf("\n**********************************\n\n");
	printf("Problem #%u\n\n",T);
  	memset(cou,0,sizeof(cou));
  	memset(H,0,sizeof(H));
  	memset(V,0,sizeof(V));
  	
  	for(i=0;i<m;++i)
  	{
  	  do{scanf("%c",&c);}while(!isupper(c));
  	  scanf("%u%u",&row,&col);
  	  if(c=='H')
  	    H[row][col]=1;
  	  if(c=='V')
  	  {
  	  	t=row;
  	  	row=col;
  	  	col=t;
  	  	V[row][col]=1;
	  }
	}
	/*
	for(i=1;i<=n;++i)
	{
	  for(j=1;j<=n;++j)
	    printf("%u",H[i][j]);
	  printf("\n");
    }
    printf("\n");
	for(i=1;i<=n;++i)
	{
	  for(j=1;j<=n;++j)
	    printf("%u",V[i][j]);
	  printf("\n");
    }
    */
	for(d=1;d<n;++d)
	  for(i=1;i<=n-d;++i)
	    for(j=1;j<=n-d;++j)
	      if(issqu(i,j,d))
	      	++cou[d];

	b=1;
	for(d=1;d<n;++d)
	  if(cou[d])
	  {
	  	b=0;
	    printf("%u square (s) of size %u\n",cou[d],d);
      }
    if(b)
      printf("No completed squares can be found.\n");
  };
  return 0;
}

