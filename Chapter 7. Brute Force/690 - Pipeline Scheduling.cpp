#include<cstdio>
#include<cstring>
#include<ctime>
#include<cstdlib>

unsigned n,clk,db;
unsigned table[5],state[5];

void DFS(unsigned begin,unsigned deep,unsigned ust[5]){
	
/*	printf("deep:%u\n",deep);
	for(i=0;i<5;++i){
	  for(j=32-1;j>=0;--j)
	    printf("%2u",ust[i]>>j&1);
	  printf("\n");
	}
	printf("\n\n");
	system("pause");*/
	if(deep>=10){
		if(clk>begin+n)
		  clk=begin+n;
		return;
	}
	if(clk<=begin+n+db*(10-deep-1))
		return;

	unsigned i,j;
	unsigned vst[5];
	for(i=db;i<=n;++i){
		for(j=0;j<5;++j)
		  if(ust[j]<<i&table[j])
		    break;
		if(j<5)
		  continue;
		else
		  for(j=0;j<5;++j)
		    vst[j]=ust[j]<<i|table[j];
		DFS(i+begin,deep+1,vst);
	}
}

int main(){
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);
  
	unsigned i,j;
  while(scanf("%u",&n)!=EOF&&n){
  	memset(table,0,sizeof(table));
    clk=0xFFFFFFFF;
    
		for(i=0;i<5;++i)
      for(j=0;j<n;++j){
  	    char c;
  	    do{
          c=getchar();
        }while(c!='X'&&c!='.');
        if(c=='X')
          table[i]|=1<<n-j-1;
      }
    
    memcpy(state,table,sizeof(state));
    i=0;
    do{
    	++i;
      for(j=0;j<5;++j)
		    if(state[j]<<i&table[j])
		      break;
		}while(j<5);
		db=i;
    DFS(0,1,state);
		printf("%u\n",clk);
//		printf("cnt=%u\n",cnt);
/*    for(i=0;i<5;++i){
      for(j=0;j<n;++j)
        printf("%3u",table[i][j]);
      printf("\n");
    }*/
  	

  }
//	double ck=(double)clock()/CLOCKS_PER_SEC; 
//  printf("Time used=%.2fs=%.2fmin=%.2fh\n",ck,ck/60,ck/360);
  return 0;
}

