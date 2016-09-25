#include<cstdio>

char puz[5][5],que;
unsigned i,j,t;
int x,y;
bool solve;

bool Mov(int h,int l)
{
  if(0<=x+h&&x+h<5&&0<=y+l&&y+l<5)
  {
    puz[x][y]=puz[x+h][y+l];
    x=x+h;
    y=y+l;
  	puz[x][y]=' ';
    return true;
  }
  return false;
}

bool CmpMov(char c)
{
  switch (c)
  {
  	case 'A':return Mov(-1,0);
  	case 'B':return Mov(1,0);
  	case 'R':return Mov(0,1);
  	case 'L':return Mov(0,-1);
  }
  return true;
}

int main()
{
  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);
  
  scanf("%c",&puz[0][0]);
  for(t=1;puz[0][0]!='Z';++t)
  {
    for(i=0;i<5;++i)
    {
      for(j=0;j<5;++j)
      {
        if(!(i==0&&j==0))
          scanf("%c",&puz[i][j]);
        if(puz[i][j]==' ')
        {
          x=i;
          y=j;
		}
      }
      getchar();
    }
    
	solve=true;
    do
    {
      scanf("%c",&que);
      if(!CmpMov(que)&&solve)
	    solve=false;
	}while(que!='0');

    if(t>1)
      printf("\n");
    printf("Puzzle #%u:\n",t);
    if(solve)
      for(i=0;i<5;++i)
      {
        for(j=0;j<4;++j)
      	  printf("%c ",puz[i][j]);
        printf("%c\n",puz[i][4]);
      }
    else
      printf("This puzzle has no final configuration.\n");
    
	getchar();
    scanf("%c",&puz[0][0]);
  }
  return 0;
}

