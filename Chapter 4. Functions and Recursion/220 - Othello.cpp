#include<cstdio>
#include<cstring>

char com,c;
short board[9][9],cur;
unsigned T,i,j,x,y;
bool leg[9][9];

void markl(int x,int y,int h,int l)
{
  int i,j;
  for(i=x+h,j=y+l;0<i&&i<9&&0<j&&j<9&&board[i][j]==-cur;i=i+h,j=j+l);
  if((i-x)*(i-x)+(j-y)*(j-y)>2&&!board[i][j])
    leg[i][j]=1;
}

void update()
{
  unsigned i,j,k;
  memset(leg,0,sizeof(leg));
  for(i=1;i<9;++i)
    for(j=1;j<9;++j)
      if(board[i][j]==cur)
      {
      	markl(i,j,1,0);
      	markl(i,j,-1,0);
      	markl(i,j,0,1);
      	markl(i,j,0,-1);
      	markl(i,j,1,1);
      	markl(i,j,1,-1);
      	markl(i,j,-1,1);
      	markl(i,j,-1,-1);
	  }
  /*
  for(i=1;i<9;++i)
  {
    for(j=1;j<9;++j)
      printf("%u",leg[i][j]);
    printf("\n");
  }
  printf("\n");
  */
}

void list()
{
  unsigned i,j;
  bool first;
  first=1;
  for(i=1;i<9;++i)
    for(j=1;j<9;++j)
      if(leg[i][j])
      {
        if(!first)
          printf(" ");
        first=0;
        printf("(%u,%u)",i,j);
      }
  if(first)
    printf("No legal move.");
  printf("\n");
}

void markb(int x,int y,int h,int l)
{
  unsigned i,j;
  for(i=x+h,j=y+l;0<i&&i<9&&0<j&&j<9&&board[i][j]==-cur;i=i+h,j=j+l);
  if(board[i][j]==cur)
    for(i=x+h,j=y+l;0<i&&i<9&&0<j&&j<9&&board[i][j]==-cur;i=i+h,j=j+l)
	  board[i][j]=cur;
}

void move(unsigned x,unsigned y)
{
  unsigned i,j,b,w;
  if(!leg[x][y])
  	cur=-cur;
  board[x][y]=cur;
  markb(x,y,1,0);
  markb(x,y,-1,0);
  markb(x,y,0,1);
  markb(x,y,0,-1);
  markb(x,y,1,1);
  markb(x,y,-1,1);
  markb(x,y,1,-1);
  markb(x,y,-1,-1);
  cur=-cur;
  update();
  b=w=0;
  for(i=1;i<9;++i)
    for(j=1;j<9;++j)
    {
      if(board[i][j]==1)
        ++w;
      if(board[i][j]==-1)
        ++b;
    }
  printf("Black -%3u White -%3u\n",b,w);
}

int main()
{
  //freopen("test.in","r",stdin);
  //freopen("test.out","w",stdout);

  scanf("%u",&T);
  while(T--)
  {
  	for(i=1;i<9;++i)
  	{
  	  scanf("\n");
  	  for(j=1;j<9;++j)
  	  {
  	    scanf("%c",&c);
  	    switch(c)
  	    {
  	      case '-':board[i][j]=0;break;
  	      case 'W':board[i][j]=1;break;
  	      case 'B':board[i][j]=-1;
		}
      }
    }
    scanf("\n%c\n",&c);
    if(c=='W')
      cur=1;
    else
      cur=-1;
      
    for(update();scanf("%c",&com)==1&&com!='Q';scanf("\n"))
    {
      if(com=='M')
      {
      	scanf("%u",&y);
      	x=y/10;
      	y%=10;
      	move(x,y);
	  }
      if(com=='L')
        list();
	}
	
    for(i=1;i<9;++i)
    {
      for(j=1;j<9;++j)
      	switch(board[i][j])
  	    {
  	      case 0:printf("-");break;
  	      case 1:printf("W");break;
  	      case -1:printf("B");
		}
      printf("\n");
    }
    if(T)
      printf("\n");
  }  
  return 0;
}

