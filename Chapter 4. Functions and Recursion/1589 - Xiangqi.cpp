#include<cstdio>
#include<cstring>
#include<cctype>

bool board[12][11],pos[12][11];
unsigned n,x,y,i,j,h[8],l[8];
char c[8];

void cha(unsigned h,unsigned l)
{
  unsigned i;
  i=0;
  do{++i;board[h+i][l]=1;}while(!pos[h+i][l]);
  i=0;
  do{++i;board[h][l+i]=1;}while(!pos[h][l+i]);
  i=0;
  do{++i;board[h-i][l]=1;}while(!pos[h-i][l]);
  i=0;
  do{++i;board[h][l-i]=1;}while(!pos[h][l-i]);
}

void hor(unsigned h,unsigned l)
{
  if(!pos[h+1][l])
    board[h+2][l+1]=board[h+2][l-1]=1;
  if(!pos[h-1][l])
    board[h-2][l+1]=board[h-2][l-1]=1;
  if(!pos[h][l+1])
    board[h+1][l+2]=board[h-1][l+2]=1;
  if(!pos[h][l-1])
    board[h+1][l-2]=board[h-1][l-2]=1;
}

void can(unsigned h,unsigned l)
{
  unsigned i;
  for(i=1;!pos[h+i][l];++i);
  if(h+i<11)
    do{++i;board[h+i][l]=1;}while(!pos[h+i][l]);
  
  for(i=1;!pos[h][l+i];++i);
  if(l+i<10)
    do{++i;board[h][l+i]=1;}while(!pos[h][l+i]);
  for(i=1;!pos[h-i][l];++i);
  if(h-i>0)
    do{++i;board[h-i][l]=1;}while(!pos[h-i][l]);
  
  for(i=1;!pos[h][l-i];++i);
  if(l-i>0)
    do{++i;board[h][l-i]=1;}while(!pos[h][l-i]);
}

void put(char c,unsigned h,unsigned l)
{
  switch (c)
  {
  	case 'G':
  	case 'R':cha(h,l);break;
  	case 'H':hor(h,l);break;
  	case 'C':can(h,l);
  }
}

int main()
{
  //freopen("test.in","r",stdin);
  //freopen("test.out","w",stdout);
  
  while(scanf("%u%u%u",&n,&x,&y)==3&&n!=0)
  {
  	memset(board,0,sizeof(board));
  	memset(pos,0,sizeof(pos));
  	for(i=0;i<12;++i)
  	  board[i][0]=board[i][10]=pos[i][0]=pos[i][10]=1;
    for(i=0;i<11;++i)
      board[0][i]=board[11][i]=pos[0][i]=pos[11][i]=1;
	for(i=1;i<=4;++i)
	  board[i][3]=board[i][7]=board[4][3+i]=1;
	
	for(i=0;i<n;++i)
	{
	  do{c[i]=getchar();}while(!isupper(c[i]));
	  scanf("%u%u",&h[i],&l[i]);
	  pos[h[i]][l[i]]=1;
//	  printf("%c %u %u\n",c[i],h[i],l[i]);
    }
    
    for(i=0;i<n;++i)
	  put(c[i],h[i],l[i]);
	
	if(board[x+1][y]&&board[x-1][y]&&board[x][y+1]&&board[x][y-1])
	  printf("YES\n");
	else
	  printf("NO\n");
	
	/*
	for(i=1;i<11;++i)
	{
	  for(j=1;j<10;++j)
	    printf("%u",pos[i][j]);
	  printf("\n");
    }
    printf("\n");
    
	for(i=1;i<11;++i)
	{
	  for(j=1;j<10;++j)
	    printf("%u",board[i][j]);
	  printf("\n");
    }
    */
  }
  return 0;
}

